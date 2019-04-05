/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:55:48 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/05 20:08:47 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void        exit_func()
{
 //   system("leaks ft_printf");
    exit(1);
}

#define ARG "Result|||||||||%#50o*-----%%%%%%\n",  1557

int         main(void)
{
    int     my_result;
    int     org_result;
    // int     a = 1999;
    // int     *b = &a;
    // int     chlen = 45;

    my_result = ft_printf(ARG);
    org_result = printf(ARG);
    printf("\n\nMy result - %d\n", my_result);
    printf("Original result - %d\n", org_result);
    system("leaks ft_printf");
    return (0);
}
