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

char                get_modifier(const char *format, int nargs)
{
    if (format[nargs - 2] == 'h')
    {
        if (format[nargs - 3] != 'h')
            return ('h');
        else if (format[nargs - 3] == 'h')
            return ('H');
    }
    else if (format[nargs - 2] == 'l')
    {
        if (format[nargs - 3] != 'l')
            return ('l');
        else if (format[nargs - 3] == 'l')
            return ('D');
    }
    return (0);
}

int     parse_this(va_list var, t_orgi params)
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
    return (len);
}