/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:17:37 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/03/25 12:35:32 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	pos;

	if (!dest && !src)
		return (NULL);
	pos = 0;
	while (pos < n)
	{
		((unsigned char *)dest)[pos] = ((unsigned char *)src)[pos];
		pos++;
	}
	return (dest);
}
