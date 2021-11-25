/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 02:01:23 by zael-mab          #+#    #+#             */
/*   Updated: 2021/11/22 02:01:24 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vm.h"

void    print_code(t_node inst, t_memory_segments segments, int x, int sw)
{
    if (sw == 0)
        dprintf(segments.fd,"//%s\n@%d\nD=A\n@%d\nA=M\nM=D\n@%d\nM=M+1\n",
         inst.command, inst.index, segments.sp, segments.sp);
    if (sw == 1)
        dprintf(segments.fd, "//%s\n@%d\nD=A\n@%d\nA=M+D\nD=M\n@%d\nA=M\nM=D\n@%d\nM=M+1\n",
            inst.command, inst.index, x, segments.sp, segments.sp);
    if (sw == 2)
        dprintf (segments.fd, "//%s\n@%d\nD=A\n@%d\nM=M+D\n@%d\nAM=M-1\nD=M\n@%d\nA=M\nM=D\n@%d\nD=A\n@%d\nM=M-D\n",
            inst.command, inst.index, x, segments.sp, x, inst.index, x);
    if (sw == 3)
        dprintf(segments.fd,"//%s\n@%d\nD=M\n@%d\nA=M\nM=D\n@%d\nM=M+1\n",
         inst.command, x, segments.sp, segments.sp);
    if (sw == 4)
        dprintf(segments.fd,"//%s\n@%d\nAM=M-1\nD=M\n@%d\nM=D\n",
        inst.command, segments.sp, x);
    if (sw == 5)
        dprintf(segments.fd, "//%s\n@%d\nAM=M-1\nD=M\n@%d\nAM=M-1\nD=M-D\n@FALSE%d\nD;%s\n@%d\nA=M\nMD=%d\n@GO%d\n0;JMP\n(FALSE%d)\n@%d\nA=M\nM=0\n(GO%d)\n@%d\nM=M+1\n",
        inst.command, segments.sp, segments.sp, inst.pos, segments.mnemonic, segments.sp, (inst.op == EQ ? -1 : -1),inst.pos, inst.pos, segments.sp, inst.pos, segments.sp);
    if (sw == 6)
        dprintf(segments.fd, "//%s\n@%d\nAM=M-1\nD=M\n@%d\nAM=M-1\nD=D%cM\n@%d\nA=M\nM=D\n@%d\nM=M+1\n",
         inst.command, segments.sp, segments.sp, x,segments.sp, segments.sp);
            
}