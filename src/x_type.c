/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:15:28 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/27 18:15:32 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char         *add_0x(char *str)
{
    char    *res;
    int     i;
    int     len;

    i = 1;
    res = (char*)malloc(sizeof(char) * (len = ft_strlen(str) + 3));
    res[len] = '\0';
    res[0] = '0';
    res[1] = 'X';
    while (++i < len)
        res[i] = str[i - 2];
    return(res);
}

char                *x_type(int nb, t_orgi *params)
{
    char    *str;
    int     i;
    char    *tmp;

    i = -1;
    str = itoa_base(nb, 16);
    if (params->flag == '#')
        str = add_0x(str);
    tmp = str;
    free(str);
    if (params->type == 'x')
    {
       while(tmp[++i])
           if (tmp[i] > 64 && str[i] < 91)
                tmp[i] += 32;
    }
    tmp = implement_width(str, params->width, params);
    return (tmp);
}