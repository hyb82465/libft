/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:44:56 by yihe              #+#    #+#             */
/*   Updated: 2025/06/06 15:48:20 by yihe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ultoa_base(unsigned long long n, char *base)
{
	char	buffer[65];
	int		base_len;
	int		i;
	char	*result;

	i = 64;
	base_len = 0;
	while (base[base_len])
		base_len++;
	buffer[i--] = '\0';
	if (n == 0)
		buffer[i--] = base[0];
	while (n > 0)
	{
		buffer[i--] = base[n % base_len];
		n /= base_len;
	}
	result = ft_strdup(&buffer[i + 1]);
	return (result);
}
