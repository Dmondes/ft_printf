/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:52:03 by delim             #+#    #+#             */
/*   Updated: 2023/11/09 17:33:40 by delim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;

    if (!dest && !src)
        return (NULL); 
    i = 0;
    if (dest > src) 
    {
        i = n;
        while (i > 0) 
        {
            ((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
            i--;
        }
    }
    else
    {
        while (i < n) 
        {
            ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
            i++;
        }
    }
    return (dest);
}
