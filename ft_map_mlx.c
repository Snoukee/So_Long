/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:17:48 by ifreire-          #+#    #+#             */
/*   Updated: 2022/04/25 20:08:40 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "include/ft_printf.h"

int	esc_close(int keycode, t_map *map)
{
	static int	steps;
	static int	i;
	char		*step;

	steps++;
	if (steps != 0)
	{
		step = ft_itoa(steps);
		mlx_put_image_to_window(map->mlx, map->win, map->wall, 0, 0);
		mlx_string_put(map->mlx, map->win, 6, 4, 10, step);
	}
	if (keycode == 53)
		ft_destroyer(map);
	else if (keycode == 2 || keycode == 124)
		i = ft_keycode2(map, i);
	else if (keycode == 0 || keycode == 123)
		i = ft_keycode0(map, i);
	else if (keycode == 1 || keycode == 125)
		i = ft_keycode1(map, i);
	else if (keycode == 13 || keycode == 126)
		i = ft_keycode13(map, i);
	ft_printf("Steps:%d\n", steps);
	return (steps);
}

void	ft_create(t_map *map, char **mapline)
{
	if (mapline[map->arr][map->str] == '1')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->floor, \
		map->str * 32, map->arr * 32);
		mlx_put_image_to_window(map->mlx, map->win, map->wall, \
		map->str * 32, map->arr * 32);
	}
	if (mapline[map->arr][map->str] == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->floor, \
		map->str * 32, map->arr * 32);
		mlx_put_image_to_window(map->mlx, map->win, map->player3, \
		map->str * 32, map->arr * 32);
		map->x = map->str;
		map->y = map->arr;
	}
	if (mapline[map->arr][map->str] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->floor, \
		map->str * 32, map->arr * 32);
		mlx_put_image_to_window(map->mlx, map->win, map->vault, \
		map->str * 32, map->arr * 32);
	}
	ft_create_extra(map, mapline);
}

void	mlx_create(t_map *map, int array_size, int string_size, char **mapline)
{
	while (map->arr < array_size)
	{
		while (map->str < string_size)
		{
			ft_create(map, mapline);
		map->str++;
		}
	map->str = 0;
	map->arr++;
	}
}

void	ft_mlx(char **mapline, int array_size, int string_size)
{
	t_map	map;

	ft_memset(&map, 0, (sizeof(map)));
	map.x_t = string_size;
	map.y_t = array_size;
	map.mapline = mapline;
	map.mlx = mlx_init();
	map.check_c = ft_map_counter(array_size, string_size, mapline);
	ft_printf("Collect '%d' coins and use the portal to WIN!\n", map.check_c);
	if (map.mlx != 0)
	{
		mlx_image(&map, array_size, string_size);
		mlx_create(&map, array_size, string_size, mapline);
	}
	mlx_hook(map.win, 17, 1L << 17, ft_destroyer, &map);
	mlx_key_hook(map.win, esc_close, &map);
	mlx_loop(map.mlx);
}
