/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:35:28 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/18 19:35:36 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char        *paste_start(char *str, char c)
{
    char    *tmp;
    int     len;
    int     i;

    i = 0;
    tmp = (char*)malloc(sizeof(char) * (len = ft_strlen(str) + 2));
    tmp[len] = '\0';
    tmp[0] = c;
    while (++i < len)
        tmp[i] = str[i - 1];
    return(tmp);
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
    tmp = ft_strjoin("0x", str);
    free(str);
    tmp = implement_width(tmp, params->width, params);
    return (tmp);
}

char         *f_type(va_list var, t_orgi *params)
{
    char    *str;
    char    *tmp;
    
    if (params->L == 1)
        str = floatoa(va_arg(var, long double), params->precision);
    else
        str = floatoa(va_arg(var, double), params->precision);
    if (str[0] != '-' && params->flag == '+')
        str = paste_start(str, '+');
    tmp = str;
    free(str);
    tmp = implement_width(str, params->width, params);
    return (tmp);
}