/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 13:52:38 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/10 13:52:39 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void        parse_this(va_list var, t_orgi params)
{
    if (params.type == 'c')
        ft_putchar(va_arg(var, int));
    else if (params.type == 's')
        ft_putstr(va_arg(var, char*));
    else if (params.type == 'd' || params.type == 'i')
        ft_putnbr(va_arg(var, int));
    else if (params.type == 'o')
        ft_putnbr(ft_atoi(itoa_base(va_arg(var, int), 8)));
    else if (params.type == 'u')
        ft_putnbr(va_arg(var, unsigned int));
}