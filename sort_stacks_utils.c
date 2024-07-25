/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:29:16 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/18 19:12:25 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reindex_b(t_all *meta)
{
	t_stack	*stack_b;
	size_t	pos;

	pos = 1;
	stack_b = meta->stack_b;
	if (!stack_b->next)
		return ;
	while (stack_b->pos != 0)
		stack_b = stack_b->next;
	stack_b = stack_b->next;
	while (stack_b->pos != 0)
	{
		stack_b->pos = pos;
		pos++;
		stack_b = stack_b->next;
	}
}

void	reindex_a(t_all *meta)
{
	t_stack	*stack_a;
	size_t	pos;

	pos = 1;
	stack_a = meta->stack_a;
	if (!stack_a->next)
		return ;
	while (stack_a->pos != 0)
		stack_a = stack_a->next;
	stack_a = stack_a->next;
	while (stack_a->pos != 0)
	{
		stack_a->pos = pos;
		pos++;
		stack_a = stack_a->next;
	}
}

void	put_direction(t_stack *node, int a, int b)
{
	node->dir_a = a;
	node->dir_b = b;
}
