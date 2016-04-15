/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arbres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 01:19:36 by jleu              #+#    #+#             */
/*   Updated: 2016/04/08 07:37:49 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	**arbre1(void)
{
	double		**b;

	b = (double**)malloc(sizeof(double*) * 3);
	b[0] = (double*)malloc(sizeof(double) * 2);
	b[1] = (double*)malloc(sizeof(double) * 2);
	b[2] = (double*)malloc(sizeof(double) * 2);
	b[0][0] = 0.25;
	b[1][0] = 0.85;
	b[2][0] = 0.25;
	b[0][1] = 2.0 * M_PI / 5.0;
	b[1][1] = 0.05;
	b[2][1] = -2.0 * M_PI / 5.0;
	return (b);
}

static double	**arbre2(void)
{
	double		**b;

	b = (double**)malloc(sizeof(double*) * 2);
	b[0] = (double*)malloc(sizeof(double) * 2);
	b[1] = (double*)malloc(sizeof(double) * 2);
	b[0][0] = 0.7;
	b[1][0] = 0.7;
	b[0][1] = M_PI / 9.0;
	b[1][1] = -2.0 * M_PI / 9.0;
	return (b);
}

static double	**arbre3(void)
{
	double		**b;

	b = (double**)malloc(sizeof(double*) * 2);
	b[0] = (double*)malloc(sizeof(double) * 2);
	b[1] = (double*)malloc(sizeof(double) * 2);
	b[0][0] = 0.7;
	b[1][0] = 0.7;
	b[0][1] = M_PI / 3.0;
	b[1][1] = -M_PI / 3.0;
	return (b);
}

void			ft_get_branches(t_data *data, int type)
{
	int			cpt;

	cpt = 0;
	if (data->b)
	{
		while (cpt < data->nb_branches)
			free(data->b[cpt++]);
		free(data->b);
		data->b = NULL;
	}
	if (type == 0)
	{
		data->nb_branches = 3;
		data->b = arbre1();
	}
	else if (type == 1)
	{
		data->nb_branches = 2;
		data->b = arbre2();
	}
	else if (type == 2)
	{
		data->nb_branches = 2;
		data->b = arbre3();
	}
}
