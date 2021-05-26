/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:56:06 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/05/25 12:13:17 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define	FT_ULONG_MAX ((unsigned long)(~0L))
#define FT_LONG_MAX 0x7FFFFFFFFFFFFFFF
#define FT_LONG_MIN 0x8000000000000000

static long	handle_limit(long res, int overflow, int sign)
{
	if (overflow)
	{
		if (sign < 0)
			return (FT_LONG_MIN);
		else
			return (FT_LONG_MAX);
	}
	if (sign < 0)
		return (-res);
	return (res);
}

static long	ft_strtol(const char *str, int sign)
{
	unsigned long	val;
	int				digit;
	int				overflow;
	unsigned long	cutoff;
	int				cutlim;

	val = 0;
	if (sign < 0)
		cutoff = -(unsigned long)FT_LONG_MIN;
	else
		cutoff = (unsigned )FT_LONG_MAX;
	cutlim = cutoff % 10;
	cutoff /= 10;
	overflow = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		if (overflow || val > cutoff
			|| (val == cutoff && digit > cutlim))
			overflow = 1;
		else
			val = val * 10 + digit;
		str++;
	}
	return ((int)handle_limit(val, overflow, sign));
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return ((int)ft_strtol(str, sign));
}
