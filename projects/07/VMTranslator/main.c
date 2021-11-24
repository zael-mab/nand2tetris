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

// add ( x + y) int
// sub (x - y)  int
// neg (- y)    int
// eq  (x == 0) bool
// gt  (x > y)  bool
// lt  (x < y)  bool
// and (x & y)  bool
// or  (x || y) bool
// not (not x)  bool


int        f_name(t_head *vmcode, char *name)
{
    int name_len;
    int jumper;

    name_len = ft_strlen(name);
    jumper = -1;
    while (name[++jumper])
    {

        if (name[jumper] == '.' && !ft_strcmp(name + jumper + 1, "vm"))
            break ;
    }
    if (jumper == name_len)
        return (0);
    else
    {
        vmcode->file_name = (ft_strncpy(ft_strnew(jumper), name, jumper));
        return(1);
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

        if (!f_name(vmcode, av[1]))
        {
            ft_printf ("Error file extention...!\n");
            return (0);
        }

        ft_printf ("\t\tfile_name=[%s]\n",vmcode->file_name);

        int i;
        fd = open(av[1], O_RDONLY);
        while (get_next_line(fd, &data->line) > 0)
        {
            char *tmp = ft_strtrim(data->line);
            free (data->line);
            data->line = tmp;
            if (ft_strlen (data->line))
            {
                i = check_and_set (data->line, data);
                if (i > 0)
                    add_last(vmcode, data);
                if (i == 0)
                {
                    ft_printf ("Unknown command in the line [%s] [%d] \n", data->line, i);
                    free(data->line);
                    return (0);
                }
                if (i == -1)
                    ft_printf ("%s.\n", data->line);
            }
            free(data->line);
            ft_bzero(data, sizeof(t_vmdata));
        }
        printf_list(*vmcode);
        
        t_memory_segments *segments;
        segments = ft_memalloc(sizeof(t_memory_segments));
        ft_bzero(segments, sizeof(t_memory_segments));
        trans(vmcode, segments);
        
    }
    else
    {
        ft_printf ("wrong arg!!!\n");
        return (0);
    }
}