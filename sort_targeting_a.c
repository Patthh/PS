/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_targeting_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:15:39 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/18 19:12:25 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_max_b(t_all *meta)
{
	size_t	counter;
	t_stack	*stack_b;
	t_stack	*max;

	counter = 1;
	stack_b = meta->stack_b->next;
	max = stack_b;
	while (counter++ < meta->ssb)
	{
		if (stack_b->number > max->number)
			max = stack_b;
		stack_b = stack_b->next;
	}
	return (max);
}

t_stack	*get_closest_b(int number, t_all *meta)
{
	size_t	counter;
	t_stack	*stack_b;
	t_stack	*closest;

	counter = 1;
	stack_b = meta->stack_b->next;
	closest = NULL;
	while (counter++ < meta->ssb)
	{
		if (number > stack_b->number && !closest)
			closest = stack_b;
		else if (number > stack_b->number && stack_b->number > closest->number)
			closest = stack_b;
		stack_b = stack_b->next;
	}
	return (closest);
}

t_stack	*get_target_a(t_stack *node, t_all *meta)
{
	t_stack	*target;

	target = get_closest_b(node->number, meta);
	if (!target)
		target = get_max_b(meta);
	return (target);
}

void	get_all_targets_a(t_all *meta)
{
	t_stack	*current;
	size_t	counter;

	if (meta->ssb < 3 || meta->ssa < 2)
		return ;
	counter = 1;
	current = meta->stack_a->next;
	while (counter++ < meta->ssa)
	{
		current->target = get_target_a(current, meta);
		current = current->next;
	}
}
