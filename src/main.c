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
    int     chlen = 45;

    my_result = ft_printf("MY test |||||||%50p --%%%%%%-- %-44c ----- %-12o*\n", b, 'O', chlen);
    org_result = printf("Original|||||||%50p --%%%%%%-- %-44c ----- %-12o*\n", b, 'O', chlen);
    printf("\n\nMy result - %d\n", my_result);
    printf("Original result - %d\n", org_result);
    system("leaks ft_printf");
    return (0);
}