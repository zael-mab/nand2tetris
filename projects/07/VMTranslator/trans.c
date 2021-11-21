/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 06:04:21 by zael-mab          #+#    #+#             */
/*   Updated: 2021/11/21 06:04:24 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vm.h"

void    init_memory_segment(t_memory_segments *segments)
{
    segments->sp = 0;
    segments->local = 1;
    segments->arg = 2;
    segments->sp_p = 256;
    segments->local_p = 300;
    segments->arg_p = 400;
    segments->this = 3;
    segments->this_p = 3000;
    segments->that = 4;
    segments->that_p = 3010;
}

void    trans(t_head *head, t_memory_segments *segments)
{
    // constant
    t_node *inst;

    init_memory_segment(segments);
    inst = head->first;
    while (inst)
    {
        if (!inst->arith)
        {
            if (inst->op == PUSH)
            {
                if (inst->segment == CONST)
                {
                    ft_printf ("//%s\n@%d\nD=A\n@%d\nA=M\nM=D\n@%d\nM=M+1\n", inst->command, inst->index, segments->sp, segments->sp);
                    // segments->sp
                }
                if (inst->segment == ARG)
                {
                    ft_printf ("//%s\n@%d\nD=M\n@%d\nAM=M+D\nD=M\n@%d\nA=M\nM=D\n@%d\nM=M+1", inst->command, inst->index, segments->local, segments->sp, segments->sp);

                }
            }
            // if (inst->op == POP)
            // {

            // }
        }
        // else
        // {

        // }
        inst = inst->next;
    }

}