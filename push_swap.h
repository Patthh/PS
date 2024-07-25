/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:01:31 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/25 02:55:12 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_stack
{
	int				number;
	size_t			pos;
	size_t			cost;
	int				dir_a;
	int				dir_b;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_proc_input
{
	char					*raw;
	char					*clean;
	int						number;
	char					*compare;
	struct s_proc_input		*next;
}	t_proc_input;

typedef struct s_all
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_proc_input	*input;
	char			**split;
	size_t			ssa;
	size_t			ssb;
}	t_all;

void	fill_stack_a(t_all *push);
int		is_filled_a(t_all *push);
void	create_stack_b(t_all *push);
int		waitsort(t_all *push);

void	free_stac(t_all *push);
void	reindex_a(t_all *push);
void	reindex_b(t_all *push);
void	clearinput(t_all *push);

char	*ft_itoa(int n);
int		ft_atoi(const char *nptr, int *nbr);
void	ft_putstr(char *s);
int		ft_strlen(char *s);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_free(void **ptr);
void	error(void);

void	ra(t_all *push, int x);
void	rb(t_all *push, int x);
void	rr(t_all *push);
void	rrr(t_all *push);
void	rra(t_all *push, int x);
void	rrb(t_all *push, int x);
void	pa(t_all *push);
void	pb(t_all *push);
void	sa(t_all *push, int x);
void	sb(t_all *push, int x);
void	ss(t_all *push);

void	get_all_targets_a(t_all *push);
void	get_all_targets_b(t_all *push);

void	put_direction(t_stack *node, int a, int b);
void	getcosts_a(t_all *push);

void	checkdupes(t_all *push);
void	cleaninput(t_all *push);
int		check_mt(char **input);
int		ft_isspace(char c);
int		checkinputs(int argc, char **argv, t_all *push);
int		checkformat(char *input);
void	convertback(t_all *push);
void	convertnumbers(t_all *push);
void	push_swap(t_all *push);
void	push_to_b(t_all *push);
void	push_to_a(t_all *push);

void	a_pos_pos(t_all *push, t_stack *to_push, t_stack *target);
void	a_neg_neg(t_all *push, t_stack *to_push, t_stack *target);
void	a_pos_neg(t_all *push, t_stack *to_push, t_stack *target);
void	a_neg_pos(t_all *push, t_stack *to_push, t_stack *target);
t_stack	*get_min_a(t_all *push);
int		ft_strcmp(const char *s1, const char *s2);

#endif
