/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:55:53 by auverneu          #+#    #+#             */
/*   Updated: 2020/04/24 16:10:58 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# define KEY_ESC 65307
# define KEY_O 111
# define KEY_P 112
# define KEY_R 114
# define KEY_F 102

typedef struct		s_coords
{
	double			x;
	double			y;
}					t_coords;

/*
**	int			x;		screen size x
**	int			y;		screen size y
**	int			it;		bool to freeze Julia
**	double		c_x;	x point being calculated
**	double		c_y;	y point being calculated
**	t_coords	b_x;	Fractal x limit
**	t_coords	b_y;	Fractal y limit
*/

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data_img;
	int				bpp;
	int				end;
	int				x;
	int				y;
	int				iteration;
	int				it;
	int				mem_a;
	int				mem_b;
	double			c_x;
	double			c_y;
	char			*fractale;
	t_coords		b_x;
	t_coords		b_y;
}					t_env;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

int					key_r(int keycode, t_env *e);
int					expose_hook(t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					pointer_motion(int x, int y, t_env *e);
int					image_pixel_put(t_env *e, t_point a, int color);
void				mandelbrot(t_env *e);
void				julia(t_env *e);
void				burning_ship(t_env *e);
int					loop_hook(t_env *e);
int					rgb(double r, double g, double b);

#endif
