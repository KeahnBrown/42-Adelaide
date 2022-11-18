/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:43:35 by kbrown            #+#    #+#             */
/*   Updated: 2022/09/22 16:44:05 by kbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include "libft.h"
#include "mlx.h"
#include "ft_printf.h"

#define MAX_ITERATIONS 90
#define WIDTH 1000
#define HEIGHT 1000
#define KEY_ESC 53
#define MOUSE_WHEEL_UP 4
#define MOUSE_WHEEL_DOWN 5
#define THREADS 10

typedef struct	s_colour
{
	int8_t		channel[4];
}				t_colour;

typedef struct	s_complex //holds values for complex number
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_fractol //computational processes for fractol
{
	void		*mlx;
	void		*window;
	void		*image;
	t_complex	max;
	t_complex	min;
	t_complex	factor;
	t_complex	comp_num;
	t_complex	const_comp_num;
	int			start_line;
	int			finish_line;
	int			colour_shift;
	int			(*formula)(struct s_fractol *fractol)
}				t_complex

typedef struct	s_formula //type of fractol with its build
{
	char		*name;
	int			(*formula)(t_fractol *fractol);
}				t_formula

typedef struct s_image
[
	void		*image;
	char		*data_addr;
	int			bpp;
	int			line_size;
	int			endian;
]				t_image

t_image		*init_image(void *mlx);
t_complex	init_complex(double re, double im);
void		set_defaults(t_fractol *fractol);


int			strequl(char *str1, char *str2); //checks if strings are the same

void		terminate(char *error);

#endif
