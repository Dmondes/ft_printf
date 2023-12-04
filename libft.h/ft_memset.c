/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:21:26 by delim             #+#    #+#             */
/*   Updated: 2023/10/29 11:30:41 by delim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *block, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)block)[i] = c;
		i ++;
	}
	return (block);
}
/* ptr to memory blk, assigned value in each byte of blk, limit of byte
 * typecast ptr, assigned i-th byte to c, bytes are unsigned values
 * return original pointer*/
