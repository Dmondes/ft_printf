/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:37:40 by delim             #+#    #+#             */
/*   Updated: 2023/10/29 11:41:14 by delim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *block, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)block)[i] = '\0';
		i ++;
	}
}
// set memory bytes to zero
// bzero is a specific form of memset
