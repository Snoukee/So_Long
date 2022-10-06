/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:07:54 by ifreire-          #+#    #+#             */
/*   Updated: 2022/04/24 19:53:39 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "include/ft_printf.h"

int	ft_map_counter(int size, int i, char **mapline)
{
	t_new	new;

	ft_memset(&new, 0, (sizeof(new)));
	while (size > new.y)
	{
		while (mapline[new.y][new.x] && i > new.x)
		{
			if (mapline[new.y][new.x] == 'C')
				new.col++;
			new.x++;
		}
		new.x = 0;
		new.y++;
	}
	return (new.col);
}

int	ft_map_bounds(int size, int i, char **mapline)
{
	t_new	new;

	ft_memset(&new, 0, (sizeof(new)));
	while (mapline[0][new.x] && i > new.x)
	{
		if (mapline[0][new.x] != '1' || mapline[size - 1][new.x] != '1')
		{
			ft_printf("Map must be closed by walls: line 0 or \
			line %d ", size - 1);
			return (1);
		}
		new.x++;
	}
	return (0);
}

int	ft_map_boundaries(int size, int i, char **mapline)
{
	t_new	new;

	ft_memset(&new, 0, (sizeof(new)));
	while (size > new.y)
	{
		while (mapline[new.y][new.x] && i > new.x)
		{
			if (mapline[new.y][0] != '1' || mapline[new.y][i - 1] != '1')
				return (ft_printf("Map must be closed by walls: \
				Line %d", new.y + 1));
			new.x++;
		}
		new.x = 0;
		new.y++;
	}
	new.checker = ft_boundaries_size(size, mapline);
	new.checker += ft_map_bounds(size, i, mapline);
	if (new.checker != 0)
		return (1);
	return (0);
}

int	ft_map_checker(int fd, char *argv)
{
	t_new	new;

	ft_memset(&new, 0, (sizeof(new)));
	new.i = ft_size_array(fd);
	new.map = (char **)malloc(sizeof (char *) * (new.i));
	close(fd);
	fd = open(argv, O_RDONLY);
	new.line = get_next_line(fd);
	while (new.line)
	{
		new.x = ft_checker(new.line);
		if (new.x == -1)
			return (0);
		new.map[new.y] = new.line;
		new.y++;
		new.line = get_next_line(fd);
	}
	new.checker = ft_map_boundaries(new.y, new.x, new.map);
	new.checker += ft_map_invalid(new.y, new.x, new.map);
	if (new.checker != 0)
		return (1);
	new.map = ft_map_valid(new.y, new.x, new.map);
	ft_mlx(new.map, new.y, new.x);
	free(new.map);
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		if (argv[1][i - 4] == '.' && argv[1][i - 3] == 'b' &&
		argv[1][i - 2] == 'e' && argv[1][i - 1] == 'r')
		{
			fd = open(argv[1], O_RDONLY);
			ft_map_checker(fd, argv[1]);
		}
		else
			return (ft_printf("Error\nThe map must be *.ber"));
	}
	return (0);
}
