/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 08:31:13 by jleu              #+#    #+#             */
/*   Updated: 2016/04/08 09:31:25 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mouse_hook(int key, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data*)param;
	if (!data->param_move || data->fract_type != 1)
	{
		if (((key == 4 || (key == 1 && data->c_g > 0)) && data->zoom < 70)
			|| ((key == 5 || (key == 2 && data->c_d > 0)) && data->zoom > 1))
		{
			data->c_g = 0;
			data->c_d = 0;
			data->x = x - data->win.largeur / 2;
			data->y = y - data->win.hauteur / 2;
			data->x2 += ft_resize(x, *data, data->win.largeur);
			data->y2 += ft_resize(y, *data, data->win.hauteur);
			(key == 4 || key == 1) ? data->zoom++ : data->zoom--;
			ft_image_draw(data);
		}
		else if (key == 1 && data->c_g == 0)
			data->c_g = time(NULL);
		else if (key == 2 && data->c_d == 0)
			data->c_d = time(NULL);
	}
	return (0);
}

static int	expose_hook(void *param)
{
	t_data *data;

	data = (t_data*)param;
	if (data->img)
	{
		mlx_clear_window(data->mlx, data->win.win);
		mlx_put_image_to_window(data->mlx, data->win.win, data->img, 0, 0);
		ft_write_param(data);
	}
	return (0);
}

static int	key_hook(int k, void *param)
{
	t_data	*data;

	if ((data = (t_data*)param) && k == 49 && data->zoom == 1)
		return (data->param_move = !data->param_move);
	else if (k > 82 && k < 88 && (data->fract_type = k - 82))
		(k > 82 && k < 85) ? ft_reset(data) : ft_get_branches(data, k - 85);
	else if (k == 123 || k == 124)
	{
		data->x = (data->win.largeur / 2) + ((k == 123) ? -50 : 50);
		data->x2 += ft_resize(data->x, *data, data->win.largeur);
	}
	else if (k == 126 || k == 125)
	{
		data->y = (data->win.hauteur / 2) + ((k == 126) ? -50 : 50);
		data->y2 += ft_resize(data->y, *data, data->win.hauteur);
	}
	else if (k == 82 || k == 53)
		(k == 82) ? ft_reset(data) : ft_quit(data, 0);
	else
	{
		data->hide_param = (k == 1) ? !data->hide_param : data->hide_param;
		return ((k == 1) ? expose_hook((void*)param) : 0);
	}
	return (ft_image_draw(data));
}

static int	loop_hook(void *param)
{
	t_data	*data;

	data = (t_data*)param;
	if (data->c_g > 0 && difftime(time(NULL), data->c_g) > 2)
		data->c_g = 0;
	else if (data->c_d > 0 && difftime(time(NULL), data->c_d) > 2)
		data->c_d = 0;
	return (1);
}

void		ft_hook(t_data *data)
{
	mlx_key_hook(data->win.win, &key_hook, (void*)data);
	mlx_mouse_hook(data->win.win, &mouse_hook, (void*)data);
	mlx_hook(data->win.win, 6, 6, &mouse_move_hook, (void*)data);
	mlx_expose_hook(data->win.win, &expose_hook, (void*)data);
	mlx_loop_hook(data->mlx, &loop_hook, (void*)data);
	mlx_loop(data->mlx);
}
