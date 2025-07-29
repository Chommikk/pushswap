/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:09:17 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/29 13:15:00 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> //delete later

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while(str[i])
		i ++;
	return (i);
}

void	put_str_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	put_error()
{
	put_str_error("Error\n");
}

void	free_arr(void *arr)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return;
	while(((char **)arr)[i])
	{
		free(((char **)arr)[i]);
		i ++;
	}
	free(arr);
}

long	*copy_long_arr(long *arr)
{
	size_t	i;
	long	*rt;
	
	i = 0;
	while (arr[i] != (long) INT_MIN -1)
		i++;
	rt = ft_calloc(i + 1, sizeof(long));
	if (rt == NULL)
		return (NULL);
	i = 0;
	rt[0] = arr[0];
	while (arr[i++] != (long) INT_MIN -1)
		rt[i] = arr[i];
	return (rt);
}

long	*buble_sort(long *arr)
{
	size_t	i;
	long	tmp;
	int		bool;
	long	*rt;
	
	i = 0;
	bool = 1;
	rt = copy_long_arr(arr);
	while (bool && rt)
	{
		i = 1;
		bool = 0;
		while (rt[i] != (long) INT_MIN - 1)
		{
			if (rt[i] < rt [i -1] && ++bool)
			{
				tmp = rt[i];
				rt[i] = rt[i - 1];
				rt[i - 1] = tmp;
			}
			i ++;
		}
	}
	return (rt);
}
