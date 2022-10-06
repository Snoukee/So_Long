/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:15:42 by ifreire-          #+#    #+#             */
/*   Updated: 2022/03/10 00:15:43 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_aux(int d)
{
	char	c;

	if (d < 10)
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

int	ft_dec(int d)
{
	if (d == -2147483648)
		return (write(1, "-2147483648", 11));
	if (d >= 10)
	{
		ft_dec(d / 10);
		ft_dec(d % 10);
	}
	else
	{
		if (d < 0)
		{
			write(1, "-", 1);
			d = -d;
			ft_dec(d);
		}
		else if (d < 10)
			ft_aux(d);
	}
	return (0);
}

int	d_printf(int d)
{
	if (d == 0)
		return (write(1, "0", 1));
	else
		ft_dec(d);
	return (ft_itoaalt(d));
}
