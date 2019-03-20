/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:55:48 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/10 12:55:51 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int         main(void)
{
    int     my_result;
    int     org_result;
    int     a = 1999;
    int     *b = &a;
    unsigned short int  num = 3267;

    my_result = ft_printf("MY test |||||||%hhp ---- %lc ----- %o\n", b, 'O', -num);
    org_result = printf("Original|||||||%p ---- %c ----- %o\n", b, 'O', -num);
    printf("\n\nMy result - %d\n", my_result);
    printf("Original reuslt - %d\n", org_result);
    return (0);
}