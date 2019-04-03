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

static void       check_precision(const char *format, int nargs, t_orgi *params)
{
    char *str;

    str = ft_strndup(format, nargs);
    while (str[--nargs])
    {
        if (str[nargs] == '.')
        {
            params->dot = 1;
            params->precision = ft_atoi(str + 1 + nargs);
        }
    }
}

static void      save_this(const char *format, int nargs, t_orgi *params)
{
    if (*format == '%')
        return ;
    null_all(params);
    params->type = format[nargs - 1];
    params->flag = (ft_strchr("#0-+ ", format[0])) ? format[0] : 0;
    check_precision(format, nargs, params);
    get_width(format, nargs, params);
    get_modifier(format, nargs, params);
}

static int      count_args(const char *format)
{
    char    *all_possible;
    int     i;

    if (*format == '%')
        return(0);
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
    va_list     args;
    int         nargs;
    t_orgi      params;
    int         done;

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
            save_this(format, nargs, &params);
            done += ft_strlen(parse_this(args, &params, format));
            format += (format[0] == '%') ? params.len * 2 - 2: nargs - 1;
        }
        format++;
    }
    printf("Precision = %d\n", params.precision);
    printf("Width = %d\n", params.width);
    return (done);
}