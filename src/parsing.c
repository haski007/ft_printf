/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 13:52:38 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/05 20:08:27 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char                *implement_precision(char *str, t_orgi *params)
{
    char    *tmp;
    char    *res;
    int     len;

    if (params->precision && (len = params->precision - ft_strlen(str)) > 0)
    {
        tmp = ft_strnew(len);
        res = ft_strjoin(ft_memset(tmp, '0', len), str);
        free(tmp);
        free(str);
        return (res);
    }
    return (str);
}

char        *implement_width(char *str, int width, t_orgi *params)
{
    char    *tmp;
    char    *res;
    int     len;

    if (width && (len = width - ft_strlen(str)) > 0)
    {
        tmp = ft_strnew(len);
        if (params->minus == 1)
            res = ft_strjoin(str, ft_memset(tmp, (params->flag == '0' && !params->dot) ? '0' : ' ', len));
        else    
            res = ft_strjoin(ft_memset(tmp, (params->flag == '0' && !params->dot) ? '0' : ' ', len), str);
        free(tmp);
        free(str);
        return (res);
    }
    return (str);
}

void        get_width(const char *format, int nargs, t_orgi *params)
{
    char    *str;
    char    *tmp;
    int     i;

    i = 0;
    str = ft_strndup(format, nargs);
    tmp = str;
    free(str);
    while (i < nargs)
    {
        if (tmp[i] > 47 && tmp[i] < 58 && tmp[i - 1] != '.')
        {
            params->width = ft_atoi(tmp + i);
            break;
        }
        i++;
    }
}

void        get_modifier(const char *format, int nargs, t_orgi *params)
{
    if (format[nargs - 2] == 'h')
    {
        if (format[nargs - 3] != 'h')
            params->h = 1;
        else if (format[nargs - 3] == 'h')
            params->hh = 1;
    }
    else if (format[nargs - 2] == 'l')
    {
        if (format[nargs - 3] != 'l')
            params->l = 1;
        else if (format[nargs - 3] == 'l')
            params->ll = 1;
    }
    else if (format[nargs - 2] == 'L')
        params->L = 1;
}

int                 parse_this(va_list var, t_orgi *params, const char *format)
{
    char    *res;
    int     len;

    if (*format == '%')
        res = extra_manages(format, params);
    else if (params->type == 'c')
        res = c_type(va_arg(var, int), params);
    else if (params->type == 's')
        res = s_type(va_arg(var, char*), params);
    else if (params->type == 'd' || params->type == 'i')
        res = d_type(var, params);
    else if (params->type == 'o')
        res = o_type(var, params);
    else if (params->type == 'u')
        res = u_type( params, var);
    else if (params->type == 'x' || params->type == 'X')
        res = x_type(var, params);
    else if (params->type == 'p')
        res = p_type(var, params);
    else if (params->type == 'f')
        res = f_type(var, params);
    else
        return(0);
    ft_putstr(res);
    len = ft_strlen(res);
    free(res);
    return (len);
}
