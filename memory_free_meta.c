/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free_meta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:24:49 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/25 02:14:02 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_split(t_all *push)
{
	int		i;
	char	**split;

	i = 0;
	split = push->split;
	if (!split)
		return ;
	while (split[i])
	{
		ft_free((void **)&split[i]);
		i++;
	}
	ft_free((void **)&split);
}

void	clearstack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (!stack)
		return ;
	if (!stack->next)
		return (ft_free((void **)&stack));
	current = stack->next;
	while (current && current->pos != 0)
	{
		temp = current;
		current = current->next;
		ft_free((void **)&temp);
	}
	ft_free((void **)&stack);
	stack = NULL;
}

void	free_stac(t_all *push)
{
	if (!push)
		return ;
	if (push->stack_a)
		clearstack(push->stack_a);
	push->stack_a = NULL;
	if (push->stack_b)
		clearstack(push->stack_b);
	push->stack_b = NULL;
	if (push->input)
		clearinput(push);
	free_split(push);
	ft_free((void **)&push);
	push = NULL;
}

void	clearinput(t_all *push)
{
	t_proc_input	*current;
	t_proc_input	*temp;

	current = push->input;
	while (current)
	{
		temp = current;
		current = current->next;
		if (temp->raw)
			ft_free((void **)&temp->raw);
		if (temp->clean)
			ft_free((void **)&temp->clean);
		if (temp->compare)
			ft_free((void **)&temp->compare);
		ft_free((void **)&temp);
	}
	push->input = NULL;
}
