/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:02:34 by ifreire-          #+#    #+#             */
/*   Updated: 2022/04/24 19:52:18 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "include/ft_printf.h"

void	ft_floor0(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->floor, \
	map->x * 32, map->y * 32);
	map->x = map->x - 1;
}

void	ft_wall0(t_map *map)
{
	map->x = map->x + 1;
	mlx_put_image_to_window(map->mlx, map->win, map->player3, \
	map->x * 32, map->y * 32);
}

int	ft_nospace0(t_map *map, int i)
{
	if (i == 0)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->player9, \
		map->x * 32, map->y * 32);
		i++;
	}
	else if (i == 1)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->player0, \
		map->x * 32, map->y * 32);
		i = 0;
	}
	if (map->mapline[map->y][map->x] == 'N')
		ft_destroyer(map);
	return (i);
}

int	ft_keycode0(t_map *map, int i)
{
	ft_floor0(map);
	if (map->mapline[map->y][map->x] == '1')
		ft_wall0(map);
	else if (map->mapline[map->y][map->x] == 'E' && map->check_c > 0)
		ft_wall0(map);
	else if (map->mapline[map->y][map->x] == 'E' && map->check_c <= 0)
		ft_destroyer(map);
	else
		i = ft_nospace0(map, i);
	if (map->mapline[map->y][map->x] == 'C')
	{
		map->mapline[map->y][map->x] = '0';
		map->check_c = map->check_c - 1;
	}
	return (i);
}
