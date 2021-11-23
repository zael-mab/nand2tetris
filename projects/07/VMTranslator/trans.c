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
    // segments->sp_p = 256;
    // segments->local_p = 300;
    // segments->arg_p = 400;
    segments->t_his = 3;
    // segments->this_p = 3000;
    segments->that = 4;
    // segments->that_p = 3010;
    segments->tmp = 5;              // tmp < 12
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
                    print_code(*inst, segments, 0, 0);

                    // ft_printf ("//%s\n@%d\nD=A\n@%d\nA=M\nM=D\n@%d\nM=M+1\n",
                    //  inst->command, inst->index, segments->sp, segments->sp);
                    // segments->sp
                }

                // ///////
                if (inst->segment == ARG)
                    print_code(*inst, segments,segments->arg, 1);
                if (inst->segment == LCL)
                    print_code(*inst, segments,segments->local, 1);
                if (inst->segment == THIS)
                    print_code(*inst, segments,segments->t_his, 1);
                if (inst->segment == THAT)
                    print_code(*inst, segments,segments->that, 1);
                
                // 

                if (inst->segment == PTR)
                {
                    if (!inst->index)
                        print_code(*inst, segments, segments->t_his, 3);
                    else
                        print_code(*inst, segments, segments->that, 3);
                }
            }
            else if (inst->op == POP)
            {

                if (inst->segment == ARG)
                    print_code(*inst, segments, segments->arg, 2);
                if (inst->segment == LCL)
                    print_code(*inst, segments, segments->local, 2);
                if (inst->segment == THAT)
                    print_code(*inst, segments, segments->that, 2);
                if (inst->segment == THIS)
                    print_code(*inst, segments, segments->t_his, 2);

                // 
                if (inst->segment == PTR)
                {
                    if (!inst->index)
                        print_code(*inst, segments, segments->t_his, 4);
                    else
                        print_code(*inst, segments, segments->that, 4);
                }
            }
        }
        // else
        // {

        // }
        inst = inst->next;
    }

}