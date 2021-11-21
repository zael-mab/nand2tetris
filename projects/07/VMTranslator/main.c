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

//  d = *p
// @p
// A=M
// D=M 

// sp stored in RAM[0]
// Stack basr addr = 256
// push x y
// *sp = y
// sp++

// @y      // D=y
// D=A
// @sp      // *sp = D
// A=M
// M=D
// @sp      // sp++
// M=M+1

//  push constant i => *sp = ; sp++

// pop local i
// addr =  lcl + i; sp--; *addr = *sp
// push local i
// addr = lcl +i; *sp = *addr; sp++;

// push segment i
// pop segment i
// segment = {local , arg, this , that}


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

        int i;
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