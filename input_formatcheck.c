/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_formatcheck.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:22:19 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/24 21:26:02 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isplusminus(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	checkformat(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (!ft_isdigit(input[i]) && !isplusminus
			(input[i]) && !ft_isspace(input[i]))
			return (0);
		if (isplusminus(input[i]) && !ft_isdigit(input[i + 1]))
			return (0);
		if (ft_isdigit(input[i]) && isplusminus(input[i + 1]))
			return (0);
	}
	return (1);
}

int	check_mt(char **input)
{
	char	**arg;
	char	*chr;

	arg = input + 1;
	while (*arg)
	{
		if (ft_strlen(*arg) == 0)
			return (1);
		chr = *arg;
		while (*chr == ' ')
			chr++;
		if (*chr == '\0')
			return (1);
		arg++;
	}
	return (0);
}
// int	check_mt(char **input)
// {
// 	int	i;
// 	int	j;
// 	i = 1;
// 	while (input[i])
// 	{
// 		j = 0;
// 		if (ft_strlen(input[i]) == 0)
// 			return (1);
// 		while (input[i][j])
// 		{
// 			if (input[i][j] == 32)
// 				j++;
// 			else
// 				break;
// 			if (input[i][j] == '\0')
// 				return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }
