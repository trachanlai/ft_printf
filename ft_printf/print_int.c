/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:55:42 by tlai              #+#    #+#             */
/*   Updated: 2023/11/09 15:22:54 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n, int *error)
{
	int		counter;
	int		counter2;
	long	digit;

	digit = (long)n;
	counter = 0;
	counter2 = 0;
	if (digit < 0 && *error != -1)
	{
		*error = write(1, "-", 1);
		digit = digit * -1;
		counter = 1;
	}
	if (digit == 0)
		counter = 1;
	if (digit >= 10 && *error != -1)
		print_int(digit / 10, error);
	while (n != '\0')
	{
		n = n / 10;
		counter2++;
	}
	if (*error != -1)
		ft_putchar('0' + digit % 10, error);
	return (counter + counter2);
}

int	print_unsigned_int(unsigned int n, int *error)
{
	int		counter;
	int		counter2;
	long	digit;

	digit = (long)n;
	counter = 0;
	counter2 = 0;
	if (digit == 0)
		counter = 1;
	if (digit >= 10 && *error != -1)
		print_int(digit / 10, error);
	while (n != '\0')
	{
		n = n / 10;
		counter2++;
	}
	if (*error != -1)
		ft_putchar('0' + digit % 10, error);
	return (counter + counter2);
}
