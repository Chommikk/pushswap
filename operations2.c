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

void	pa(t_num **a, t_num **b, char **str)
{
	if (*str != NULL)
	{
		*str = ft_strjoinf1(*str, "pa\n");
		if (*str == NULL)
		{
			return (free_arr(a), free_arr(b), put_error(), exit(1));
		}
	}
	push_arr(a);
	a[0] = b[0];
	pull_arr(b);
}

void	pb(t_num **a, t_num **b, char **str)
{
	if (*str != NULL)
	{
		*str = ft_strjoinf1(*str, "pb\n");
		if (*str == NULL)
			return (free_arr(a), free_arr(b), put_error(), exit(1));
	}
	push_arr(b);
	b[0] = a[0];
	pull_arr(a);
}

void	ra(t_num **a, t_num **b, char **str)
{
	t_num	*tmp;
	size_t	i;

	i = 0;
	if (*str != NULL)
	{
		*str = ft_strjoinf1(*str, "ra\n");
		if (*str == NULL)
			return (free_arr(a), free_arr(b), put_error(), exit(1));
	}
	if (a[0] == NULL)
		return ;
	tmp = a[0];
	while (a[i])
		i++;
	pull_arr(a);
	a[i - 1] = tmp;
}

void	rb(t_num **a, t_num **b, char **str)
{
	t_num	*tmp;
	size_t	i;

	i = 0;
	if (*str != NULL)
	{
		*str = ft_strjoinf1(*str, "rb\n");
		if (*str == NULL)
			return (free_arr(a), free_arr(b), put_error(), exit(1));
	}
	if (b[0] == NULL)
		return ;
	tmp = b[0];
	while (b[i])
		i++;
	pull_arr(b);
	b[i - 1] = tmp;
}

void	rr(t_num **a, t_num **b, char **str)
{
	char	*s;

	s = NULL;
	if (*str != NULL)
	{
		*str = ft_strjoinf1(*str, "rr\n");
		if (*str == NULL)
			return (free_arr(a), free_arr(b), put_error(), exit(1));
	}
	ra(a, b, &s);
	rb(a, b, &s);
}
