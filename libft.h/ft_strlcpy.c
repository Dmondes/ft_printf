/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:20:04 by delim             #+#    #+#             */
/*   Updated: 2023/11/11 19:05:05 by delim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (i < (size - 1) && size != 0)
			dest[i] = src[i];
		i ++;
	}
	if (i < size)
		dest[i] = '\0';
	else if (size > 0)
		dest[size - 1] = '\0';
	return (i);
}
