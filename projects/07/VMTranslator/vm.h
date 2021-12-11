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
# include <stdio.h>

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

# define    LBL     7
# define    IFGOTO  77
# define    GOTO    777



# define    LCL     1
# define    ARG     2
# define    THIS    4
# define    THAT    16
# define    CONST   32
# define    STATIC  64
# define    PTR     128
# define    TEMP    256


typedef enum {true, false} bool;


typedef struct      s_head
{
    int             h_size;
    char            *file_name;
    struct s_node   *first;
}                   t_head;

typedef struct      s_node
{
    int             op;
    int             pos;
    int             segment;
    int             index;
    bool            arith;
    char            *command;
    char            *label;
    struct s_node  *next;
}                   t_node;

typedef struct      s_vmdata
{
    int             op;
    int             segment;
    int             index;
    bool            arith;  
    char            *label;
    char            *line;
}                   t_vmdata;

typedef struct          s_memory_segments
{
    unsigned int        sp;
    unsigned int        local;
    unsigned int        arg;
    unsigned int        t_his;
    unsigned int        that;
    unsigned int        tmp;

    char                *mnemonic;
    int                 fd;
}                       t_memory_segments;

//
// set sp 256,        // stack pointer
// set local 300,     // base address of the local segment
// set argument 400,  // base address of the argument segment
// set this 3000,     // base address of the this segment
// set that 3010,     // base address of the that segment

// push segment i
// pop segment i
// segment = {local , arg, this , that}

// addr = segmentPointer + i, *sp = *addr, sp++
// addr = segmentPointer + i, sp--, *addr = *sp

//  push constant i =>  *sp = i, sp++
//  no pop constant operation

//  static stored RAM[16] => RAM[255]
// file.vm          
// pop static 5 ==> @filename.5 , M=D
// pop static 2 ==> @filename.2 , M=D

//  temp  a fixed 8-place memory segment.
//  maped on Ram locations 5 to 12
//  pop tmp i =>  addr = 5 + i, *sp = *addr, sp++
//  push tmp i => addr = 5 + i, sp--. *addr =*sp


//  push pointer 0/1    =>  *sp = this/that, sp++
//  pop pointer 0/1     =>  sp--, this/that = *sp
//      pointer 0 accessing this
//      pointer 1 accessing that

void        add_last(t_head *head, t_vmdata *data);
int         set_op(char *op);
int         set_segment(char *segment);
int         check_and_set(char *line, t_vmdata *data);
void        trans(t_head *head, t_memory_segments *segments);
void        print_code(t_node inst, t_memory_segments segments, int x, int sw);



#endif