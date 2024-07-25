/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:41:07 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/25 02:48:32 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	int		strlen;
	int		i;
	char	*duplicate;

	strlen = ft_strlen((char *)s);
	duplicate = (char *)ft_calloc(strlen + 1, sizeof(char));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (*s)
	{
		duplicate[i] = *s;
		s++;
		i++;
	}
	duplicate[i] = 0;
	return (duplicate);
}
