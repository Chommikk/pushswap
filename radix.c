/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:22:14 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/30 13:33:01 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
#include "libft.h"
#include <stdio.h> //delete

void	radix_alg(t_num **a, t_num **b, char **str, size_t scale)
{
	size_t	size;

	size = 0;
	while(a[size])
		size++;
	while(size)
	{
		if ((a[0]->expected & (1 << scale)) == 0)
			pb(a, b, str);
		else
			ra(a, b, str);
		size --;
	}
	while(b[0])
		pa(a, b, str);
}

void	radix(t_num **a, t_num **b, char *str)
{
	size_t	size;
	size_t	scale;

	scale = 0;
	size = 0;
	while(a[size])
		size++;
	size = sq_rt(size, 2);
	while(scale < size)
	{
		radix_alg(a, b, &str, scale);
		scale ++;
	}
	ft_putstr_fd(str, 1);
	free(str);
	free_arr(a);
	// printf("----\n");
	free_arr(b);
	exit(1);
}
