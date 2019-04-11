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

char                *implement_plus(long long int nb, t_orgi *params)
{
    char *str;
    char *res;

    res = NULL;
    str = ft_itoa(nb);
    str = implement_precision(str, params);
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
