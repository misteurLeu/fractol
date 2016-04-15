/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 20:20:10 by jleu              #+#    #+#             */
/*   Updated: 2016/04/08 09:14:13 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	ft_zoom(unsigned int zoom)
{
	long double val;

	val = 1;
	while (--zoom > 0)
		val *= 2;
	return (val);
}
