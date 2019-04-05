/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:09:02 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/05 20:05:32 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char                *implement_plus(long long int nb, t_orgi *params)
{
    char *str;
    char *res;

    res = NULL;
    str = ft_itoa(nb);
    str = implement_precision(str, params);
    if (params->flag == '+' && nb > -1)
    {
        res = ft_strjoin("+", str);
        free(str);
    }
    else if (params->flag == ' ' && nb > -1)
    {
        res = ft_strjoin(" ", str);
        free(str);
    }
    return (res);
}

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
