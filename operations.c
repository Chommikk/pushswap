/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:42:12 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/30 12:23:11 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
#include <stdio.h> //remove

void	sa(t_num **a, t_num **b, char **str)
{
	t_num	*tmp;

	if (a[0] != NULL && a[1] != NULL)
	{
		if (*str != NULL)
		{
			*str = ft_strjoinf1(*str, "sa\n");
			if (*str == NULL)
				return (free_arr(a), free_arr(b), put_error(), exit(1));
		}
		tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
	}
}

void	sb(t_num **a, t_num **b, char **str)
{
	t_num	*tmp;

	if (b[0] != NULL && b[1] != NULL)
	{
		if (*str != NULL)
		{
			*str = ft_strjoinf1(*str, "sb\n");
			if (*str == NULL)
				return (free_arr(a), free_arr(b), put_error(), exit(1));
		}
		tmp = b[0];
		b[0] = b[1];
		b[1] = tmp;
	}
}

void	ss(t_num **a, t_num **b, char **str)
{
	char	*s;

	s = NULL;
	if (*str != NULL)
	{
		*str = ft_strjoinf1(*str, "ss\n");
		if (*str == NULL)
			return (free_arr(a), free_arr(b), put_error(), exit(1));
	}
	sa(a, b, &s);
	sb(a, b, &s);
}

void	push_arr(t_num **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	while (i)
	{
		arr[i] = arr[i - 1];
		i --;
	}
}

void	pull_arr(t_num **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		arr[i] = arr[i + 1];
		i ++;
	}
}
