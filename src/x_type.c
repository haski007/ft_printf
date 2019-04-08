/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:15:28 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/05 20:06:07 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char         *add_0x(char *str)
{
    char    *res;

    res = ft_strjoin("0x", str);
    free(str);
    return(res);
}

char                *x_type(va_list var, t_orgi *params)
{
    char    *str;
    int     i;

    i = -1;
    if (params->l)
        str = itoa_base(va_arg(var, unsigned long), 16);
    else if (params->ll)
        str = itoa_base(va_arg(var, unsigned long long), 16);
    else if (params->h)
        str = u_itoa_base(va_arg(var, unsigned short int), 16);
    else if (params->hh)
        str = u_itoa_base(va_arg(var, unsigned char), 16);
    else 
        str = itoa_base(va_arg(var, unsigned int), 16);
    str = implement_precision(str, params);
    if (params->flag == '#' && str[ft_strlen(str) - 1] != '0')
        str = add_0x(str);
    if (params->type == 'x')
       while(str[++i])
           if (str[i] > 64 && str[i] < 91)
                str[i] += 32;
    str = implement_width(str, params->width, params);
    return (str);
}
