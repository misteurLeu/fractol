/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 00:45:00 by jleu              #+#    #+#             */
/*   Updated: 2016/04/08 09:26:15 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	ft_resize(int val, t_data data, int size)
{
	return ((4.0 / ft_zoom(data.zoom)) * (long double)val /
			(long double)size - (2.0 / ft_zoom(data.zoom)));
}

double		ft_resize2(long double val, t_data data, int size)
{
	return ((double)((val * ft_zoom(data.zoom) + 2.0) *
			(long double)size / 4.0));
}
