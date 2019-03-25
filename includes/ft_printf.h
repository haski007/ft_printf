/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:39:39 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/19 16:20:27 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct		s_orgi
{
    char            h;
    char            hh;
    char            l;
    char            ll;
    char            L;
    char            dot;
    unsigned int    precision;
    unsigned int    width;
	char            type;
}					t_orgi;

int					ft_printf(const char *format, ...);
int					parse_this(va_list var, t_orgi *params);
int					s_type(char *str, t_orgi *params);
int					c_type(char c);
int					d_type(int nb, t_orgi *params);
int					o_type(int nb);
int					u_type(unsigned int nb);
int					x_type(int nb, t_orgi *params);
int					p_type(va_list var, t_orgi *params);
int                 f_type(va_list var, t_orgi *params);
void                get_modifier(const char *format, int nargs, t_orgi *params);
void                get_width(const char *format, int nargs, t_orgi *params);
char                *implement_width(char *str, int width);

#endif
