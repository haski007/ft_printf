/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:50:43 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/18 17:50:46 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char             *u_type( t_orgi *params, va_list var)
{
    char    *str;

    if (params->l)
        str = ft_itoa(va_arg(var, unsigned long));
    else if (params->ll)
        str = ft_itoa(va_arg(var, unsigned long long));
    else 
        str = ft_itoa(va_arg(var, int));
    str = implement_width(str, params->width, params);
    return (str);
}

char             *o_type(va_list var, t_orgi *params)
{
    char            *str;

    if (params->l)
        str = itoa_base(va_arg(var, unsigned long), 8);
    else if (params->ll)
        str = itoa_base(va_arg(var, unsigned long long), 8);
    else 
        str = itoa_base(va_arg(var, int), 8);
    if (params->flag == '#')
        str = paste_start(str, '0');
    str = implement_width(str, params->width, params);
    return(str);
}

char             *d_type(va_list var, t_orgi *params)
{
    char    *str;
    char    *tmp;
    long long int     nb;

    if (params->l)
        nb = va_arg(var, unsigned long);
    else if (params->ll)
        nb = va_arg(var, unsigned long long);
    else 
        nb = va_arg(var, int);
    if (nb == 0 && params->flag == '+')
        str = ft_strdup("+0");
    else if ((params->flag == '+' || params->flag == ' ') && nb > -1)
    {
        str = ft_itoa(-nb);
        str[0] = (params->flag == '+') ? '+' : ' ';
    }
    else
        str = ft_itoa(nb);
    tmp = str;
    free(str);
    tmp = implement_width(str, params->width, params);
    return (tmp);
}

char            *s_type(char *str, t_orgi *params)
{
    if(!str)
        return (0);
    if (params->dot)
        str = ft_strndup(str, params->precision);
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
