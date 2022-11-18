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
# define FRACTOL_H

# include <stdint.h>
# include <math.h>
# include <stdio.h>
# include <inttypes.h>
# include "libft.h"
# include "mlx.h"

# define MAX_ITERATIONS 90
# define WIDTH 1000
# define HEIGHT 1000
# define THREADS 10

typedef struct s_colour
{
	int8_t		channel[4];
}				t_colour;

typedef struct s_complex //holds values for complex number
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_image
{
	void		*image;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_image;

typedef struct s_fractol //computational processes for fractol
{
	void		*mlx;
	void		*window;
	t_image		*image;
	int			max_iteration;
	t_complex	max;
	t_complex	min;
	t_complex	factor;
	t_complex	c;
	t_complex	k;
	int			start_line;
	int			finish_line;
	int			colour_shift;
	int			(*formula)(struct s_fractol *fractol);
	int8_t		is_julia_fixed;
	int8_t		is_help;
}				t_fractol;

typedef struct s_formula //type of fractol with its build
{
	char		*name;
	int			(*formula)(t_fractol *fractol);
}				t_formula;

//init
t_image			*init_image(void *mlx);
t_complex		init_complex(double re, double im);
void			set_defaults(t_fractol *fractol);

//utils
int				ft_strequl(char *str1, char *str2);
void			terminate(char *error);

//colour
t_colour		get_colour(int iteration, t_fractol *fractol);

//controls
int				zoom(int button, int x, int y, t_fractol *fractol);
int				julia_motion(int x, int y, t_fractol *fractol);
int				ft_close(void *param);

void			draw_fractol(t_fractol *fractol);
void			draw_help(t_fractol *fractol);
void			ft_putendl(char const *s);
int				key_press(int key, t_fractol *fractol);

double			ft_abs(double num);

//print
void			print_help(void);

//fractals
int				mandelbrot(t_fractol *fractol);

int				julia(t_fractol *fractol);

int				iterate_burning_ship(t_fractol *fractol);

int				iterate_mandelbar(t_fractol *fractol);

int				iterate_celtic_mandelbrot(t_fractol *fractol);

int				iterate_celtic_mandelbar(t_fractol *fractol);

int				iterate_celtic_perpendicular(t_fractol *fractol);

int				iterate_perpendicular_mandelbrot(t_fractol *fractol);

int				iterate_perpendicular_burning_ship(t_fractol *fractol);

int				iterate_perpendicular_buffalo(t_fractol *fractol);

#endif
