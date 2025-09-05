/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formatted_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:07:42 by yihe              #+#    #+#             */
/*   Updated: 2025/06/06 15:45:12 by yihe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_formatted_unsigned(t_format *fmt, unsigned int n)
{
	char	*num_str;
	int		len;

	num_str = ft_ultoa_base((unsigned long long)n, "0123456789");
	len = print_formatted_number(fmt, num_str, 0);
	free(num_str);
	return (len);
}
