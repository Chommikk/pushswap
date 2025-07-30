/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:19:04 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/30 12:25:19 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	rrb(t_num **a, t_num **b, char *str)
{
	t_num	*tmp;
	size_t	i;

	i = 0;
	if (str != NULL)
	{
		str = ft_strjoinf1(str, "rrb\n");
		if (str == NULL)
			return (free_arr(a), free_arr(b));
	}
	while (b[i])
		b++;
	tmp = b[i];
	b[i] = NULL;
	push_arr(b, 0);
	b[0] = tmp;
}

void	rra(t_num **a, t_num **b, char *str)
{
	t_num	*tmp;
	size_t	i;

	i = 0;
	if (str != NULL)
	{
		str = ft_strjoinf1(str, "rra\n");
		if (str == NULL)
			return (free_arr(a), free_arr(b));
	}
	while (a[i])
		a++;
	tmp = a[i];
	a[i] = NULL;
	push_arr(a, 0);
	a[0] = tmp;
}

void	rrr(t_num **a, t_num **b, char *str)
{
	if (str != NULL)
	{
		str = ft_strjoinf1(str, "rrr\n");
		if (str == NULL)
			return (free_arr(a), free_arr(b));
	}
	rra(a, b, NULL);
	rrb(a, b, NULL);
}
