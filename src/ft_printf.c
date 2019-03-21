/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:55:48 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/10 12:55:51 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_orgi        check_precision(const char *format, int nargs, t_orgi params)
{
    char *str;

    str = ft_strndup(format, nargs);
    while (str[--nargs])
    {
        if (str[nargs] == '.' && str[nargs + 1] > 47
         && str[nargs + 1] < 58)
            params.precision = ft_atoi(str + 1 + nargs);
    }
    return (params);
}

static t_orgi        null_all(t_orgi params)
{
    params.h = 0;
    params.hh = 0;
    params.L = 0;
    params.l = 0;
    params.ll = 0;
    params.precision = 6;
    return (params);
}

static t_orgi      save_this(const char *format, int nargs, t_orgi params)
{

    params.type = format[nargs - 1];
    params = null_all(params);
    if (params.type == 'f')
        params = check_precision(format, nargs, params);
    params = get_width(format, nargs, params);
    params = get_modifier(format, nargs, params);
    return (params);
}

static int      count_args(const char *format)
{
    char    *all_possible;
    int     i;

    i = 0;
    all_possible = "cspdioufxX";
    while (format[i])
    {
        if ((ft_strchr(all_possible, format[i])))
            return (i + 1);
        i++;
    }
    return (0);
}

int             ft_printf(const char *format, ...)
{
    va_list args;
    int     nargs;
    t_orgi  params;
    int     done;

    done = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format != '%')
        {
            ft_putchar(*format);
            done++;
        }
        else
        {
            format++;
            nargs = count_args(format);
            params = save_this(format, nargs, params);
            done += parse_this(args, params);
            format += nargs - 1;
        }
        format++;
    }
    return (done);
}