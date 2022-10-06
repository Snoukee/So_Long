/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uXprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:16:11 by ifreire-          #+#    #+#             */
/*   Updated: 2022/03/15 23:51:03 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_hex65(unsigned int d)
{
	char	c;

	if (d >= 16)
	{
		ft_hex65(d / 16);
		ft_hex65(d % 16);
	}
	else
	{
		if (d <= 9)
		{
			c = d + 48;
			write (1, &c, 1);
		}
		else
		{
			c = d + 55;
			write(1, &c, 1);
		}
	}
}

int	hex65_printf(int d)
{
	if (d == 0)
		return (write(1, "0", 1));
	else
		ft_hex65(d);
	return (ft_size_hex(d));
}
