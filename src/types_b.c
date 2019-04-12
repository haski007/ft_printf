/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:35:28 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/05 20:06:37 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char        *paste_start(char *str, char c)
{
    char *res;

    res = NULL;
    if (c == '+')
        res = ft_strjoin("+", str);
    else if (c == ' ')
        res = ft_strjoin(" ", str);
    else if (c == '0')
        res = ft_strjoin("0", str);
    free(str);
    return (res);
}


char         *p_type(va_list var, t_orgi *params)
{
    char    *str;
    char    *tmp;
    int     i;

    i = -1;
    str = itoa_base(va_arg(var, long long unsigned int), 16);
    while(str[++i])
        str[i] = ft_tolower(str[i]);
    str = implement_precision(str, params);
    tmp = ft_strjoin("0x", str);
    free(str);
    tmp = implement_width(tmp, params->width, params);
// exit_func();
    return (tmp);
}

char         *f_type(va_list var, t_orgi *params)
{
    char    *str;
    char    *tmp;
    
    if (params->L == 1)
    {
        if (params->precision)
            str = floatoa(va_arg(var, long double), params->precision);
        else
            str = floatoa(va_arg(var, long double), 6);
    }
    else
    {
        if (params->precision)
            str = floatoa(va_arg(var, double), params->precision);
        else
            str = floatoa(va_arg(var, double), 6);
    }
    if (str[0] != '-' && (params->plus == '+' || params->plus == ' '))
        str =  (params->plus == '+') ? paste_start(str, '+') : paste_start(str, ' ');
    tmp = implement_width(str, params->width, params);
    return (tmp);
}