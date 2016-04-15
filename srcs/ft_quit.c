/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:47:24 by jleu              #+#    #+#             */
/*   Updated: 2016/03/19 20:07:58 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_quit(t_data *data, int sortie)
{
	if (data->win.win)
		mlx_destroy_window(data->mlx, data->win.win);
	if (sortie == 0)
		ft_putendl("see you again mister johns.");
	exit(0);
}
