/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 19:05:30 by jleu              #+#    #+#             */
/*   Updated: 2016/04/08 07:31:34 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_rand(int a, int b)
{
	static int	init = 0;
	int			temp;

	if (init == 0)
	{
		srand(time(NULL));
		init = 1;
	}
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	return (rand() % (b - a) + a);
}
