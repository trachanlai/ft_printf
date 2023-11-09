/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:05:25 by tlai              #+#    #+#             */
/*   Updated: 2023/11/09 16:04:29 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	print_x_low(unsigned long x, int *error)
// {
// 	unsigned int	counter;

// 	counter = 0;
// 	if (*error != -1)
// 	{
// 		if (x >= 16 && *error != -1)
// 			counter += print_x_low(x / 16, error);
// 		if (*error != -1)
// 			ft_putchar("0123456789abcdef"[x % 16], error);
// 		counter++;
// 	}
// 	return (counter);
// }

int	print_x_low(unsigned long x, int *error)
{
	unsigned int	counter;
	char			*hexdigits;
	char			hexchar;

	counter = 0;
	hexdigits = "0123456789abcdef";
	hexchar = hexdigits[x % 16];
	if (*error != -1)
	{
		if (x >= 16 && *error != -1)
			counter += print_x_low(x / 16, error);
		if (*error != -1)
			ft_putchar(hexchar, error);
		counter++;
	}
	return (counter);
}

int	print_x_up(unsigned long x, int *error)
{
	unsigned int	counter;
	char			*hexdigits;
	char			hexchar;

	counter = 0;
	hexdigits = "0123456789ABCDEF";
	hexchar = hexdigits[x % 16];
	if (*error != -1)
	{
		if (x >= 16 && *error != -1)
			counter += print_x_up(x / 16, error);
		if (*error != -1)
			ft_putchar(hexchar, error);
		counter++;
	}
	return (counter);
}

int	print_p_pointer(unsigned long p, int *error)
{
	unsigned int	counter;

	counter = 0;
	*error = write(1, "0x", 2);
	counter += 2;
	counter += print_x_low(p, error);
	return (counter);
}
