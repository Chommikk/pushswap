/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:09:02 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/29 13:18:20 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "pushswap.h"

long	*split_to_arr(char **arr)
{
	size_t	i;
	long	*stack;

	i = 0;
	while (arr[i])
		i ++;
	stack = malloc (sizeof(long) * (i + 1));
	if (stack == NULL)
		return (free_split(arr), NULL);
	i = 0;
	while (arr[i])
	{
		stack[i] = satoi_safe(arr[i]);
		if (stack [i] == (long) INT_MAX + 1)
			return (free_split(arr), free(stack), NULL);
		i ++;
	}
	stack[i] = (long)INT_MIN -1;
	free_split(arr);
	return (stack);
}

long	satoi_safe(char *str)
{
	long	number;
	long	pon;
	size_t	i;

	pon = 1;
	i = 0;
	number = 0;
	if (str [i] && str[i] == '-' && ++ i)
		pon = -1;
	if (!(str[i] <= '9' && str[i] >= '0'))
		return ((long) INT_MAX + 1);
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		number = number * 10 + str[i] - '0';
		if ((pon == 1 && number > (long)INT_MAX)
			|| (pon == -1 && pon * number < (long)INT_MIN))
			return ((long)INT_MAX + 1);
		i ++;
	}
	if (str[i])
		return ((long)INT_MAX + 1);
	number = number * pon;
	return (number);
}

long	*append_long(long *stack, long thing)
{
	size_t	i;
	long	*ptr;

	if (stack == NULL)
	{
		ptr = malloc (sizeof(long) * 2);
		if (!ptr)
			return (NULL);
		ptr[0] = thing;
		ptr[1] = (long)INT_MIN - 1;
		return (ptr);
	}
	i = 0;
	while (stack[i] != (long)INT_MIN - 1)
		i ++;
	ptr = malloc (sizeof(long) * i + 2);
	if (ptr == NULL)
		return (free(stack), ptr);
	i = 0;
	while (stack[i ++] != (long)INT_MIN - 1)
		ptr[i - 1] = stack[i - 1];
	ptr[i - 1] = thing;
	ptr[i] = (long)INT_MIN - 1;
	return (free(stack), ptr);
}

void	free_split(char **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i ++;
		}
		free(arr);
	}
}

char	*ft_strjoinf1(char *fr, char *str)
{
	char	*tmp;

	tmp = ft_strjoin(fr, str);
	free(fr);
	return (tmp);
}
