/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:26:05 by ifreire-          #+#    #+#             */
/*   Updated: 2022/04/20 01:55:28 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<stdarg.h>
# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>
# include<limits.h>

// Main Function //

int				ft_printf(const char *txt, ...);
// Conversion Functions 
int				s_printf(char *str);
int				c_printf(char a);
unsigned long	p_printf(unsigned long d);
int				d_printf(int d);
int				u_printf(unsigned int d);
int				hex65_printf(int d);
int				hex97_printf(int d);

// Auxiliary functions  //

int				ft_size_hex(unsigned int d);
int				ft_itoaalt(int n);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *b, int c, size_t len);

#endif
