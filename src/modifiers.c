/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:36:28 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/19 16:36:29 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    get_modifier(const char *format, int nargs, t_orgi params)
{
    if (format[nargs - 2] == 'h')
    {
        if (format[nargs - 3] != 'h')
            params.modifier = 'h';
        else if (format[nargs - 3] == 'h')
            params
    }




}