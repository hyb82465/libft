/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:47:35 by yihe              #+#    #+#             */
/*   Updated: 2025/05/21 12:14:01 by yihe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	free_all(char **arr, int n)
{
	while (--n >= 0)
		free(arr[n]);
	free(arr);
	return (0);
}

static int	populate_result(char **result, char const *s, char c)
{
	int	i;
	int	start;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			result[index] = ft_substr(s, start, i - start);
			if (!result[index])
				return (free_all(result, index));
			index++;
		}
	}
	result[index] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc ((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!populate_result(result, s, c))
		return (NULL);
	return (result);
}
