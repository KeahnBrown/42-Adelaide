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
#include "colour.h"
#include <pthread.h>

static void	put_pixel(t_fractol *fractol, int x, int y, t_colour colour)
{
	int	i;

	i = (x * fractol->image->bits_per_pixel / 8)
		+ (y * fractol->image->size_line);
	fractol->image->data_addr[i] = colour.channel[3];
	fractol->image->data_addr[++i] = colour.channel[2];
	fractol->image->data_addr[++i] = colour.channel[1];
	fractol->image->data_addr[++i] = colour.channel[0];
}

static void	draw_fractol_part(t_fractol *fractol)
{
	int			y;
	int			x;
	t_colour	colour;

	y = fractol->start_line;
	while (y < fractol->finish_line)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			colour = get_colour(fractol->formula(fractol), fractol);
			put_pixel(fractol, x, y, colour);
			x++;
		}
		y++;
	}
}

void	draw_fractol(t_fractol *fractol)
{
	pthread_t	threads[THREADS];
	t_fractol	fractols[THREADS];
	int			i;

	fractol->factor = init_complex((fractol->max.re
				- fractol->min.re) / (WIDTH - 1),
			(fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	i = 0;
	while (i < THREADS)
	{
		fractols[i] = *fractol;
		fractols[i].start_line = i * (HEIGHT / THREADS);
		fractols[i].finish_line = (i + 1) * (HEIGHT / THREADS);
		if (pthread_create(&threads[i], NULL,
				(void *(*)(void *))draw_fractol_part, (void *)&fractols[i]))
			terminate("Error: Threads not initiated correctly");
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			terminate("Error: Threads not initiated correctly");
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image->image, 0, 0);
	mlx_string_put(fractol->mlx, fractol->window,
		900, 965, COLOUR_TUNDORA, "H - Help");
}

void	draw_help(t_fractol *fractol)
{
	ft_bzero(fractol->image->data_addr,
		WIDTH * HEIGHT * (fractol->image->bits_per_pixel / 8));
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image->image, 0, 0);
	mlx_string_put(fractol->mlx, fractol->window, 460, 355, COLOUR_SILVER,
		"Controls");
	mlx_string_put(fractol->mlx, fractol->window, 385, 400, COLOUR_SILVER,
		"Reset          - R");
	mlx_string_put(fractol->mlx, fractol->window, 385, 430, COLOUR_SILVER,
		"Colour Shift    - C");
	mlx_string_put(fractol->mlx, fractol->window, 385, 460, COLOUR_SILVER,
		"Move           - Arrows");
	mlx_string_put(fractol->mlx, fractol->window, 385, 490, COLOUR_SILVER,
		"Zoom           - Scroll");
	mlx_string_put(fractol->mlx, fractol->window, 385, 520, COLOUR_SILVER,
		"Iterations     - +/-");
	mlx_string_put(fractol->mlx, fractol->window, 385, 550, COLOUR_SILVER,
		"Julia Constant - Mouse");
	mlx_string_put(fractol->mlx, fractol->window, 385, 580, COLOUR_SILVER,
		"Mouse Lock     - Space");
	mlx_string_put(fractol->mlx, fractol->window, 385, 610, COLOUR_SILVER,
		"Close Help     - H");
}
