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


t_image		*init_image(void *mlx)
{
	t_image		*image;

	if (!(image = (t_image *)malloc(sizeof(t_image))))
		terminate("error with image initialisation");
	if (!(image->image = mlx_new_image(mlx, WIDTH, HEIGHT)))
		terminate("error with image initialisation");
	image->data_addr = mlx_get_data_addr(
		image->image,
		&(image->bits_per_pixel),
		&(image->size_line),
		&(image->endian)
	);
	return(image);
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;
	complex.re = re;
	complex.im = im;
	return (complex);
}

void		set_default(t_fractol *fractol)
{
	fractol->max_iteration = MAX_ITERATIONS;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im + (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	fractol->k = init_complex(-0.4, 0.6);
	fractol->color_shift = 0;
}