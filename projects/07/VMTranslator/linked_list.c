/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:08:31 by zael-mab          #+#    #+#             */
/*   Updated: 2021/11/19 09:08:31 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


void    init_newnode(t_node *newnode, t_vmdata data)
{
    newnode->op = data.op;
    newnode->segment = data.segment;
    newnode->index = data.index;
    newnode->command = ft_strdup(data.line);
    newnode->arith = data.arith;
    newnode->label = NULL;
    newnode->next = NULL;
}

void    add_last(t_head *head, t_vmdata *data)
{
    t_node *newnode;
    t_node *tmp;

    newnode = ft_memalloc(sizeof(t_node));
    init_newnode(newnode, *data);
    if (data->label)
        newnode->label = ft_strdup(data->label);
    if (!head->first)
    {
        head->first = newnode;
        newnode->pos = 1;
        head->h_size = 1;
    }
    else
    {
        tmp = head->first;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = newnode;
        head->h_size++;
        newnode->pos = head->h_size;
    }
}

