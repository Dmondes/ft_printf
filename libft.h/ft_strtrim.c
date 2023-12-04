/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:37:13 by delim             #+#    #+#             */
/*   Updated: 2023/11/01 18:48:18 by delim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	copy_str(char *trim_str, char const *s1, int start, int t_len)
{
	int	i;

	i = 0;
	while (i < t_len)
	{
		trim_str[i] = s1[start + i];
		i ++;
	}
	trim_str[i] = '\0';
}

char	*str_zero()
{
	char	*trim_str;

	trim_str = (char *)malloc(sizeof(char));
	if (!trim_str)
		return (NULL);
	*trim_str = '\0';
	return (trim_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	len;
	int	i;
	int	trimmed_len;
	char	*trim_str;

	start = 0;
	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	while (start < len && ft_strchr(set, s1[start]) != NULL)
		start ++;
	while (i < len && ft_strrchr(set, s1[len - i - 1]) != NULL)
		i ++;
	trimmed_len = len - start - i;
	if (trimmed_len <= 0)
		return (str_zero());
	trim_str = (char *)malloc(sizeof(char) * (trimmed_len + 1));
	if (!trim_str)
		return (NULL);
	copy_str(trim_str, s1, start, trimmed_len);
	return (trim_str);
}
