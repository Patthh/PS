/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:55:30 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/25 00:59:06 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*allocz(void)
{
	char	*ptr;

	ptr = (char *)ft_calloc(1, sizeof(char));
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start > (unsigned int)s_len)
		return (allocz());
	if (len > (size_t)ft_strlen((char *)s + start))
		len = (size_t)ft_strlen((char *)s + start);
	substring = (char *)ft_calloc((len + 1), sizeof(char));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}
