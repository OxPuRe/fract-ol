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
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
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

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data_img;
	int				bpp;
	int				end;
	int				x;			// screen size x
	int				x_min;
	int				y;			// screen size y
	int				y_min;
	int				a;
	int				b;
	int				iteration;
	int				it;			// bool to freeze Julia
	int				mem_a;
	int				mem_b;
	double			c_x;		// coordonées du point en train d'etre calculé
	double			c_y;		// coordonées du point en train d'etre calculé
	char			*fractale;
	t_coords		b_x;		// Limite de l'ensemble de la fractale sur l'axe X
	t_coords		b_y;		// Limite de l'ensemble de la fractale sur l'axe Y
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

#endif
