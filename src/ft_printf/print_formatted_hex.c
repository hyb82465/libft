/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formatted_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:35:51 by yihe              #+#    #+#             */
/*   Updated: 2025/06/07 14:56:42 by yihe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_formatted_hex(t_format *fmt, unsigned int n)
{
	char	*num_str;
	int		len;

	if (fmt->specifier == 'x')
		num_str = ft_ultoa_base((unsigned long long)n, "0123456789abcdef");
	else
		num_str = ft_ultoa_base((unsigned long long)n, "0123456789ABCDEF");
	len = print_formatted_number(fmt, num_str, 0);
	free(num_str);
	return (len);
}
