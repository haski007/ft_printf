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
    int     i;

    i = 0;
    str = itoa_base(va_arg(var, long long unsigned int), 16);
    while(str[++i])
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
    adress = ft_strjoin("0x", str);
    free(str);
    ft_putstr(adress);
    return (ft_strlen(adress));
}

int         f_type(va_list var)
{
    
}