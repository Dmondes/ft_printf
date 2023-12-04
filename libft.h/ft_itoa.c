/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:50:05 by delim             #+#    #+#             */
/*   Updated: 2023/11/01 19:01:45 by delim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*case_zero(void)
{
	char	*new_str;

	new_str = (char *)malloc(2);
	if (!new_str)
		return (NULL);
	new_str[0] = '0';
	new_str[1] = '\0';
	return (new_str);
}

int	count_digits(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count ++;
		n /= 10;
	}
	return (count);
}

void	fill_str(int count, long n, char *new_str, int negative)
{
	count -= 1;
	while (n > 0)
	{
		new_str[count] = n % 10 + '0';
		n /= 10;
		count --;
	}
	if (negative)
		new_str[0] = '-';
}

char	*ft_itoa(int n)
{
	int		negative;
	int		count;
	char	*new_str;
	long int	num;

	negative = 0;
	count = 0;
	num = n;
	if (n == 0)
		return(case_zero());
	if (num < 0)
	{
		num = -num;
		negative = 1;
		count ++;
	}
	count += count_digits(num);
	new_str = (char *)malloc(count + 1);
	if (!new_str)
		return (NULL);
	fill_str(count, num, new_str, negative);
	new_str[count] = '\0';
	return (new_str);
}
