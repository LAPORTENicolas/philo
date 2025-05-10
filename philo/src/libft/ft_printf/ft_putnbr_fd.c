/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:32:55 by nlaporte          #+#    #+#             */
/*   Updated: 2025/05/09 15:37:26 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

static int	ft_print(unsigned int n, int fd)
{
	if (n <= 0)
		return (0);
	return (ft_print(n / 10, fd) + ft_putchar_fd((n % 10) + '0', fd));
}

int	ft_putnbr_fd(int n, int fd)
{
	char	str[20];
	int		i;

	i = 0;
	while (n > 0 && n <= INT_MAX)
	{
		str[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (n == 0)
		str[i] = '0';
	ft_putstr_fd(str, fd);
	return (i);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	return (ft_print(n, fd));
}
