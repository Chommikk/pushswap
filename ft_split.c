/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:52:52 by mchoma            #+#    #+#             */
/*   Updated: 2025/05/07 18:52:54 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	**free_all(void **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i ++;
	}
	free(ptr);
	return (0);
}

size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	amount;

	i = 0;
	amount = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			amount ++;
			while (s[i] && s[i] != c)
				i ++;
		}
		else
			i ++;
	}
	return (amount);
}

char	**appendptr(char **ptr, const char *str, size_t len)
{
	size_t	i;
	char	*str2;

	i = 0;
	while (ptr[i])
		i++;
	str2 = ft_substr(str, 0, len);
	if (str2 == 0)
		return ((char **)free_all((void **)ptr));
	ptr[i] = str2;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**arr;

	i = 0;
	arr = ft_calloc(word_count(s, c) + 1, sizeof(void **));
	if (arr == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j])
				j ++;
			arr = appendptr(arr, &s[i], j);
			if (arr == NULL)
				return (NULL);
			i = i + j;
		}
		else
			i ++;
	}
	return (arr);
}
