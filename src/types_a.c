/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:50:43 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/05 20:06:55 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char             *u_type(t_orgi *params, va_list var)
{
    char    *str;

    if (params->l)
        str = ft_itoa(va_arg(var, unsigned long));
    else if (params->ll)
        str = ft_itoa(va_arg(var, unsigned long long));
    else if (params->h)
        str = ft_u_itoa(va_arg(var, unsigned short int));
    else if (params->hh)
        str = ft_u_itoa(va_arg(var, unsigned char));
    else 
        str = ft_itoa(va_arg(var, unsigned int));
    str = implement_width(str, params->width, params);
    str = implement_precision(str, params);
    return (str);
}

char             *o_type(va_list var, t_orgi *params)
{
    char            *str;

    if (params->l)
        str = itoa_base(va_arg(var, unsigned long), 8);
    else if (params->ll)
        str = itoa_base(va_arg(var, unsigned long long), 8);
    else if (params->h)
        str = itoa_base(va_arg(var, unsigned short int), 8);
    else if (params->hh)
        str = itoa_base(va_arg(var, unsigned char), 8);
    else 
        str = itoa_base(va_arg(var, int), 8);
    if (params->flag == '#' && str[ft_strlen(str) - 1] != '0')
        str = paste_start(str, '0');
    str = implement_precision(str, params);
    str = implement_width(str, params->width, params);
    return(str);
}

char             *d_type(va_list var, t_orgi *params)
{
    char                *str;
    char                *tmp;
    long long int       nb;

    if (params->l)
        nb = va_arg(var, long int);
    else if (params->ll)
        nb = va_arg(var, long long int);
    else if (params->h)
        nb = va_arg(var, short int);
    else if (params->hh)
        nb = va_arg(var, signed char);
    else 
        nb = va_arg(var, int);
    if (nb == 0 && params->flag == '+')
        str = "+0";
    str = implement_plus(nb, params);
    str = implement_precision(str, params);
    str = implement_width(str, params->width, params);
    return (str);
}

char            *s_type(char *str, t_orgi *params)
{
    if(!str)
        str = ft_strdup("(null)");
    if (params->dot)
        str = ft_strndup(str, params->precision);
    else
        str = ft_strdup(str);
    str = implement_width(str, params->width, params);
    return (str);
}     

char             *c_type(char c, t_orgi *params)
{
    char    *str;

    str = (char*)malloc(sizeof(char) * 2);
    str[1] = '\0';
    str[0] = c;
    str = implement_width(str, params->width, params);
    return (str);
}

