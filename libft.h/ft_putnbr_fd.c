/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:10:49 by delim             #+#    #+#             */
/*   Updated: 2023/11/09 18:29:46 by delim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	num;

	num = n;
	if (n < 0)
	{
		num = -num;
		ft_putchar_fd('-', fd);
	}
	if (num < 10)
	{
		c = num + '0';
		ft_putchar_fd(c, fd);
	}
	else
	{
		ft_putnbr_fd((num / 10), fd);
		num = num % 10;
		c = num + '0';
		ft_putchar_fd(c, fd);
	}
}
