/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:26:54 by jleu              #+#    #+#             */
/*   Updated: 2016/04/08 09:31:27 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# define WIN_WIDTH 1024
# define WIN_HEIGHT 512

typedef struct		s_comp
{
	long double		a;
	long double		b;
}					t_com;

typedef struct		s_window
{
	void			*win;
	int				largeur;
	int				hauteur;
}					t_window;

typedef struct		s_data
{
	int				nb_branches;
	double			**b;
	t_window		win;
	void			*mlx;
	char			*img_ptr;
	int				color;
	void			*img;
	int				size_line;
	int				endian;
	int				fract_type;
	int				param_move;
	t_com			param;
	int				hide_param;
	unsigned int	zoom;
	long double		x2;
	long double		y2;
	int				x3;
	int				y3;
	int				x;
	int				y;
	time_t			c_g;
	time_t			c_d;
}					t_data;

double				ft_resize2(long double val, t_data data, int size);
void				ft_reset(t_data *data);
void				ft_get_branches(t_data *data, int type);
void				ft_put_pixel_to_image(t_data data, int x, int y, int color);
void				ft_write_param(t_data *data);
int					ft_image_draw(t_data *data);
void				ft_quit(t_data *data, int sortie);
t_com				*ft_new_complex(t_com *z,long double a,long double b);
long double			ft_zoom(unsigned int zoom);
long double			ft_resize(int val, t_data data, int size);
int					ft_rand(int a, int b);
t_com				*ft_getcomplex(t_com *c, t_data *data, int x, int y);
void				ft_hook(t_data* data);
void				ft_putline(t_data data, t_com p1, t_com p2, int color);
int					mouse_move_hook(int x, int y, void *param);

#endif
