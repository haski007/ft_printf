/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 16:06:00 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/10 17:48:44 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_size(int num, int base)
{
	int		size;

	if (num == 0)
		return(1);
	size = 0;
	while (num)
	{
		size++;
		num /= base;
	}
	return (size);
}

char		*itoa_base(long long int num, int base)
{
	char	*str;
	int		size;
	char	*res;

	str = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	size = count_size(num, base);
	res = (char*)malloc(sizeof(char) * size + 1);
	res[size] = '\0';
	while (size)
	{
		res[size - 1] = str[num % base];
		num /= base;
		size--;
	}
	return (res);
}
