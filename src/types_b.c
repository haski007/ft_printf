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
/*
static char *make_me_adress(char *str)
{
    char    *adress;
    int     i;

    i = -1;
    adress = ft_strnew(ft_strlen(str) + 2);
    adress[0] = '0';
    adress[1] = 'x';
    while (str[++i])
        adress[i + 2] = str[i];
    return (adress);
}
*/
int         x_type(int nb, t_orgi *params)
{
    char    *str;
    int     i;
    char    *tmp;

    i = -1;
    str = itoa_base(nb, 16);
    tmp = str;
    free(str);
    if (params->type == 'x')
    {
       while(tmp[++i])
           if (tmp[i] > 64 && str[i] < 91)
                tmp[i] += 32;
    }
    tmp = implement_width(str, params->width);
    ft_putstr(tmp);
    return (ft_strlen(tmp));
}

int         p_type(va_list var, t_orgi *params)
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
    tmp = implement_width(tmp, params->width);
    ft_putstr(tmp);
    return (ft_strlen(tmp));
}

int         f_type(va_list var, t_orgi *params)
{
    char    *str;
    char    *tmp;
    
    if (params->L == 1)
        str = floatoa(va_arg(var, long double), params->precision);
    else
        str = floatoa(va_arg(var, double), params->precision);
    tmp = str;
    free(str);
    tmp = implement_width(str, params->width);
    ft_putstr(tmp);
    return (ft_strlen(tmp));
}