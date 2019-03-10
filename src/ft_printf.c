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

static int      count_args(char *format)
{
    int     i;
    int     count;

    i = -1;
    count = 0;
    while (format[++i])
    {
        if(format[i] == '%')
            count++;
    }
    return (count);
}

int             ft_printf(const char *format, ...)
{
    va_list args;
    int     done;

    done = 0;
    if ((count_args(format)) == 0)
        ft_putstr(format);
    va_start(args, format);
    while (format)
    {
        if (*format != '%')
        {
            ft_putchar(*format);
            done++;
        }
        else
        {
                   
        }
        format++;
    }
   return (0);
}