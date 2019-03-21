/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floatoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:44:31 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/21 16:46:11 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	fabs(long double num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

static void			cat_free(char *str, char *itoa_ret)
{
	ft_strcat(str, itoa_ret);
	free(itoa_ret);
}

static void			fill_zeros(char *str, char *itoa_ret, int precision)
{
	int itoa_len;

	itoa_len = ft_strlen(itoa_ret);
	while (itoa_len++ < precision)
		ft_strcat(str, "0");
}

char				*floatoa(long double num, unsigned int precision)
{
	long long int	ip;
	long double		fp;
	char			*str;
	char			*itoa_ret;

	str = ft_strnew(30);
	if (num < 0)
	{
		ft_strcat(str, "-");
		num = fabs(num);
	}
	ip = (long long int)num;
	fp = num - ip;
	itoa_ret = ft_itoa(ip);
	cat_free(str, itoa_ret);
	if (precision != 0)
	{
		ft_strcat(str, ".");
		fp = fp * ft_power(10, precision);
		itoa_ret = fp - (int)fp >= 0.5 ? ft_itoa(fp + 1) : ft_itoa(fp);
		fill_zeros(str, itoa_ret, precision);
		cat_free(str, itoa_ret);
	}
	return (str);
}
