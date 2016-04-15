/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:25:18 by jleu              #+#    #+#             */
/*   Updated: 2016/04/15 19:16:52 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_convertcolor(int c)
{
	int	val;

	val = 0;
	if (c > 170)
	{
		val = (c - 170);
		c -= 85;
	}
	if (c > 85)
	{
		val += (c - 85) * 255 / 85 * 256;
		c -= 85;
	}
	val += (c * 255) / 85 * 256 * 256;
	return (val);
}
/*
int					ft_convertcolor(int c)
{
	int	val;

	val = ((255 * c / 1000) * 256 * 256
			+ (255 * (c % 100) / 100) * 256
			+ (255 * (c % 10) / 10));
	return (val);
}
*/
void				ft_put_pixel_to_image(t_data data, int x, int y, int color)
{
	unsigned int	cpt;
	unsigned int	c;

	color = ft_convertcolor(color);
	c = mlx_get_color_value(data.mlx, color);
	cpt = (data.endian) ? 0 : data.color;
	while ((data.endian && cpt < (unsigned int)data.color) ||
			(!data.endian && cpt > 0))
	{
		if (data.size_line * y + (unsigned int)data.color * x + cpt <
		(data.win.largeur) * (data.win.hauteur) * (unsigned int)data.color)
			data.img_ptr[data.size_line * y + data.color * x + cpt] =
			(char)(c >> (cpt * 8));
		cpt = (data.endian) ? cpt + 1 : cpt - 1;
	}
}
