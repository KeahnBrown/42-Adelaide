/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:22:53 by kbrown            #+#    #+#             */
/*   Updated: 2022/09/23 12:23:00 by kbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_macos.h"

static void	help(t_fractol *fractol)
{
	if (fractol->is_help)
	{
		fractol->is_help = 1;
		draw_help(fractol);
	}
	else
	{
		draw_fractol(fractol);
		fractol->is_help = 0;
	}
}

static void	move(int key, t_fractol *fractol)
{
	t_complex	delta;

	delta = init_complex(ft_abs(fractol->max.re - fractol->min.re),
			ft_abs(fractol->max.im - fractol->min.im));
	if (key == ARROW_LEFT)
	{
		fractol->min.re -= delta.re * 0.05;
		fractol->max.re -= delta.re * 0.05;
	}
	else if (key == ARROW_RIGHT)
	{
		fractol->min.re += delta.re * 0.05;
		fractol->max.re += delta.re * 0.05;
	}
	else if (key == ARROW_UP)
	{
		fractol->min.im += delta.im * 0.05;
		fractol->max.im += delta.im * 0.05;
	}
	else if (key == ARROW_DOWN)
	{
		fractol->min.im -= delta.im * 0.05;
		fractol->max.im -= delta.im * 0.05;
	}
	draw_fractol(fractol);
}

static void	change_max_iteration(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS)
	{
		if (fractol->max_iteration < 50)
			fractol->max_iteration += 1;
		else if (fractol->max_iteration < 1000000000)
			fractol->max_iteration = (int)(fractol->max_iteration * 1.05);
	}
	if (key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS)
	{
		if (fractol->max_iteration > 50)
			fractol->max_iteration = (int)(fractol->max_iteration * 0.95);
		else if (fractol->max_iteration > 1)
			fractol->max_iteration -= 1;
	}
	draw_fractol(fractol);
}

static void	change_colour_shift(t_fractol *fractol)
{
	fractol->colour_shift = (fractol->colour_shift + 1) % 3;
	draw_fractol(fractol);
}

int	key_press(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	else if (key == MAIN_PAD_H)
		help(fractol);
	else if (!fractol->is_help)
	{
		if (key == MAIN_PAD_R)
		{
			set_defaults(fractol);
			draw_fractol(fractol);
		}
		else if (key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS
			|| key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS)
			change_max_iteration(key, fractol);
		else if (key == ARROW_LEFT || key == ARROW_RIGHT
			|| key == ARROW_UP || key == ARROW_DOWN)
			move(key, fractol);
		else if (key == MAIN_PAD_C)
			change_colour_shift(fractol);
		else if (key == MAIN_PAD_SPACE)
			fractol->is_julia_fixed = !fractol->is_julia_fixed;
	}
	return (0);
}
