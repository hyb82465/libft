/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formatted_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:59:10 by yihe              #+#    #+#             */
/*   Updated: 2025/06/09 17:56:17 by yihe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_formatted_string(t_format *fmt, char *str)
{
	int	len;
	int	str_len;

	len = 0;
	if (!str)
	{
		if (fmt->dot && fmt->precision < 5)
			str = "";
		else
			str = "(null)";
	}
	str_len = ft_strlen(str);
	if (fmt->dot && fmt->precision < str_len)
		str_len = fmt->precision;
	if (!fmt->minus)
		while (fmt->width-- > str_len)
			len += write(1, " ", 1);
	len += write(1, str, str_len);
	if (fmt->minus)
		while (fmt->width-- > str_len)
			len += write(1, " ", 1);
	return (len);
}
