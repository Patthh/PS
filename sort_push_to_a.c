/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:02:49 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/18 19:12:25 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_max_b(t_all *meta)
{
	t_stack	*current;
	t_stack	*max;

	current = meta->stack_b->next;
	max = current;
	while (current->pos != 0)
	{
		if (current->number > max->number)
			max = current;
		current = current->next;
	}
	return (max);
}

void	push_to_a(t_all *meta)
{
	t_stack	*b_max;
	t_stack	*a_middle;

	a_middle = meta->stack_a->next->next;
	b_max = get_max_b(meta);
	if (b_max->pos < meta->ssb / 2)
		while (meta->stack_b->next != b_max)
			rb(meta, 1);
	else
		while (meta->stack_b->next != b_max)
			rrb(meta, 1);
	while (meta->ssb > 1 && meta->stack_b->next->number
		> a_middle->next->number)
		pa(meta);
	rra(meta, 1);
	while (meta->ssb > 1 && meta->stack_b->next->number
		> a_middle->number)
		pa(meta);
	rra(meta, 1);
	while (meta->ssb > 1 && meta->stack_b->next->number
		> meta->stack_a->prev->number)
		pa(meta);
	rra(meta, 1);
	while (meta->ssb > 1)
		pa(meta);
}
