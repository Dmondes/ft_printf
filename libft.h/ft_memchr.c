/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:12:37 by delim             #+#    #+#             */
/*   Updated: 2023/10/29 13:21:23 by delim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *block, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (*(unsigned char *)(block + i) == (unsigned char)c)
			return ((void *)(block + i));
		i ++;
	}
	return (NULL);
}
// typecast to ensure individual byte/ char
// deref to get value, typecast for byte, ptr arithmetic
