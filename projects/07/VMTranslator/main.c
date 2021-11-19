/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 07:06:39 by zael-mab          #+#    #+#             */
/*   Updated: 2021/11/19 07:06:41 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdio.h>

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
    else
        return (0);
    // if (ft_strcmp(segment, "p") == 0)
    //     return (P);
}


int     set_op(char *op)
{
    if (ft_strcmp(op, "push") == 0)
        return (PUSH);
    else if (ft_strcmp(op, "pop") == 0)
        return (POP);
    else if (ft_strcmp(op, "add") == 0)
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
        data->op = set_op(tab[0]);
        if (data->op == 0)
        {
            ft_printf ("op problem at line [%s]\n", line);
            return (0);
        }
        data->segment = set_segment(tab[1]);
        if (data->segment == 0)
        {
            ft_printf ("segment problem at line [%s]\n", line);
            return (0);
        }

        data->index = ft_atoi(tab[2]);
        // if (!(ft_strcmp(tab[0], "push")) || !(ft_strcmp(tab[0], "pop")))
        // {
        //     if (!(ft_strcmp(tab[0], "push")))
        //         data->op = PUSH;
        //     else
        //         data->op = POP;

        //     // data->segment = set_segment(tab[1]);
        //     data->segment = (tab[1]);
            
        //     // free the table 
        //     ft_memdel((void **)tab);
        //     if (!tab[0])
        //         ft_putchar ('$');
        //     return (1);
        // }
        return (1);
    }
}


int main (int ac, char **av)
{
    if (ac == 2)
    {

        int fd;
        t_head *vmcode;
        t_vmdata *data;

        vmcode = ft_memalloc(sizeof (t_head));
        ft_bzero(vmcode , sizeof(t_head));

        data = ft_memalloc (sizeof (t_vmdata));
        ft_bzero(data, sizeof(t_vmdata));

        fd = open(av[1], O_RDONLY);
        char *line;
        line = NULL;
        int i;
        while (get_next_line(fd, &line) > 0)
        {
            i = check_and_set (line, data);
            if (i > 0)
            {
                ft_printf ("%s", data->index);
                // add_last(vmcode, data);
            }
            else if (i == 0)
            {
                ft_printf ("Unknown command in the line [%s] [%d] \n", line, i);
                free(line);
                return (0);
            }
            printf ("\t-------> \t_ %s\n", line);
            // add_last (vmcode, data);
            free(line);
        }
        // printf_list(*vmcode);
    }
    else
    {
        ft_printf ("wrong arg!!!\n");
        return (0);
    }
}