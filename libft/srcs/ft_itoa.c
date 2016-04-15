/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:45:06 by jleu              #+#    #+#             */
/*   Updated: 2016/04/04 11:01:31 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	neg;
	int		temp;
	char	*str;

	len = (n < 0);
	neg = (n < 0);
	temp = n;
	while ((++len) && (temp > 9 || temp < -9))
		temp /= 10;
	str = ft_strnew(len + 1);
	str[len] = 0;
	if (!str)
		return (NULL);
	while (n > 9 || n < -9)
	{
		str[--len] = (n < 0) ? (-(n % 10)) + '0' : (n % 10) + '0';
		n /= 10;
	}
	str[len - 1] = (n < 0) ? (-(n % 10)) + '0' : (n % 10) + '0';
	str[0] = (neg) ? '-' : str[0];
	return (str);
}
