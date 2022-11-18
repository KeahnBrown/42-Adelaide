/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:52:52 by kbrown            #+#    #+#             */
/*   Updated: 2022/06/28 15:31:58 by kbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putnbr(int num);
int	ft_convert(unsigned long num, int base, int uporlow);
int	ft_puthexp(void *p);
int	ft_putchar(char c);

#endif
