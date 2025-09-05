/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formatted_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:54:54 by yihe              #+#    #+#             */
/*   Updated: 2025/06/06 14:19:21 by yihe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_formatted_char(t_format *fmt, char c)
{
	int	len;

	len = 0;
	if (!fmt->minus)
	{
		while (fmt->width > 1)
		{
			len += write(1, " ", 1);
			fmt->width--;
		}
	}
	len += write(1, &c, 1);
	if (fmt->minus)
	{
		while (fmt->width > 1)
		{
			len += write(1, " ", 1);
			fmt->width--;
		}
	}
	return (len);
}
