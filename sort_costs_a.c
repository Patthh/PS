/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_costs_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:24:07 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/18 19:12:25 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	calc_r_r_a(t_stack *node)
{
	size_t	cost_a;
	size_t	cost_b;

	cost_a = node->pos -1;
	cost_b = node->target->pos -1;
	if (cost_b > cost_a)
		cost_a = cost_b;
	return (cost_a + 1);
}

size_t	calc_r_rr_a(t_stack *node, t_all *meta)
{
	size_t	cost_a;
	size_t	cost_b;

	cost_a = node->pos -1;
	cost_b = meta->ssb - node->target->pos;
	return (cost_a + cost_b + 1);
}

size_t	calc_rr_rr_a(t_stack *node, t_all *meta)
{
	size_t	cost_a;
	size_t	cost_b;

	cost_a = meta->ssa - node->pos;
	cost_b = meta->ssb - node->target->pos;
	if (cost_b > cost_a)
		cost_a = cost_b;
	return (cost_a + 1);
}

size_t	calc_rr_r_a(t_stack *node, t_all *meta)
{
	size_t	cost_a;
	size_t	cost_b;

	cost_a = meta->ssa - node->pos;
	cost_b = node->target->pos - 1;
	return (cost_a + cost_b + 1);
}

void	getcosts_a(t_all *meta)
{
	t_stack	*current;

	current = meta->stack_a->next;
	while (current->pos != 0)
	{
		current->cost = calc_r_r_a(current);
		put_direction(current, -1, -1);
		if (current->cost > calc_r_rr_a(current, meta))
		{
			current->cost = calc_r_rr_a(current, meta);
			put_direction(current, -1, 1);
		}
		if (current->cost > calc_rr_rr_a(current, meta))
		{
			current->cost = calc_rr_rr_a(current, meta);
			put_direction(current, 1, 1);
		}
		if (current->cost > calc_rr_r_a(current, meta))
		{
			current->cost = calc_rr_r_a(current, meta);
			put_direction(current, 1, -1);
		}
		current = current->next;
	}
}
