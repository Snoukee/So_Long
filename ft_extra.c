/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:53:19 by ifreire-          #+#    #+#             */
/*   Updated: 2022/04/24 20:34:14 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "include/ft_printf.h"

int	ft_destroyer(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit(1);
}

int	ft_size_array(int fd)
{
	t_new	new;

	ft_memset(&new, 0, (sizeof(new)));
	new.lin2 = get_next_line(fd);
	if (new.lin2 == NULL)
	{
		ft_printf("Error\nEmpty Map\n");
		exit(1);
	}
	while (new.lin2)
	{
		new.lin2 = get_next_line(fd);
		new.y++;
	}
	return (new.y);
}

void	ft_create_extra(t_map *map, char **mapline)
{
	if (mapline[map->arr][map->str] == 'E')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->floor, \
		map->str * 32, map->arr * 32);
		mlx_put_image_to_window(map->mlx, map->win, \
		map->portal4, map->str * 32, map->arr * 32);
	}
	if (mapline[map->arr][map->str] == '0')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->floor, \
		map->str * 32, map->arr * 32);
		mlx_put_image_to_window (map->mlx, map->win, map->floor, \
		map->str * 32, map->arr * 32);
	}
	if (mapline[map->arr][map->str] == 'N')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->floor, \
		map->str * 32, map->arr * 32);
		mlx_put_image_to_window (map->mlx, map->win, map->enemy1, \
		map->str * 32, map->arr * 32);
	}
}

void	mlx_image(t_map *map, int array_size, int string_size)
{
	int	z;

	z = 32;
	map->win = mlx_new_window(map->mlx, string_size * 32, array_size * 32, "z");
	map->wall = mlx_xpm_file_to_image(map->mlx, "./mlx/wall.xpm", &z, &z);
	map->player1 = mlx_xpm_file_to_image(map->mlx, "./mlx/player1.xpm", &z, &z);
	map->player2 = mlx_xpm_file_to_image(map->mlx, "./mlx/player2.xpm", &z, &z);
	map->player3 = mlx_xpm_file_to_image(map->mlx, "./mlx/player3.xpm", &z, &z);
	map->player4 = mlx_xpm_file_to_image(map->mlx, "./mlx/player4.xpm", &z, &z);
	map->player5 = mlx_xpm_file_to_image(map->mlx, "./mlx/player5.xpm", &z, &z);
	map->player6 = mlx_xpm_file_to_image(map->mlx, "./mlx/player6.xpm", &z, &z);
	map->player7 = mlx_xpm_file_to_image(map->mlx, "./mlx/player7.xpm", &z, &z);
	map->player8 = mlx_xpm_file_to_image(map->mlx, "./mlx/player8.xpm", &z, &z);
	map->player9 = mlx_xpm_file_to_image(map->mlx, "./mlx/player9.xpm", &z, &z);
	map->player0 = mlx_xpm_file_to_image(map->mlx, "./mlx/player0.xpm", &z, &z);
	map->enemy1 = mlx_xpm_file_to_image(map->mlx, "./mlx/enemy1.xpm", &z, &z);
	map->portal4 = mlx_xpm_file_to_image(map->mlx, "./mlx/portal4.xpm", &z, &z);
	map->vault = mlx_xpm_file_to_image(map->mlx, "./mlx/vault.xpm", &z, &z);
	map->floor = mlx_xpm_file_to_image(map->mlx, "./mlx/floor.xpm", &z, &z);
}
