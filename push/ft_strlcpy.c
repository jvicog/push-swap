/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 20:12:24 by jvico-ga          #+#    #+#             */
/*   Updated: 2022/02/17 18:42:19 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	value;

	value = 0;
	if (dstsize != 0)
	{
		while (dstsize-- - 1 && src[value] != '\0')
		{
			dst[value] = src[value];
			value++;
		}
		dst[value] = '\0';
	}
	while (src[value] != '\0')
		value++;
	return (value);
}
