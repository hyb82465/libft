/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formatted_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:02:48 by yihe              #+#    #+#             */
/*   Updated: 2025/06/06 17:21:58 by yihe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_formatted_int(t_format *fmt, int n)
{
	char		*num_str;
	int			is_negative;
	int			len;

	if (n == -2147483648)
	{
		is_negative = 1;
		num_str = ft_strdup("2147483648");
	}
	else if (n < 0)
	{
		is_negative = 1;
		num_str = ft_itoa(-n);
	}
	else
	{
		is_negative = 0;
		num_str = ft_itoa(n);
	}
	len = print_formatted_number(fmt, num_str, is_negative);
	free(num_str);
	return (len);
}
