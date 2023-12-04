/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:44:17 by delim             #+#    #+#             */
/*   Updated: 2023/10/29 12:56:39 by delim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = c;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i ++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
// convert c to ascii char
// return is same as ((char *)s + i);
// if char ch happens to be null-term char
