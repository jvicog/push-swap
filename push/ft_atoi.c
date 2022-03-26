/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:57:24 by jvico-ga          #+#    #+#             */
/*   Updated: 2022/03/14 19:19:15 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long long	value;
	int			sign;

	sign = 1;
	value = 0;
	while (*str == '\t' || *str == ' ' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == '\n')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+' || *str == ' ')
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		value = value * 10 + (*str - '0');
		str++;
		if ((value * sign) > 2147483647)
			return (0);
		if ((value * sign) < -21474836478)
			return (0);
	}
	return (value * sign);
}
