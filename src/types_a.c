/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:50:43 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/18 17:50:46 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int             u_type(unsigned int nb)
{
    if (!nb)
        return (0);
    ft_putnbr(nb);
    return (ft_numlen(nb));   
}

int             o_type(int nb)
{
    int based;

    based = ft_atoi(itoa_base(nb, 8));
    ft_putnbr(based);
    return((based < 0) ? ft_numlen(based) + 1 : ft_numlen(based));
}

int             d_type(int nb, t_orgi *params)
{
    char    *str;
    char    *tmp;
    int     len;

    if (!nb)
        return (0);
    str = ft_itoa(nb);
    if ((len = params->width - ft_strlen(str) > 0))
    {
        tmp = ft_strnew(len);
        str = ft_strcat(ft_memset(tmp, ' ', len), str);
    }
    ft_putstr(str);
    len = ft_strlen(str);
    free(str);
    return (len);
}

int             s_type(char *str, t_orgi *params)
{
    int     len;
    char    *tmp;

    if(!str)
        return (0);
    if (params->dot)
        str = ft_strndup(str, params->precision);
    if (params->width)
    {
        if ((len = params->width - ft_strlen(str)) > 0)
        {
            tmp = ft_strnew(len);
            str = ft_strcat(ft_memset(tmp, ' ', len), str);
            free(tmp);
        }
    }
    ft_putstr(str);
    len = ft_strlen(str);
    return (len);
}     

int             c_type(char c)
{
    if (!c)
        return (0);
    ft_putchar(c);
    return (1);
}
