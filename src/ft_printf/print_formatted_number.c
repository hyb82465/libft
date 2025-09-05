/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formatted_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:58:00 by yihe              #+#    #+#             */
/*   Updated: 2025/06/09 18:29:10 by yihe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_prefix_len(t_format *fmt, int is_negative, char *num_str)
{
	if (is_negative)
		return (1);
	if ((fmt->plus || fmt->space)
		&& (fmt->specifier == 'd' || fmt->specifier == 'i'))
		return (1);
	if (fmt->hash && num_str[0] != '0'
		&& (fmt->specifier == 'x' || fmt->specifier == 'X'))
		return (2);
	return (0);
}

static int	print_prefix(t_format *fmt, int is_negative, int len, char *num_str)
{
	if (is_negative)
	{
		ft_putchar_fd('-', 1);
		len++;
	}
	else if ((fmt->specifier == 'd' || fmt->specifier == 'i')
		&& (fmt->plus || fmt->space))
	{
		if (fmt->plus)
			ft_putchar_fd('+', 1);
		else if (fmt->space)
			ft_putchar_fd(' ', 1);
		len++;
	}
	else if (fmt->hash && num_str[0] != '0'
		&& (fmt->specifier == 'x' || fmt->specifier == 'X'))
	{
		if (fmt->specifier == 'x')
			ft_putstr_fd("0x", 1);
		else if (fmt->specifier == 'X')
			ft_putstr_fd("0X", 1);
		len += 2;
	}
	return (len);
}

static int	print_left_padding(t_format *fmt, int num_len, char pad)
{
	int	len;

	len = 0;
	while (!fmt->minus && fmt->width-- > num_len)
	{
		ft_putchar_fd(pad, 1);
		len++;
	}
	return (len);
}

static int	print_number_body(t_format *fmt, char *num_str, int num_len)
{
	int	len;

	len = 0;
	while (fmt->dot && fmt->precision-- > (int)ft_strlen(num_str))
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	ft_putstr_fd(num_str, 1);
	len += (int)ft_strlen(num_str);
	while (fmt->minus && fmt->width-- > num_len)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	return (len);
}

int	print_formatted_number(t_format *fmt, char *num_str, int is_negative)
{
	int		len;
	int		num_len;
	char	pad;

	num_len = ft_strlen(num_str);
	len = 0;
	pad = ' ';
	if (fmt->zero && !fmt->minus && !fmt->dot)
		pad = '0';
	if (fmt->dot && fmt->precision == 0 && num_str[0] == '0')
	{
		while (fmt->width-- > 0)
			len += write(1, " ", 1);
		return (len);
	}
	if (fmt->dot && fmt->precision > (int)ft_strlen(num_str))
		num_len = fmt->precision;
	num_len += get_prefix_len(fmt, is_negative, num_str);
	if (fmt->zero && !fmt->dot)
		len += print_prefix(fmt, is_negative, 0, num_str);
	len += print_left_padding(fmt, num_len, pad);
	if (!fmt->zero || (fmt->zero && fmt->dot))
		len += print_prefix(fmt, is_negative, 0, num_str);
	len += print_number_body(fmt, num_str, num_len);
	return (len);
}
