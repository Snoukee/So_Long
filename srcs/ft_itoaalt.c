/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:09:37 by ifreire-          #+#    #+#             */
/*   Updated: 2022/03/14 21:16:39 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_size(int i)
{
	int	size;

	size = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i = i / 10;
		size++;
	}
	return (size);
}

char	*ft_convert(int n, int size)
{
	char	*dest;
	int		signal;

	signal = -1;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	dest[size] = '\0';
	size--;
	if (n < 0)
	{
		n = -n;
		dest[0] = '-';
		signal = 0;
	}
	while (size > signal)
	{
		dest[size] = (n % 10) + 48;
		size--;
		n /= 10;
	}
	return (dest);
}

int	ft_charsize(char *dest)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	free(dest);
	return (i);
}

int	ft_itoaalt(int n)
{
	int		size;
	int		index;
	char	*x;

	if (n == -2147483648)
		return (11);
	size = ft_size(n);
	if (n < 0)
		size ++;
	x = ft_convert(n, size);
	index = ft_charsize(x);
	return (index);
}
