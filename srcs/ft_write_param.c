/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 10:06:43 by jleu              #+#    #+#             */
/*   Updated: 2016/04/08 07:44:39 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_write_param(t_data *data)
{
	char *zoom;

	zoom = ft_itoa(data->zoom);
	mlx_string_put(data->mlx, data->win.win, 10, 10, 0x00ffff00, "2^");
	mlx_string_put(data->mlx, data->win.win, 30, 10, 0x00ff0000, zoom);
	free(zoom);
	mlx_string_put(data->mlx, data->win.win, 780, 10, 0x00ffff00,
					"show/hide commands : s");
	if (!data->hide_param)
	{
		mlx_string_put(data->mlx, data->win.win, 780, 25, 0x00ff0000,
						"------------------------");
		mlx_string_put(data->mlx, data->win.win, 780, 40, 0x00f5f5dc,
						"scroll : zoom/dezoom");
		mlx_string_put(data->mlx, data->win.win, 780, 55, 0x00f5f5dc,
						"space : stop auto move");
		mlx_string_put(data->mlx, data->win.win, 780, 70, 0x00f5f5dc,
						"1,2,3 : fractal type");
		mlx_string_put(data->mlx, data->win.win, 780, 85, 0x00f5f5dc,
						"0 : reset curent fractal");
		mlx_string_put(data->mlx, data->win.win, 780, 100, 0x00f5f5dc,
						"esc : quit");
	}
}
