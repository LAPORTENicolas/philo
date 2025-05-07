/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 04:39:54 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/15 04:39:56 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(long long unsigned n, int fd, char *b)
{
	if (n <= 0)
		return (0);
	else if (n > 15)
		return (ft_printhex(n / 16, fd, b) + ft_putchar_fd(b[n % 16], fd));
	return (ft_putchar_fd(b[n % 16], fd));
}

int	ft_printhex2(unsigned int n, int fd, char *b)
{
	if (n <= 0)
		return (ft_putchar_fd('0', 1));
	else if (n > 15)
		return (ft_printhex2(n / 16, fd, b) + ft_putchar_fd(b[n % 16], fd));
	return (ft_putchar_fd(b[n % 16], fd));
}

int	ft_puthex_fd(long long unsigned n, int fd, int suffix)
{
	if (suffix == 1)
		return (ft_putstr_fd("0x", 1) + ft_printhex(n, fd, "0123456789abcdef"));
	else if (suffix == 2)
		return (ft_printhex(n, fd, "0123456789abcdef"));
	else if (suffix == 3)
		return (ft_printhex(n, fd, "0123456789ABCDEF"));
	return (0);
}
