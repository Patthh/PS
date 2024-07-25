/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:04:37 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/18 19:12:25 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_to_push_a(t_all *meta)
{
	t_stack	*current;
	t_stack	*to_push;

	current = meta->stack_a->next;
	to_push = current;
	while (current->pos != 0)
	{
		if (current->cost < to_push->cost)
			to_push = current;
		current = current->next;
	}
	return (to_push);
}

void	execute_push_a(t_stack *to_push, t_all *meta)
{
	t_stack	*target;

	target = to_push->target;
	if (to_push->dir_a == 1 && to_push->dir_b == 1)
		a_pos_pos(meta, to_push, target);
	if (to_push->dir_a == -1 && to_push->dir_b == 1)
		a_neg_pos(meta, to_push, target);
	if (to_push->dir_a == -1 && to_push->dir_b == -1)
		a_neg_neg(meta, to_push, target);
	if (to_push->dir_a == 1 && to_push->dir_b == -1)
		a_pos_neg(meta, to_push, target);
}

void	push_to_b(t_all *meta)
{
	t_stack	*to_push;

	while (meta->ssa > 4 && meta->ssb < 3)
		pb(meta);
	while (meta->ssa > 4)
	{
		get_all_targets_a(meta);
		getcosts_a(meta);
		to_push = get_to_push_a(meta);
		execute_push_a(to_push, meta);
	}
}
