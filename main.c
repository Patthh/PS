/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:21:00 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/25 03:11:07 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	set_meta_null(t_all *meta)
{
	meta->stack_a = NULL;
	meta->stack_b = NULL;
	meta->input = NULL;
	meta->split = NULL;
	meta->ssa = 0;
	meta->ssb = 0;
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_all	*push;

	if (check_mt(argv))
		return (error (), 1);
	push = malloc(sizeof(t_all));
	if (!push)
		return (free(push), 1);
	set_meta_null(push);
	if (argc < 2)
		return (free(push), 1);
	else
	{
		if (!checkinputs(argc, argv, push))
			return (free_stac(push), exit(1), 1);
		if (!waitsort(push))
			return (free_stac(push), 0);
		fill_stack_a(push);
		create_stack_b(push);
		if (is_filled_a(push))
		{
			push_swap(push);
			free_stac(push);
		}
	}
	return (0);
}

// void print_stack(t_stack *stack, size_t max_size) {
//     if (!stack)
//     {
//         printf("(empty)\n");
//         return;
//     }
//     t_stack *current = stack;
//     size_t count = 0;
// 	    if (current->number == 0 && current->next != NULL) {
//         current = current->next;
//     }
//     while (current && count < max_size)
//     {
//         printf("%d ", current->number);
//         current = current->next;
//         count++;
//     }
//     if (count == max_size && current)
//         printf("... (more elements)");
//     printf("\n");
// }
// int	main(int argc, char **argv)
// {
// 	t_all	*push;
// 	if (check_mt(argv))
// 		return (error (), 1);
// 	push = malloc(sizeof(t_all));
// 	if (!push)
// 		return (free(push), 1);
// 	set_meta_null(push);
// 	if (argc < 2)
// 		return (free(push), 1);
// 	else
// 	{
// 		if (!checkinputs(argc, argv, push))
// 			return (free_stac(push), exit(1), 1);
// 		if (!waitsort(push))
// 			return (free_stac(push), 0);
// 		fill_stack_a(push);
// 		create_stack_b(push);
// 		printf("Initial state:\n");
//         printf("Stack A: ");
//         print_stack(push->stack_a, push->ssa);
//         printf("Stack B: ");
//         print_stack(push->stack_b, push->ssb);
// 		if (is_filled_a(push))
// 		{
// 			printf("operation :\n");
// 			push_swap(push);
// 			printf("\nFinal state:\n");
//             printf("Stack A: ");
//             print_stack(push->stack_a, push->ssa);
//             printf("Stack B: ");
//             print_stack(push->stack_b, push->ssb);
// 			free_stac(push);
// 		}
// 	}
// 	return (0);
// }