/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 09:06:23 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/03/26 11:41:13 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*ite;
	size_t	i;

	if (s == NULL)
		return (NULL);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ite = ret;
	if (start < len)
	{
		i = 0;
		s += start;
		while (s[i] && i < len)
			*ite++ = s[i++];
	}
	*ite = '\0';
	return (ret);
}
