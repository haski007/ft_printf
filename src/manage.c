/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:09:02 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/15 19:29:41 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				*implement_precision(char *str, t_orgi *params)
{
	char	*tmp;
	char	*res;
	int		len;
	
	if (str[0] == '0' && params->dot && !str[1])
		return (ft_strdup(""));
	if (params->precision && (len = params->precision - ft_strlen(str)) > 0)
	{
		tmp = ft_strnew(len);
		res = ft_strjoin(ft_memset(tmp, '0', len), str);
		free(tmp);
		free(str);
		return (res);
	}
	return (str);
}

char				*implement_width(char *str, int width, t_orgi *params)
{
	char	*tmp;
	char	*res;
	int		len;

	if (width && (len = width - ft_strlen(str)) > 0)
	{
		tmp = ft_strnew(len);
		if (params->minus)
			res = ft_strjoin(str, ft_memset(tmp, ' ', len));
		else
			res = ft_strjoin(ft_memset(tmp, ((params->zero &&
							!params->dot) || (params->type == '%'
							&& !params->precision)) ? '0' : ' ', len), str);
		free(tmp);
		free(str);
		return (res);
	}
	return (str);
}

static char			*implement_minus(char *str,
		long long int nb)
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

char				*implement_sign(char *str, long long int nb, t_orgi *params)
{
	char *res;

	res = NULL;
	str = (params->zero) ?
		implement_width(str, params->width - 1, params) : str;
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
	res = implement_minus(res, nb);
	return (res);
}
