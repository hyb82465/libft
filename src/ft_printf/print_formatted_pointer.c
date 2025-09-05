/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formatted_pointer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:09:24 by yihe              #+#    #+#             */
/*   Updated: 2025/06/09 18:08:12 by yihe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_formatted_pointer(t_format *fmt, void *ptr)
{
	char	*str;
	char	*full_str;
	int		full_len;
	int		len;

	len = 0;
	if (!ptr)
		full_str = "(nil)";
	else
	{
		str = ft_ultoa_base((unsigned long long)ptr, "0123456789abcdef");
		full_str = ft_strjoin("0x", str);
		free(str);
	}
	full_len = ft_strlen(full_str);
	if (!fmt->minus)
		while (fmt->width-- > full_len)
			len += write(1, " ", 1);
	len += write(1, full_str, full_len);
	if (fmt->minus)
		while (fmt->width-- > full_len)
			len += write(1, " ", 1);
	if (ptr)
		free(full_str);
	return (len);
}
