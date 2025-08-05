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

void	put_error(void)
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
		return ;
	while (((char **)arr)[i])
	{
		free(((char **)arr)[i]);
		i ++;
	}
	free(arr);
}
