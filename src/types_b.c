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

int         x_type(int nb, char reg)
{
    char    *str;
    int     i;

    i = -1;
    str = itoa_base(nb, 16);
    if (reg == 'X')
        ft_putstr(str);
    else
    {
       while(str[++i])
           if (str[i] > 64 && str[i] < 91)
                str[i] += 32;
       ft_putstr(str);
    }
    return (ft_strlen(str));
}

int         p_type(va_list var)
{
    char    *str;
    char    *adress;
    int     adresslen;
    int     i;

    i = 0;
    str = itoa_base(va_arg(var, long long unsigned int), 16);
    while(str[++i])
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
    adress = ft_strjoin("0x", str);
    ft_putstr(adress);
    adresslen = ft_strlen(adress);
    free(str);
    free(adress);
    return (adresslen);
}

int         f_type(va_list var, t_orgi *params)
{
    char    *str;
    char    *tmp;
    int     len;
    
    if (params->L == 1)
        str = floatoa(va_arg(var, long double), params->precision);
    else
        str = floatoa(va_arg(var, double), params->precision);
    if ((len = params->width - ft_strlen(str)) > 0)
    {
        tmp = ft_strnew(len);
        tmp = ft_strcat(ft_memset(tmp, ' ', len), str);
    }
    ft_putstr(tmp);
    len = ft_strlen(tmp);
    free(str);
    return (len);
}