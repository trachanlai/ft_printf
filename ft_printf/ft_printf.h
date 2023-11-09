/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:20:07 by tlai              #+#    #+#             */
/*   Updated: 2023/11/09 16:12:56 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_conversion(va_list args, char specifier, int *error);

int		ft_putchar(const char c, int *error);
int		print_s_string(const char *str, int *error);

int		print_int(int n, int *error);
int		print_unsigned_int(unsigned int n, int *error);

int		print_x_low(unsigned long x, int *error);
int		print_x_up(unsigned long x, int *error);
int		print_p_pointer(unsigned long p, int *error);

#endif