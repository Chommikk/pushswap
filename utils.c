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
#include "pushswap.h" // delete later
#include <stdio.h> //delete later

void	put_str_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	put_error()
{
	put_str_error("Error\n");
}
//x to the power of y
size_t	ft_pow(size_t x, size_t y)
{
	if (y == 0)
		return (1);
	while (y)
	{
		x = x * x;
		y --;
	}
	return (x);
}

size_t	sq_rt(size_t x, size_t y)
{
	size_t	i;
	
	i = 0;
	while (x)
	{
		x = x / y;
		i ++;
	}
	return (i);
}

void	free_arr(t_num **arr)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return;
	while(((char **)arr)[i])
	{
		printf("%li\n", ((t_num**)arr)[i]->org_nbr);
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
