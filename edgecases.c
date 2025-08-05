/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edgecases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:39:37 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/31 13:44:15 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

size_t	stack_len(t_num **a)
{
	size_t	i;

	i = 0;
	while (a[i])
		i ++;
	return (i);
}

void	rthreeb(t_num **a, t_num **b, char **str)
{
	size_t	i;

	i = 0;
	while (i < 10)
	{
		if (sort_check(a, b) == 1)
			return (ft_putstr_fd(*str, 1),
				free_arr(a), free_arr(b), free(*str), exit(1));
		if (b[1] != NULL && b[2] != NULL
			&& b[1]->expected > b[2]->expected
			&& b[2]->expected > b[0]->expected)
			rb(a, b, str);
		else if (b[0] != NULL && b[1] != NULL
			&& b[0]->expected < b[1]->expected)
			sb (a, b, str);
		else if (b[1] != NULL && b[2] != NULL
			&& b[1]->expected < b[2]->expected)
			rrb(a, b, str);
		i ++;
	}
}

void	six(t_num **a, t_num **b, char **str)
{
	size_t	len;
	size_t	i;

	len = stack_len(a);
	i = 0;
	if (sort_check(a, b) == 1)
		return (ft_putstr_fd(*str, 1),
			free(*str), free_arr(a), free_arr(b), exit(1));
	while (i < len)
	{
		if (a[0]->expected < len / 2)
			pb(a, b, str);
		else
			ra(a, b, str);
		i ++;
	}
	three(a, b, str);
	rthreeb(a, b, str);
	i = 0;
	while (b[0])
		pa(a, b, str);
	return (ft_putstr_fd(*str, 1), free_arr(a),
		free_arr(b), free(*str), exit(1));
}

int	sort_check(t_num **a, t_num **b)
{
	size_t	i;

	if (b[0] != NULL)
		return (0);
	i = 0;
	while (a[i])
	{
		if (a[i]->expected != i)
			return (0);
		i ++;
	}
	return (1);
}

void	three(t_num **a, t_num **b, char **str)
{
	size_t	i;

	i = 0;
	while (i < 10)
	{
		if (sort_check(a, b) == 1)
			return (ft_putstr_fd(*str, 1),
				free_arr(a), free_arr(b), free(*str), exit(1));
		if (a[1] != NULL && a[2] != NULL && a[1]->expected < a[2]->expected
			&& a[2]->expected < a[0]->expected)
			ra(a, b, str);
		else if (a[0] != NULL && a[1] != NULL
			&& a[0]->expected > a[1]->expected)
			sa (a, b, str);
		else if (a[1] != NULL && a[2] != NULL
			&& a[1]->expected > a[2]->expected)
			rra(a, b, str);
		i ++;
	}
}
