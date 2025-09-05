/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:15:27 by yihe              #+#    #+#             */
/*   Updated: 2025/05/21 14:30:02 by yihe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_length(int n)
{
	int	len;

	len = (n <= 0);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	len = count_length(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	sign = 1;
	if (n < 0)
		sign = -1;
	while (len--)
	{
		str[len] = '0' + (n % 10) * sign;
		n /= 10;
		if (len == 0 && sign == -1)
			str[len] = '-';
	}
	return (str);
}
