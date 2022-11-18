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

void	init()

static int		(*find_formula(char *name)) (t_fractol *fractol)
{
	size_t i;
	int			(*formula)(t_fractol *fractol);
	static	t_formula	formulas[] = {
		{ "Mandelbrot", &iterate_mandelbrot },
		{"Julia", &iterate_julia}
	};

	i = 0
	formula = NULL;
	while (i < sizeof(formulas) / sizeof(t_formula))
	{
		if (ft_strequl(name, formulas[i].name))
			formula = formulas[i].formula;
		i++;
	}
	return (fromula);
}

static t_fractol	*init_fractol(char *name, void *mlx)
{
	t_fractol	*fractol;
	if (!(fractol = (t_fractol *)ft_malloc(sizeof(t_fractol))))
		terminate("Issue with initalising fractol");
	fractol->mlx = mlx;
	if (!(fractol->window = mlx_new_window(mlx, WIDTH, HEIGHT, name)))
		terminate("Issue with loading window");
	fractol->image = init_image(mlx);
	set_defaults(fractol);
	if (!(fractol->formula = find_formula(name)))
		terminate("Error: fractol name not reconized");
	mlx_hook(fractol->window, 2, 0, key_press, fractol);
	mlx_hook(fractol->window, 17, 0, close, fractol);
	mlx_hook(fractol->window, 4, 0, zoom, fractol);
	return (fractol);
	
}

static void		start(int num, char **names)
{
	t_fractol	*fractols[10];
	void		*mlx;
	int			i;

	i = 0;
	mlx = mlx_init();
	while (i < number)
	{
		fractols[i] = init_fractol(names[i], mlx);
		draw_fractol(fractols[i]);
		i++;
	}
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	int i;

	if (argc >= 2)
	{
		while (i < argc)
		{
			i = 1;
			if (!find_formula(argv[i]))
				break;
			i++;
		}
		if (i == argc)
			start(argc - 1, &argv[1]);
	}
}