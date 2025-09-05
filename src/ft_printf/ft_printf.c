/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:31:55 by yihe              #+#    #+#             */
/*   Updated: 2025/06/10 14:19:30 by yihe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dispatch_format(t_format *fmt, va_list args)
{
	if (fmt->specifier == 'c')
		return (print_formatted_char(fmt, va_arg(args, int)));
	else if (fmt->specifier == 's')
		return (print_formatted_string(fmt, va_arg(args, char *)));
	else if (fmt->specifier == 'p')
		return (print_formatted_pointer(fmt, va_arg(args, void *)));
	else if (fmt->specifier == 'd' || fmt->specifier == 'i')
		return (print_formatted_int(fmt, va_arg(args, int)));
	else if (fmt->specifier == 'u')
		return (print_formatted_unsigned(fmt, va_arg(args, unsigned int)));
	else if (fmt->specifier == 'x' || fmt->specifier == 'X')
		return (print_formatted_hex(fmt, va_arg(args, unsigned int)));
	else if (fmt->specifier == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			count;
	t_format	fmt;

	i = 0;
	count = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			parse_format(format, &i, &fmt);
			count += dispatch_format(&fmt, args);
		}
		else
			count += write(1, &format[i++], 1);
	}
	va_end(args);
	return (count);
}
