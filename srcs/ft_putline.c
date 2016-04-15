/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:24:43 by jleu              #+#    #+#             */
/*   Updated: 2016/04/08 07:38:26 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_putline(t_data data, t_com p1, t_com p2, int color)
{
	double	a;
	double	b;
	int		croiss_y;
	int		croiss_x;

	croiss_y = (p1.b < p2.b);
	if ((int)p1.a != (int)p2.a)
	{
		a = (p2.b - p1.b) / (p2.a - p1.a);
		b = p1.b - a * p1.a;
		croiss_x = (p1.a < p2.a);
		while (((int)p1.a < (int)p2.a && croiss_x)
			|| ((int)p2.a < (int)p1.a && !croiss_x))
		{
			ft_put_pixel_to_image(data, p1.a, p1.b, color);
			while (((croiss_y && p1.b < (a * p1.a + b))
					|| (!croiss_y && p1.b > (a * p1.a + b)))
					&& (p1.b += (croiss_y) ? 1 : -1))
				ft_put_pixel_to_image(data, (int)p1.a, (int)p1.b, color);
			(croiss_x) ? p1.a++ : p1.a--;
		}
	}
	if ((int)p1.a == (int)p2.a)
		while ((croiss_y && ++p1.b <= p2.b) || (!croiss_y && --p1.b >= p2.b))
			ft_put_pixel_to_image(data, (int)p1.a, (int)p1.b, color);
}
