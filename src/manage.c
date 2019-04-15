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

static char         *implement_minus(char *str, long long int nb, t_orgi *params)
{
    char *res;

    res = NULL;
    if (nb < 0)
    {
        res = ft_strjoin("-", str);
        free(str);
    }
    else
        res = str;
    return (res);
}

char                *implement_sign(char *str, long long int nb, t_orgi *params)
{
    char *res;

    res = NULL;
    str = (params->zero) ? implement_width(str, params->width - 1, params) : str;
    if (params->plus && nb > -1)
    {
        res = ft_strjoin("+", str);
        free(str);
    }
    else if (params->space && nb > -1)
    {
        res = ft_strjoin(" ", str);
        free(str);
    }
    else
        res = str;
    res = implement_minus(res, nb, params);
    return (res);
}

char                *percent_manages(t_orgi *params)
{
    char        *str;
    
    str = ft_strdup("%");
    str = implement_width(str, params->width, params);
    str = implement_precision(str, params);
    return (str);
}
