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

static t_orgi      save_this(const char *format, int nargs)
{
    t_orgi      args;

    args.type = format[nargs - 1];
    return (args);
}

static int      count_args(const char *format)
{
    char    *all_possible;
    int     i;

    i = 0;
    all_possible = "cspdiouxX";
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
            params = save_this(format, nargs);
            done += parse_this(args, params);
            format += nargs - 1;
        }
        format++;
    }
    return (done);
}