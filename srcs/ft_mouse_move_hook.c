/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 08:31:06 by jleu              #+#    #+#             */
/*   Updated: 2016/04/08 09:00:23 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_move_hook(int x, int y, void *param)
{
	t_data	*data;
	int		sqr[4];

	data = (t_data*)param;
	if (data->param_move && data->fract_type == 1)
	{
		sqr[0] = ((int)(data->param.a / 2.0 + data->win.largeur)
				* (data->win.largeur / 2)) - 5;
		sqr[1] = ((int)(data->param.a / 2.0 + data->win.largeur)
				* (data->win.largeur / 2)) + 5;
		sqr[2] = ((int)(data->param.b / 2.0 + data->win.hauteur)
				* (data->win.hauteur / 2)) - 5;
		sqr[3] = ((int)(data->param.b / 2.0 + data->win.hauteur)
				* (data->win.hauteur / 2)) + 5;
		if (!(data->param.a > sqr[0] && data->param.a < sqr[1] &&
					data->param.b > sqr[2] && data->param.b < sqr[3]))
		{
			data->param.a = ft_resize(x, *data, data->win.largeur);
			data->param.b = ft_resize(y, *data, data->win.hauteur);
			ft_image_draw(data);
		}
	}
	return (0);
}
