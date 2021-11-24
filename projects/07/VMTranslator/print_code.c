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
        ft_printf ("//%s\n@%d\nD=A\n@%d\nA=M\nM=D\n@%d\nM=M+1\n",
         inst.command, inst.index, segments.sp, segments.sp);
    if (sw == 1)
        ft_printf ("//%s\n@%d\nD=A\n@%d\nA=M+D\nD=M\n@%d\nA=M\nM=D\n@%d\nM=M+1\n",
            inst.command, inst.index, x, segments.sp, segments.sp);
    if (sw == 2)
        ft_printf ("//%s\n@%d\nD=A\n@%d\nM=M+D\n@%d\nAM=M-1\nD=M\n@%d\nA=M\nM=D\n@%d\nD=A\n@%d\nM=M-D\n",
            inst.command, inst.index, x, segments.sp, x, inst.index, x);
    if (sw == 3)
        ft_printf ("//%s\n@%d\nD=M\n@%d\nA=M\nM=D\n@%d\nM=M+1\n",
         inst.command, x, segments.sp, segments.sp);
    if (sw == 4)
        ft_printf ("//%s\n@%d\nAM=M-1\nD=M\n@%d\nM=D\n",
        inst.command, segments.sp, x);
    if (sw == 5)
        ft_printf("//%s\n@%d\nAM=M-1\nD=M\n@%d\nAM=M-1\nD=M-D\n@FALSE\nD;%s\n@%d\nA=M\nMD=1\n@GO\n0;JMP\n(FALSE)\n@%d\nA=M\nM=0\n(GO)\n@%d\nM=M+1\n",
        inst.command, segments.sp, segments.sp, segments.mnemonic, segments.sp, segments.sp, segments.sp);
    if (sw == 6)
        ft_printf("//%s\n@%d\nAM=M-1\nD=M\n@%d\nAM=M-1\nD=D%cM\n@%d\nA=M\nM=D\n@%d\nM=M+1\n",
         inst.command, segments.sp, segments.sp, x,segments.sp, segments.sp);
            
}