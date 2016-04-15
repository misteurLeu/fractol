/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 07:29:53 by jleu              #+#    #+#             */
/*   Updated: 2016/04/08 08:58:46 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_window		new_win(void *mlx)
{
	t_window	win;

	win.largeur = WIN_WIDTH;
	win.hauteur = WIN_HEIGHT;
	win.win = mlx_new_window(mlx, win.largeur, win.hauteur, "FDF_PROJECT");
	return (win);
}

static void			bad_param(void)
{
	ft_putendl("\nerror bad parameters");
	ft_putendl("--------------------");
	ft_putendl("usage :");
	ft_putendl("1 = julia");
	ft_putendl("2 = mendel");
	ft_putendl("3 = arbre 1");
	ft_putendl("4 = arbre 2");
	ft_putendl("5 = arbre 3");
}

int					main(int argc, char **argv)
{
	t_data			data;

	if (argc == 2 && (argv[1][0] > 48 && argv[1][0] < 54) && !argv[1][1])
	{
		data.win.win = NULL;
		data.mlx = mlx_init();
		data.win = new_win(data.mlx);
		data.img = NULL;
		data.fract_type = argv[1][0] - '0';
		ft_reset(&data);
		data.c_g = 0;
		data.c_d = 0;
		data.b = NULL;
		if (data.fract_type > 2)
			ft_get_branches(&data, data.fract_type - 3);
		data.hide_param = 1;
		ft_new_complex(&data.param, 0, 0);
		ft_image_draw(&data);
		ft_hook(&data);
		ft_quit(&data, 0);
	}
	else
		bad_param();
	return (1);
}
