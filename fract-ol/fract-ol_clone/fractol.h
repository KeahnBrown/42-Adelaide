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
#include "ft_printf.h"
#include "mlx.h"

#define MAX_ITERATIONS 90
#define WIDTH 1000
#define HEIGHT 1000
#define KEY_ESC 53
#define MOUSE_WHEEL_UP 4
#define MOUSE_WHEEL_DOWN 5

typedef struct	s_complex // 
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_fractol
{
	void		*mlx;
	void		*window;
	void		*image;
	t_complex	max;
	t_complex	min;
	t_complex	factor;
	t_complex	comp_num;
	t_complex	const_comp_num;
	int			(*formula)(struct s_fractol *fractol)
}				t_complex

typedef struct	s_formula
{
	char		*name;
	int			(*formula)(t_fractol *fractol);
}				t_formula

int		strequl(char *str1, char *str2); //checks if strings are the same

#endif
