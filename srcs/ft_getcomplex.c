/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcomplex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 23:16:08 by jleu              #+#    #+#             */
/*   Updated: 2016/04/08 07:41:18 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_com	*ft_getcomplex(t_com *c, t_data *data, int x, int y)
{
	ft_new_complex(c, data->x2 + ft_resize(x, *data, data->win.largeur),
					data->y2 + ft_resize(y, *data, data->win.hauteur));
	data->x = 0;
	data->y = 0;
	return (c);
}
