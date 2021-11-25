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
    segments->t_his = 3;
    segments->that = 4; 
    segments->tmp = 5;              // tmp < 12
}

void    trans(t_head *head, t_memory_segments *segments)
{
    t_node *inst;

    init_memory_segment(segments);
    inst = head->first;
    while (inst)
    {
        if (!inst->arith)
        {
            if (inst->op == PUSH)
            {
                // constant
                if (inst->segment == CONST)
                    print_code(*inst, *segments, 0, 0);

                // ///////
                if (inst->segment == ARG)
                    print_code(*inst, *segments,segments->arg, 1);
                if (inst->segment == LCL)
                    print_code(*inst, *segments,segments->local, 1);
                if (inst->segment == THIS)
                    print_code(*inst, *segments,segments->t_his, 1);
                if (inst->segment == THAT)
                    print_code(*inst, *segments,segments->that, 1);
                
                // 
                if (inst->segment == PTR)
                {
                    if (!inst->index)
                        print_code(*inst, *segments, segments->t_his, 3);
                    else
                        print_code(*inst, *segments, segments->that, 3);
                }

                // 
                if (inst->segment == TEMP)
                    print_code(*inst, *segments, segments->tmp + inst->index, 3);


                // 
                if (inst->segment == STATIC)
                {
                    dprintf (segments->fd,"//%s\n@%s.%d\nD=M\n@%d\nA=M\nM=D\n@%d\nM=M+1\n",
                        inst->command, head->file_name, inst->index, segments->sp, segments->sp);
                }
            }
            if (inst->op == POP)
            {

                if (inst->segment == ARG)
                    print_code(*inst, *segments, segments->arg, 2);
                if (inst->segment == LCL)
                    print_code(*inst, *segments, segments->local, 2);
                if (inst->segment == THAT)
                    print_code(*inst, *segments, segments->that, 2);
                if (inst->segment == THIS)
                    print_code(*inst, *segments, segments->t_his, 2);

                // 
                if (inst->segment == PTR)
                {
                    if (!inst->index)
                        print_code(*inst, *segments, segments->t_his, 4);
                    else
                        print_code(*inst, *segments, segments->that, 4);
                }

                //
                if (inst->segment == TEMP)
                    print_code(*inst, *segments, segments->tmp + inst->index, 4);

                // 
                if (inst->segment == STATIC)
                {
                    dprintf (segments->fd, "//%s\n@%d\nAM=M-1\nD=M\n@%s.%d\nM=D\n",
                    inst->command, segments->sp, head->file_name, inst->index);
                }
            }
        }
        /////////////  /////////////////////////////////////////
        if (inst->arith == 1)
        {
            if (inst->op == ADD)
            {
                dprintf(segments->fd,"//%s\n@%d\nAM=M-1\nD=M\n@%d\nAM=M-1\nD=M+D\n@%d\nA=M\nM=D\n@%d\nM=M+1\n",
                 inst->command, segments->sp, segments->sp, segments->sp, segments->sp);
            }
            if (inst->op == SUB)
            {
                dprintf(segments->fd,"//%s\n@%d\nAM=M-1\nD=M\n@%d\nAM=M-1\nD=M-D\n@%d\nA=M\nM=D\n@%d\nM=M+1\n",
                 inst->command, segments->sp, segments->sp, segments->sp, segments->sp);
            }
            if (inst->op == NEG)
            {
                dprintf(segments->fd,"//%s\n@%d\nAM=M-1\nM=-M\n@%d\nM=M+1",
                 inst->command, segments->sp, segments->sp);
            }
            // //   ????????
            if (inst->op == EQ)
            {
                segments->mnemonic = ft_strdup("JNE");
                print_code(*inst, *segments, 0, 5);
                free(segments->mnemonic);
            }
            //////
            if (inst->op == GT)
            {
                segments->mnemonic = ft_strdup("JLE");
                print_code(*inst, *segments, 0, 5);
                free(segments->mnemonic);
            }
            if (inst->op == LT)
            {
                segments->mnemonic = ft_strdup("JGE");
                print_code(*inst, *segments, 0, 5);
                free(segments->mnemonic);
            }
            // //
            if (inst->op == AND)
            {
                print_code(*inst, *segments, '&', 6);
            }
            if (inst->op == OR)
            {
                print_code(*inst, *segments, '|', 6);
            }
            //
            if (inst->op == NOT)
            {
                dprintf(segments->fd, "//%s\n@%d\nA=M-1\nM=!M\n",
                 inst->command, segments->sp);
            }

        }
        inst = inst->next;
    }

}