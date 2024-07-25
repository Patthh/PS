/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:27:59 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/25 02:08:18 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	connect(t_stack *first, t_stack *second)
{
	first->next = second;
	second->prev = first;
}

void	unattach_a(t_stack *topush, t_all *meta)
{
	t_stack	*previous;
	t_stack	*next;

	previous = topush->prev;
	next = topush->next;
	if (previous == next)
	{
		previous->next = NULL;
		previous->prev = NULL;
	}
	else
	{
		connect(previous, next);
	}
	reindex_a(meta);
}

void	unattach_b(t_stack *topush, t_all *meta)
{
	t_stack	*previous;
	t_stack	*next;

	previous = topush->prev;
	next = topush->next;
	if (previous == next)
	{
		previous->next = NULL;
		previous->prev = NULL;
	}
	else
	{
		connect(previous, next);
	}
	reindex_b(meta);
}

void	pa(t_all *meta)
{
	t_stack	*zero;
	t_stack	*to_push;
	t_stack	*one;

	to_push = meta->stack_b;
	if (to_push->next == NULL)
		return ;
	to_push = to_push->next;
	unattach_b(to_push, meta);
	zero = meta->stack_a;
	if (zero->next)
	{
		one = zero->next;
		connect(zero, to_push);
		connect(to_push, one);
	}
	else
	{
		connect(zero, to_push);
		connect(to_push, zero);
	}
	reindex_a(meta);
	meta->ssb--;
	meta->ssa++;
	ft_putstr("pa\n");
}

void	pb(t_all *meta)
{
	t_stack	*zero;
	t_stack	*to_push;
	t_stack	*one;

	to_push = meta->stack_a;
	if (to_push->next == NULL)
		return ;
	to_push = to_push->next;
	unattach_a(to_push, meta);
	zero = meta->stack_b;
	if (zero->next)
	{
		one = zero->next;
		connect(zero, to_push);
		connect(to_push, one);
	}
	else
	{
		connect(zero, to_push);
		connect(to_push, zero);
	}
	reindex_b(meta);
	meta->ssa--;
	meta->ssb++;
	ft_putstr("pb\n");
}
