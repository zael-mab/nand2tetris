/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:08:16 by zael-mab          #+#    #+#             */
/*   Updated: 2021/11/19 09:08:17 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vm.h"

int     set_segment(char *segment)
{
    if (ft_strcmp(segment, "local") == 0)
        return (LCL);
    else if (ft_strcmp(segment, "argument") == 0)
        return (ARG);
    else if (ft_strcmp(segment, "this") == 0)
        return (THIS);
    else if (ft_strcmp(segment, "that") == 0)
        return (THAT);
    else if (ft_strcmp(segment, "constant") == 0)
        return (CONST);
    else if (ft_strcmp(segment, "static") == 0)
        return (STATIC);
    else if (ft_strcmp(segment, "temp") == 0)
        return (TEMP);
    else if (ft_strcmp(segment, "pointer") == 0)
        return (PTR);
    else
        return (0);
}


int     set_op(char *op)
{
    if (ft_strcmp(op, "add") == 0)
        return (ADD);
    else if (ft_strcmp(op, "sub") == 0)
        return (SUB);
    else if (ft_strcmp(op, "neg") == 0)
        return (NEG);
    else if (ft_strcmp(op, "eq") == 0)
        return (EQ);
    else if (ft_strcmp(op, "gt") == 0)
        return (GT);
    else if (ft_strcmp(op, "lt") == 0)
        return (LT);
    else if (ft_strcmp(op, "and") == 0)
        return (AND);
    else if (ft_strcmp(op, "or") == 0)
        return (OR);
    else if (ft_strcmp(op, "not") == 0)
        return (NOT);
    else
        return (0);
}


int     check_and_set(char *line, t_vmdata *data)
{
    char **tab;

    tab = ft_strsplit(line, ' ');

    if ((tab[0][0] == '/' && tab[0][1] == '/' ) || ft_strlen(tab[0]) < 2)
        return (-1);
    else
    {

        data->op = set_op((tab[0]));
        if (data->op > 0)
            data->arith = 1;

        if (!data->op)
        {
            if (ft_strcmp(tab[0], "push") == 0)
                data->op = PUSH;
            if (ft_strcmp(tab[0], "pop") == 0)
                data->op = POP;
            
            if (data->op == 0)
            {
                ft_printf ("syntax error!\n");
                return(0);
            }
            if ((data->op & POP) || (data->op & PUSH))
            {
                data->segment = set_segment(tab[1]);
                if (data->segment == 0)
                {
                    ft_printf ("segment problem at line [%s]\n", line);
                    return (0);
                }
            }
            data->index = ft_atoi(tab[2]);
        }
        
        if (data->op == 0)
        {
            if (ft_strlen(line) > 1)
                ft_printf ("|+++++[%s] |op problem at line|\n", line);
            return (0);
        }

    }
    ft_memdel((void **)tab);
    return (1);
}
