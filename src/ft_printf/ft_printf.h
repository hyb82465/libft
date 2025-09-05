/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:52:43 by yihe              #+#    #+#             */
/*   Updated: 2025/06/24 13:05:12 by yihe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../../libft.h"

typedef struct s_format
{
	int		minus;
	int		zero;
	int		dot;
	int		width;
	int		precision;
	int		plus;
	int		space;
	int		hash;
	char	specifier;
}	t_format;

int		ft_printf(const char *format, ...);
void	parse_format(const char *format, int *i, t_format *fmt);
char	*ft_ultoa_base(unsigned long long n, char *base);

int		print_formatted_char(t_format *fmt, char c);
int		print_formatted_string(t_format *fmt, char *str);
int		print_formatted_pointer(t_format *fmt, void *ptr);
int		print_formatted_int(t_format *fmt, int n);
int		print_formatted_unsigned(t_format *fmt, unsigned int n);
int		print_formatted_hex(t_format *fmt, unsigned int n);
int		print_formatted_number(t_format *fmt, char *num_str, int is_negative);

#endif
