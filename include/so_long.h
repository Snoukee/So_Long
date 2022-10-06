/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:36:01 by ifreire-          #+#    #+#             */
/*   Updated: 2022/04/24 20:14:26 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<string.h>
# include<stdarg.h>
# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>
# include<limits.h>
# include<mlx.h>
# include<string.h>

// Map Struct //
typedef struct s_map {
	void	*mlx;
	void	*win;
	void	*wall;
	void	*player1;
	void	*player2;
	void	*player3;
	void	*player4;
	void	*player5;
	void	*player6;
	void	*player7;
	void	*player8;
	void	*player9;
	void	*player0;
	void	*enemy1;
	void	*portal1;
	void	*portal4;
	void	*vault;
	void	*floor;
	char	**mapline;
	int		str;
	int		arr;
	int		x_t;
	int		y_t;
	int		x;
	int		y;
	int		check_c;
}				t_map;

typedef struct s_new {
	int		x;
	int		y;
	int		i;
	int		checker;
	int		lsize;
	int		lzero;
	int		exit;
	int		player;
	int		col;
	char	**map;
	char	*line;
	char	*lin2;
}				t_new;

// Main Function //
int		ft_string_size(char **mapline, int i_array);
int		ft_boundaries_size(int size, char **mapline);
int		ft_checker(char *line);
int		ft_map_invalid(int size, int i, char **mapline);
char	**ft_map_valid(int size, int i, char **mapline);
int		ft_map_boundaries(int size, int i, char **mapline);
int		esc_close(int keycode, t_map *map);
void	mlx_image(t_map *map, int array_size, int string_size);
void	mlx_create(t_map *map, int array_size, int string_size, char **mapline);
void	ft_mlx(char **mapline, int array_size, int string_size);
int		ft_map_checker(int fd, char *argv);
int		ft_map_counter(int size, int i, char**mapline);
int		ft_keycode0(t_map *map, int i);
int		ft_keycode1(t_map *map, int i);
int		ft_keycode2(t_map *map, int i);
int		ft_keycode13(t_map *map, int i);
int		ft_destroyer(t_map *map);
int		ft_size_array(int fd);
void	ft_create_extra(t_map *map, char **mapline);

// Next Line Function //
char	*get_next_line(int fd);
char	*next_line(char *line, char *buffer, int size_line);
char	*give_buffer_text(char *buffer, char *line, int i);
char	*ft_itoa(int n);
int		check(char *buffer);
int		get_size_line(char *buffer);
int		ft_map_check(char *line);

#endif