/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:17:35 by pracksaw          #+#    #+#             */
/*   Updated: 2024/07/18 19:12:25 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	index;

	index = 0;
	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	while (index + 1 < size && src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	if (size != 0)
		dst[index] = '\0';
	return (srclen);
}
