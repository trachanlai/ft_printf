/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:11:48 by tlai              #+#    #+#             */
/*   Updated: 2023/11/09 16:13:02 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char c, int *error)
{
	*error = write(1, &c, 1);
	if (*error != -1)
		return (1);
	return (-1);
}

int	print_s_string(const char *str, int *error)
{
	int	counter;

	counter = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str != '\0' && *error != -1)
	{
		ft_putchar(*str, error);
		str++;
		counter++;
	}
	return (counter);
}

int	ft_conversion(va_list args, char specifier, int *error)
{
	int	counter;

	counter = 0;
	if (specifier == '\0')
		return (-1);
	else if (specifier == 'c')
		return (ft_putchar(va_arg(args, int), error));
	else if (specifier == 's')
		return (print_s_string(va_arg(args, const char *), error));
	else if (specifier == 'd' || specifier == 'i')
		return (print_int(va_arg(args, int), error));
	else if (specifier == 'u')
		return (print_unsigned_int(va_arg(args, unsigned int), error));
	else if (specifier == 'x')
		return (print_x_low(va_arg(args, unsigned int), error));
	else if (specifier == 'X')
		return (print_x_up(va_arg(args, unsigned int), error));
	else if (specifier == 'p')
		return (print_p_pointer(va_arg(args, unsigned long), error));
	else if (specifier == '%')
		return (ft_putchar('%', error));
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;
	int		error;

	error = 0;
	va_start(args, str);
	counter = 0;
	if (str == NULL)
		return (-1);
	while (*str != '\0' && error != -1)
	{
		if (*str == '%')
			counter += ft_conversion(args, *(++str), &error);
		else
		{
			counter++;
			error = write(1, str, 1);
		}
		str++;
	}
	va_end(args);
	if (error == -1)
		return (-1);
	return (counter);
}

// #include <stdio.h>

// int main ()
// {
// 	int i;
// 	int j;
// 	i = printf("%d\n", 156);
// 	j = ft_printf("%d\n", 156);
// 	printf("Original %d\n", i);
// 	ft_printf("Duplicat %d\n", j);

// 	return (0);
// }

// int	main()
// {
// 	int len = 0;
// 	// int s1 = 0;
// 	// int s2 = 0;
// 	printf("\nc \tand \ts\n");
// 	len = printf("%p\n", NULL);
// 	printf("len:%d\n", len);
// 	len = ft_printf("%p\n", NULL);
// 	printf("len:%d\n", len);

// 	// printf("\ni \tand \td\n");
// 	// len = printf("%i\t%d\n", 0, -8527413);
// 	// printf("len:%d\n", len);
// 	// len = ft_printf("%i\t%d\n", 0, -8527413);
// 	// printf("len:%d\n", len);

// 	// int	voidling = 42;
// 	// unsigned int u = 4561387;
// 	// printf("\np \tand \tu\n");
// 	// len = printf("%p\t%u\n", &voidling, u);
// 	// printf("len:%d\n", len);
// 	// len = ft_printf("%p\t%u\n", &voidling, u);
// 	// printf("len:%d\n", len);

// 	// unsigned int x = 4194512153;
// 	// unsigned int X = -94512740;
// 	// printf("\nx \tand \tX\n");
// 	// len = printf("%x\t%X\n", x, X);
// 	// printf("len:%d\n", len);
// 	// len = ft_printf("%x\t%X\n", x, X);
// 	// printf("len:%d\n", len);
// 	return (0);
// }