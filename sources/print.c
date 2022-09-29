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

void	print_help(void)
{
	ft_putendl("Usage: ./fractol <name>");
	ft_putendl(NULL);
	ft_putendl("You can specify from 1 to 10 names of fractals");
	ft_putendl(NULL);
	ft_putendl("List of available fractals:");
	ft_putendl(" * Mandelbrot");
	ft_putendl(" * Julia");
	ft_putendl(" * Burning Ship");
	ft_putendl(" * Mandelbar");
	ft_putendl(" * Celtic Mandelbrot");
	ft_putendl(" * Celtic Mandelbar");
	ft_putendl(" * Celtic Perpendicular");
	ft_putendl(" * Perpendicular Mandelbrot");
	ft_putendl(" * Perpendicular Burning Ship");
	ft_putendl(" * Perpendicular Buffalo");
}
