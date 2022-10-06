/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Uprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:20:01 by ifreire-          #+#    #+#             */
/*   Updated: 2022/03/15 23:58:45 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_size_u(unsigned int d)
{
	int	size;

	size = 0;
	while (d != 0)
	{
		size++;
		d = d / 10;
	}
	return (size);
}

void	ft_uns_int(unsigned int d)
{
	char	c;

	if (d >= 10)
	{
		ft_uns_int(d / 10);
		ft_uns_int(d % 10);
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
			c = d + 48;
			write(1, &c, 1);
		}
	}
}

int	u_printf(unsigned int d)
{
	if (d == 0)
		return (write(1, "0", 1));
	else
		ft_uns_int(d);
	return (ft_size_u(d));
}
