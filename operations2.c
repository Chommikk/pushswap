/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:42:12 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/30 12:24:12 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	pa(t_num **a, t_num **b, char *str)
{
	t_num	*tmp;

	if (str != NULL)
	{
		str = ft_strjoinf1(str, "pa\n");
		if (str == NULL)
			return (free_arr(a), free_arr(b));
	}
	push_arr(a, 0);
	a[0] = b[0];
	pull_arr(b, 0);
}

void	pb(t_num **a, t_num **b, char *str)
{
	if (str != NULL)
	{
		str = ft_strjoinf1(str, "pb\n");
		if (str == NULL)
			return (free_arr(a), free_arr(b));
	}
	push_arr(b, 0);
	b[0] = a[0];
	pull_arr(a, 0);
}

void	ra(t_num **a, t_num **b, char *str)
{
	t_num	*tmp;
	size_t	i;

	i = 0;
	if (str != NULL)
	{
		str = ft_strjoinf1(str, "ra\n");
		if (str == NULL)
			return (free_arr(a), free_arr(b));
	}
	tmp = a[0];
	pull_arr(a, 0);
	while (a[i])
		a++;
	a[i] = tmp;
}

void	rb(t_num **a, t_num **b, char *str)
{
	t_num	*tmp;
	size_t	i;

	i = 0;
	if (str != NULL)
	{
		str = ft_strjoinf1(str, "rb\n");
		if (str == NULL)
			return (free_arr(a), free_arr(b));
	}
	tmp = b[0];
	pull_arr(b, 0);
	while (b[i])
		b++;
	b[i] = tmp;
}

void	rr(t_num **a, t_num **b, char *str)
{
	if (str != NULL)
	{
		str = ft_strjoinf1(str, "rr\n");
		if (str == NULL)
			return (free_arr(a), free_arr(b));
	}
	ra(a, b, NULL);
	rb(a, b, NULL);
}
