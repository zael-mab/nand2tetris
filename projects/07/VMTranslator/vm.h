/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 07:08:06 by zael-mab          #+#    #+#             */
/*   Updated: 2021/11/19 07:08:08 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft/libft.h"
# include <fcntl.h>

# define    PUSH    1
# define    POP     2
# define    ADD     4
# define    SUB     16
# define    NEG     32
# define    EQ      64
# define    GT      128
# define    LT      256
# define    AND     512
# define    OR      1024
# define    NOT     2048

# define    LCL     1
# define    ARG     2
# define    THIS    4
# define    THAT    16
# define    CONST   32
# define    STATIC  64
# define    PTR     128
# define    TEMP    256





typedef struct      s_head
{
    int             h_size;
    struct s_node   *first;
}                   t_head;

typedef struct      s_node
{
    int             op;
    int             segment;
    int             index;
    char            *command;
    struct s_node  *next;
}                   t_node;

typedef struct      s_vmdata
{
    int             op;
    int             segment;
    int             index;
    char            *line;
}                   t_vmdata;


void        add_last(t_head *head, t_vmdata *data);
void        printf_list(t_head head);


#endif