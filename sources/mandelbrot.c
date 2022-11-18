/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:31:16 by kbrown            #+#    #+#             */
/*   Updated: 2022/07/22 15:55:11 by kbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration
		< fractol->max_iteration)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
				+ fractol->c.re, 2.0 * z.re * z.im + fractol->c.im);
		iteration++;
	}
	return (iteration);
}
