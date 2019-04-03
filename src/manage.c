/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:09:02 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/03 17:09:08 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char         *many_percent(const char *format, t_orgi *params)
{
    char        *str;
    int         i;
    int         n;

    n = 0;
    i = 0;
    while (format[i] == '%')
    {
        if (i % 2 == 0)
            n++;
        i++;
    }
    str = ft_strnew(n);
    str = ft_memset(str, '%', n);
    params->len = n;
    return (str);
}

char                *extra_manages(const char *format, t_orgi *params)
{
    char *str;

    if (format[0] == '%')
        str = many_percent(format, params);
    else
        return (0);
    return (str);
}