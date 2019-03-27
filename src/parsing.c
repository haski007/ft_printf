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

void        null_all(t_orgi *params)
{
    ft_bzero(params, sizeof(t_orgi));
    params->precision = 6;
}

char        *implement_width(char *str, int width, t_orgi *params)
{
    char    *tmp;
    int     len;

    str = ft_strdup(str);
    if (width && (len = width - ft_strlen(str)) > 0)
    {
        tmp = ft_strnew(len);
        if (params->flag == '-')
            str = ft_strcat(str, ft_memset(tmp, (params->flag == '0') ? '0' : ' ', len));
        else    
            str = ft_strcat(ft_memset(tmp, (params->flag == '0') ? '0' : ' ', len), str);
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

char                 *parse_this(va_list var, t_orgi *params)
{
    char    *res;

    res = NULL;
    if (params->type == 'c')
        res = c_type(va_arg(var, int), params);
    else if (params->type == 's')
        res = s_type(va_arg(var, char*), params);
    else if (params->type == 'd' || params->type == 'i')
        res = d_type(var, params);
    else if (params->type == 'o')
        res = o_type(va_arg(var, int), params);
    else if (params->type == 'u')
        res = u_type(va_arg(var, int), params);
    else if (params->type == 'x' || params->type == 'X')
        res = x_type(va_arg(var, int), params);
    else if (params->type == 'p')
        res = p_type(var, params);
    else if (params->type == 'f')
        res = f_type(var, params);
    ft_putstr(res);
    return (res);
}