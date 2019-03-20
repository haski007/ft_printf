/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 13:52:38 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/10 13:52:39 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void                get_modifier(const char *format, int nargs, t_orgi params)
{
    if (format[nargs - 2] == 'h')
    {
        if (format[nargs - 3] != 'h')
            params.h = 1;
        else if (format[nargs - 3] == 'h')
            params.hh = 1;
    }
    else if (format[nargs - 2] == 'l')
    {
        if (format[nargs - 3] != 'l')
            params.l = 1;
        else if (format[nargs - 3] == 'l')
            params.ll = 1;
    }
    else if (format[nargs - 2] == 'L')
        params.L = 1;
    return (0);
}

int                  parse_this(va_list var, t_orgi params)
{
    int     len;

    len = 0;
    if (params.type == 'c')
        len += c_type(va_arg(var, int));
    else if (params.type == 's')
        len += s_type(va_arg(var, char*));
    else if (params.type == 'd' || params.type == 'i')
        len += d_type(va_arg(var, int));
    else if (params.type == 'o')
        len += o_type(va_arg(var, int));
    else if (params.type == 'u')
        len += u_type(va_arg(var, int));
    else if (params.type == 'x' || params.type == 'X')
        len += x_type(va_arg(var, int), params.type);
    else if (params.type == 'p')
        len += p_type(var);
    else if (params.type == 'f')
        len += f_type(var);
    return (len);
}