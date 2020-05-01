/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:58:55 by auverneu          #+#    #+#             */
/*   Updated: 2020/04/24 16:11:23 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	inter(int keycode, t_env *e)
{
	if (keycode == KEY_P && e->iteration + 20 < 2147483647)
	{
		e->iteration += 20;
		expose_hook(e);
	}
	if (keycode == KEY_O && e->iteration - 20 > 0)
	{
		e->iteration -= 20;
		expose_hook(e);
	}
	if (keycode == KEY_F)
	{
		if (e->it == 1)
			e->it = 0;
		else
			e->it = 1;
	}
}

int			key_r(int keycode, t_env *e)
{
	if (keycode == KEY_R)
	{
		if (ft_strcmp("julia", e->fractale) == 0)
		{
			e->c_x = 0;
			e->c_y = 0;
		}
		e->b_x.x = -2.4;
		e->b_x.y = 2.4;
		e->b_y.x = -1.5;
		e->b_y.y = 1.5;
		expose_hook(e);
	}
	inter(keycode, e);
	if (keycode == KEY_ESC)
	{
		free(e->fractale);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
