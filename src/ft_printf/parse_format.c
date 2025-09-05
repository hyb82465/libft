/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:30:45 by yihe              #+#    #+#             */
/*   Updated: 2025/06/07 15:01:51 by yihe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(const char *format, int *i, t_format *fmt)
{	
	ft_bzero(fmt, sizeof(t_format));
	while (format[*i] == '-' || format[*i] == '0' || format[*i] == '+'
		|| format[*i] == ' ' || format[*i] == '#')
	{
		if (format[*i] == '-')
			fmt->minus = 1;
		else if (format[*i] == '0')
			fmt->zero = 1;
		else if (format[*i] == '+')
			fmt->plus = 1;
		else if (format[*i] == ' ')
			fmt->space = 1;
		else if (format[*i] == '#')
			fmt->hash = 1;
		(*i)++;
	}
}

void	parse_format(const char *format, int *i, t_format *fmt)
{
	parse_flags(format, i, fmt);
	while (ft_isdigit(format[*i]))
	{
		fmt->width = fmt->width * 10 + (format[*i] - '0');
		(*i)++;
	}
	if (format[*i] == '.')
	{
		fmt->dot = 1;
		(*i)++;
		while (ft_isdigit(format[*i]))
		{
			fmt->precision = fmt->precision * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
	fmt->specifier = format[*i];
	(*i)++;
}
