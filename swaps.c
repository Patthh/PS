/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops_swaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:32:53 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/18 19:12:25 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_all *meta, int x)
{
	int		temp;
	t_stack	*one;
	t_stack	*two;

	if (meta->ssa < 3)
		return ;
	one = meta->stack_a;
	while (one->pos != 1)
		one = one->next;
	two = one->next;
	temp = one->number;
	one->number = two->number;
	two->number = temp;
	if (x)
		ft_putstr("sa\n");
}

void	sb(t_all *meta, int x)
{
	int		temp;
	t_stack	*one;
	t_stack	*two;

	if (meta->ssb < 3)
		return ;
	one = meta->stack_b;
	while (one->pos != 1)
		one = one->next;
	two = one->next;
	temp = one->number;
	one->number = two->number;
	two->number = temp;
	if (x)
		ft_putstr("sb\n");
}

void	ss(t_all *meta)
{
	sa(meta, 0);
	sb(meta, 0);
	ft_putstr("ss\n");
}
