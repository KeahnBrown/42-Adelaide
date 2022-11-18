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

static int	(*find_formula(char *name)) (t_fractol *fractol)
{
	size_t				i;
	int					(*formula)(t_fractol *fractol);
	static t_formula	formulas[] = {
	{"Mandelbrot", &mandelbrot},
	{"Julia", &julia},
	{"Burning Ship", &iterate_burning_ship},
	{"Mandelbar", &iterate_mandelbar},
	{"Celtic Mandelbrot", &iterate_celtic_mandelbrot},
	{"Celtic Mandelbar", &iterate_celtic_mandelbar},
	{"Celtic Perpendicular", &iterate_celtic_perpendicular},
	{"Perpendicular Mandelbrot", &iterate_perpendicular_mandelbrot},
	{"Perpendicular Burning Ship", &iterate_perpendicular_burning_ship},
	{"Perpendicular Buffalo", &iterate_perpendicular_buffalo}
	};

	i = 0;
	formula = NULL;
	while (i < sizeof(formulas) / sizeof(t_formula))
	{
		if (ft_strequl(name, formulas[i].name))
			formula = formulas[i].formula;
		i++;
	}
	return (formula);
}

static t_fractol	*init_fractol(char *name, void *mlx)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!(fractol))
		terminate("Issue with initalising fractol");
	fractol->mlx = mlx;
	fractol->window = mlx_new_window(mlx, WIDTH, HEIGHT, name);
	if (!(fractol->window))
		terminate("Issue with loading window");
	fractol->image = init_image(mlx);
	set_defaults(fractol);
	fractol->is_julia_fixed = 0;
	fractol->formula = find_formula(name);
	if (!(fractol->formula))
		terminate("Error: fractol name not reconized");
	mlx_hook(fractol->window, 2, 0, key_press, fractol);
	mlx_hook(fractol->window, 17, 0, close, fractol);
	mlx_hook(fractol->window, 4, 0, zoom, fractol);
	if (ft_strequl(name, "Julia"))
		mlx_hook(fractol->window, 6, 0, julia_motion, fractol);
	return (fractol);
}

static void	start(int num, char **names)
{
	t_fractol	*fractols[10];
	void		*mlx;
	int			i;

	i = 0;
	mlx = mlx_init();
	while (i < num)
	{
		fractols[i] = init_fractol(names[i], mlx);
		draw_fractol(fractols[i]);
		i++;
	}
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2 && ft_strequl(argv[1], "help"))
		print_help();
	else if (argc >= 2 && argc <= 11)
	{
		i = 1;
		while (i < argc)
		{
			if (!find_formula(argv[i]))
				break ;
			i++;
		}
		if (i == argc)
			start(argc - 1, &argv[1]);
	}
	return (0);
}
