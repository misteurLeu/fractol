/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:25:07 by jleu              #+#    #+#             */
/*   Updated: 2016/04/08 09:31:22 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_get_color(t_com *z, t_com *c)
{
	long double				save_a;
	long double				save_b;
	register unsigned int	color;

	color = 0;
	while (z->a * z->a + z->b * z->b <= 4.0 && ++color < 999)
	{
		save_a = z->a;
		save_b = z->b;
		z->a = (save_a * save_a - save_b * save_b) + c->a;
		z->b = 2.0 * (save_a * save_b) + c->b;
	}
	return (color);
}

static void		ft_arbre(t_data *data, t_com *c, t_com *z, int color)
{
	t_com		save;
	double		x;
	double		y;
	int			cpt;

	color = (color < 50) ? 0 : color;
	ft_putline(*data, *c, *z, color + 50);
	save.a = z->a;
	save.b = z->b;
	x = save.a - c->a;
	y = save.b - c->b;
	cpt = -1;
	if ((data->fract_type == 3 && x * x + y * y >= 0.0001)
		|| (data->fract_type == 4 && x * x + y * y >= 0.01)
		|| (data->fract_type == 5 && x * x + y * y >= 0.1))
		while (++cpt < data->nb_branches)
			ft_arbre(data, &save, ft_new_complex(z,
					cos(data->b[cpt][1]) * data->b[cpt][0] * x
					- sin(data->b[cpt][1]) * data->b[cpt][0] * y + save.a,
					sin(data->b[cpt][1]) * data->b[cpt][0] * x
					+ cos(data->b[cpt][1]) * data->b[cpt][0] * y
					+ save.b), color - 50);
}

static void		ft_mandel(t_data *data)
{
	t_com			z;
	register int	x;
	register int	y;

	x = -1;
	while (++x != data->win.largeur)
	{
		y = -1;
		while (++y != data->win.hauteur)
		{
			ft_getcomplex(&z, data, x, y);
			if (data->fract_type == 2)
				data->param = z;
			ft_put_pixel_to_image(*data, x, y, ft_get_color(&z, &data->param));
		}
	}
}

int				ft_image_draw(t_data *data)
{
	t_com		z;
	t_com		c;

	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL;
	}
	data->img = mlx_new_image(data->mlx, data->win.largeur, data->win.hauteur);
	data->img_ptr =
		mlx_get_data_addr(data->img, &data->color,
				&data->size_line, &data->endian);
	data->color /= 8;
	if (data->fract_type < 3)
		ft_mandel(data);
	if (data->fract_type > 2)
		ft_arbre(data,
		ft_new_complex(&c, ft_resize2(data->x2, *data, data->win.largeur),
							ft_resize2(data->y2, *data, data->win.hauteur) + data->win.hauteur / 2),
		ft_new_complex(&z, ft_resize2(data->x2, *data, data->win.largeur),
							ft_resize2(data->y2, *data, data->win.hauteur) + data->win.hauteur / 2 - 80.0), 492);
	mlx_clear_window(data->mlx, data->win.win);
	mlx_put_image_to_window(data->mlx, data->win.win, data->img, 0, 0);
	ft_write_param(data);
	return (0);
}
