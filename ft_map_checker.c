/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:18:30 by ifreire-          #+#    #+#             */
/*   Updated: 2022/04/26 20:41:17 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "include/ft_printf.h"

int	ft_string_size(char **mapline, int i_array)
{
	int	i;

	i = 0;
	while (mapline[i_array][i])
	{
		i++;
	}
	return (i);
}

int	ft_boundaries_size(int size, char **mapline)
{
	t_new	new;

	new.y = 1;
	new.lzero = ft_string_size(mapline, 0);
	while (new.y < size - 1)
	{
		new.lsize = ft_string_size(mapline, new.y);
		if (new.lsize != new.lzero)
		{
			ft_printf("Each line on the map must have \
			the same size: Line %d\n", new.y + 1);
			return (1);
		}
		new.y++;
	}
	new.lsize = ft_string_size(mapline, new.y);
	if (new.lsize != new.lzero - 1)
	{
		ft_printf("Each line on the map must have \
		the same size: Line %d\n", new.y + 1);
		return (1);
	}
	return (0);
}

int	ft_checker(char *line)
{
	static int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C' && line[i] \
			!= 'E' && line[i] != 'P' && line[i] != '\n' && line[i] != 'N')
		{
			ft_printf("Map Invalid (PS:Map should only contain the \
			following chars 0,1,C,E,P & (N))\n");
			return (-1);
		}
		i++;
	}
	return (i);
}

int	ft_map_invalid(int size, int i, char **mapline)
{
	t_new	new;

	ft_memset(&new, 0, (sizeof(new)));
	while (size > new.y)
	{
		while (mapline[new.y][new.x] && i > new.x)
		{
			if (mapline[new.y][new.x] == 'E')
				new.exit++;
			else if (mapline[new.y][new.x] == 'P')
				new.player++;
			else if (mapline[new.y][new.x] == 'C')
				new.col++;
			new.x++;
		}
		new.x = 0;
		new.y++;
	}
	if (new.exit == 0 || new.col == 0 || new.player == 0)
	{
		ft_printf("Map must have at least 1 of each:\n%d:Exit(s)\n%d:Player(s) \
		\n%d:Collection(s)\n", new.exit, new.player, new.col);
		return (1);
	}
	return (0);
}

char	**ft_map_valid(int size, int i, char **mapline)
{
	t_new	new;

	ft_memset(&new, 0, (sizeof(new)));
	while (size > new.y)
	{
		while (mapline[new.y][new.x] && i > new.x)
		{
			if (mapline[new.y][new.x] == 'P')
				new.player++;
			if (new.player > 1 && mapline[new.y][new.x] == 'P')
				mapline[new.y][new.x] = '0';
			new.x++;
		}
		new.x = 0;
		new.y++;
	}		
	return (mapline);
}
