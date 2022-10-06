# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 15:21:04 by ifreire-          #+#    #+#              #
#    Updated: 2022/04/26 20:46:58 by ifreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OBJS_Wildcard	= $(wildcard *.c)

SRC				= so_long.c \
				ft_keycode0.c \
				ft_keycode1.c \
				ft_keycode2.c \
				ft_keycode13.c \
				ft_map_mlx.c \
				ft_map_checker.c \
				ft_extra.c \
				srcs/get_next_line.c \
				srcs/get_next_line_utils.c \
				srcs/ft_printf.c \
				srcs/ft_itoa.c \
				srcs/c_printf.c \
				srcs/s_printf.c \
				srcs/p_printf.c \
				srcs/d_printf.c \
				srcs/u_printf.c \
				srcs/hex65_printf.c \
				srcs/hex97_printf.c \
				srcs/ft_size_hex.c \
				srcs/ft_itoaalt.c \
				srcs/ft_strlen.c \
				srcs/ft_strdup.c \
				srcs/ft_memset.c

OBJ			= $(SRC:.c=.o)

CC				= gcc

#CFLAGS			= -Wall -Wextra -Werror

NAME			= so_long

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all:			$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -fsanitize=address -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#$(NAME):		$(OBJS_O)
#				ar rcs $(NAME) $(OBJS_O)
#				ranlib $(NAME)

clean:
				rm -f $(OBJ)

fclean: 		clean
				rm -f $(NAME)

re: 			fclean $(NAME)

.PHONY: all clean fclean re
