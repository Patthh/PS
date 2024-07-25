/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_targeting_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:15:39 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/18 19:12:25 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_min_a(t_all *meta)
{
	size_t	counter;
	t_stack	*stack_a;
	t_stack	*min;

	counter = 1;
	stack_a = meta->stack_a->next;
	min = stack_a;
	while (counter++ < meta->ssa)
	{
		if (stack_a->number < min->number)
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}

t_stack	*get_closest_a(int number, t_all *meta)
{
	size_t	counter;
	t_stack	*stack_a;
	t_stack	*closest;

	counter = 1;
	stack_a = meta->stack_a->next;
	closest = NULL;
	while (counter++ < meta->ssa)
	{
		if (number < stack_a->number && !closest)
			closest = stack_a;
		else if (number < stack_a->number && stack_a->number > closest->number)
			closest = stack_a;
		stack_a = stack_a->next;
	}
	return (closest);
}

t_stack	*get_target_b(t_stack *node, t_all *meta)
{
	t_stack	*target;

	target = get_closest_a(node->number, meta);
	if (!target)
		target = get_min_a(meta);
	return (target);
}

void	get_all_targets_b(t_all *meta)
{
	t_stack	*current;
	size_t	counter;

	counter = 1;
	current = meta->stack_b->next;
	while (counter++ < meta->ssb)
	{
		current->target = get_target_b(current, meta);
		current = current->next;
	}
}
