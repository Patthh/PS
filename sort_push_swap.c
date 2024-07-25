/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:50:52 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/18 19:12:25 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_all *meta)
{
	t_stack	*stack_a;
	int		num1;
	int		num2;

	stack_a = meta->stack_a->next;
	num1 = stack_a->number;
	num2 = stack_a->next->number;
	if (num1 > num2)
		sa(meta, 1);
}

void	sort_three(t_all *meta)
{
	t_stack	*stack_a;
	int		num1;
	int		num2;
	int		num3;

	stack_a = meta->stack_a->next;
	num1 = stack_a->number;
	num2 = stack_a->next->number;
	num3 = stack_a->next->next->number;
	if (num1 < num2 && num2 > num3 && num3 > num1)
	{
		rra(meta, 1);
		sa(meta, 1);
	}
	else if (num1 > num2 && num2 < num3 && num3 > num1)
		sa(meta, 1);
	else if (num1 > num2 && num2 > num3 && num3 < num1)
	{
		ra(meta, 1);
		sa(meta, 1);
	}
	else if (num1 > num2 && num2 < num3 && num3 < num1)
		ra(meta, 1);
	else if (num1 < num2 && num2 > num3 && num3 < num1)
		rra(meta, 1);
}

void	push_swap(t_all *meta)
{
	if (meta->ssa == 3)
		return (sort_two(meta));
	push_to_b(meta);
	sort_three(meta);
	if (meta->ssb < 2)
		return ;
	push_to_a(meta);
}
