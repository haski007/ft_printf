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
    int             len;
    char            h;
    char            hh;
    char            l;
    char            ll;
    char            L;
    char            dot;
    unsigned int    precision;
    unsigned int    width;
    char            flag;
	char            type;
}					t_orgi;

int					ft_printf(const char *format, ...);
char			    *parse_this(va_list var, t_orgi *params, const char *format);
char			    *s_type(char *str, t_orgi *params);
char			    *c_type(char c, t_orgi *params);
char			    *d_type(va_list var, t_orgi *params);
char			    *o_type(va_list var, t_orgi *params);
char			    *u_type(t_orgi *params, va_list var);
char			    *x_type(va_list var, t_orgi *params);
char			    *p_type(va_list var, t_orgi *params);
char                *f_type(va_list var, t_orgi *params);
void                get_modifier(const char *format, int nargs, t_orgi *params);
void                get_width(const char *format, int nargs, t_orgi *params);
char                *implement_width(char *str, int width, t_orgi *params);
void                null_all(t_orgi *params);
char                *paste_start(char *str, char c);
char                *extra_manages(const char *format, t_orgi *params);

#endif
