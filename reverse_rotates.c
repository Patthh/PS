/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops_reverse_rotates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:47:58 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/18 19:12:25 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_all *meta)
{
	rra(meta, 0);
	rrb(meta, 0);
	ft_putstr("rrr\n");
}

void	rra(t_all *meta, int x)
{
	t_stack	*one;
	t_stack	*last;
	t_stack	*zero;

	if (meta->ssa < 2)
		return ;
	zero = meta->stack_a;
	one = zero->next;
	last = zero->prev;
	zero->prev->prev->next = zero;
	zero->prev = zero->prev->prev;
	zero->next = last;
	last->prev = zero;
	last->next = one;
	one->prev = last;
	reindex_a(meta);
	if (x)
		ft_putstr("rra\n");
}

void	rrb(t_all *meta, int x)
{
	t_stack	*one;
	t_stack	*last;
	t_stack	*zero;

	if (meta->ssb < 2)
		return ;
	zero = meta->stack_b;
	while (zero->pos != 0)
		zero = zero->next;
	one = zero->next;
	last = zero->prev;
	zero->prev->prev->next = zero;
	zero->prev = zero->prev->prev;
	zero->next = last;
	last->prev = zero;
	last->next = one;
	one->prev = last;
	reindex_b(meta);
	if (x)
		ft_putstr("rrb\n");
}
