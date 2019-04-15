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
    system("leaks ft_printf");
    exit(1);
}

// #define ARG "Result|||||||||%#50.22x*\n",  157

int         main(void)
{
    int     my_result;
    int     org_result;
    int     a = 0;
    int     *b = &a;
    // long long double  chlen = -0;

    my_result = ft_printf("%+0.5d\n", 42);
    org_result = printf("%+05d\n", 42);
    printf("\n\nMy result - %d\n", my_result);
    printf("Original result - %d\n", org_result);
    //   system("leaks ft_printf");
    return (0);
}
