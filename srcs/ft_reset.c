/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 07:02:50 by jleu              #+#    #+#             */
/*   Updated: 2016/04/08 09:02:34 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_reset(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->x2 = 0;
	data->y2 = 0;
	data->x3 = 0;
	data->y3 = 0;
	data->param_move = 1;
	data->zoom = 1;
	ft_new_complex(&data->param, 0, 0);
}
