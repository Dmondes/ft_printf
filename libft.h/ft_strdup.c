/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:08:10 by delim             #+#    #+#             */
/*   Updated: 2023/10/29 14:12:28 by delim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*point;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src) + 1;
	point = (char *)malloc(sizeof(char) * len);
	if (!point)
		return (NULL);
	while (src[i])
	{
		point[i] = src[i];
		i ++;
	}
	point[i] = '\0';
	return (point);
}
//strdup: returns a dynmiclly alloc. cpy of str, dsnt affct original
