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

t_colour	get_colour(int iteration, t_fractol *fractol)
{
	t_colour	colour;
	double		t;
	t = (double)iteration / fraction->max_iteration;
	colour.channel[0] = 0;
	colour.channel[(0 + fractol->colour_shift) % 3 + 1] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	colour.channel[(1 + fractol->colour_shift) % 3 + 1] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	colour.channel[(2 + fractol->colour_shift) % 3 + 1] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (colour);
}