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
	int			(*formula)(t_fractol *fractol);
	static	t_formula	formulas[] = {
		{ "Mandelbrot", &iterate_mandelbrot }
	};

	formula = NULL;
	while (i < sizeof(formulas) / sizeof(t_formula))
	{
		if (ft_str)
	}
}
int	main(int argc, char **argv)
{
	int i;

	if (argc == 2)
	{
		i = 1;
		if (!find_formula(argv[i])) {break;}

	}
}