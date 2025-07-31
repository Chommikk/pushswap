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
#include <stdio.h>
void	rthree(t_num **a, t_num **b, char **str);

void	six(t_num **a, t_num **b, char **str)
{
	size_t	len;
	size_t	i;

	len = stack_len(a);
	i = 0;
	if (sort_check(a, b) == 1)
		return  (ft_putstr_fd(*str, 1), free(*str), free_arr(a), free_arr(b), exit(1));
	while (i < len)
	{
		if (a[0]->expected < len / 2)
			pb(a, b, str);
		else
			ra(a, b, str);
		i ++;
	}
	three(a, b, str);
	rthree(b, a, str);
	i = 0;
	while (b[0])
		pa(a, b, str);
	free_arr(a);
	printf("----\n");
	free_arr(b);
	// return  (ft_putstr_fd(*str, 1), free_arr(a), free_arr(b), free(*str), exit(1));
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

//give a flag to the funcion that will do it for b not for a
void	rthree(t_num **a, t_num **b, char **str)
{
	size_t	i;

	i = 0;
	while (i < 10)
	{
		if (sort_check(a, b) == 1)
			return  (ft_putstr_fd(*str, 1), free_arr(a), free_arr(b), free(*str), exit(1));
		if (a[1] != NULL && a[2] != NULL && a[1] ->expected > a[2]->expected && a[2]->expected > a[0]->expected)
			ra(a, b, str);
		else if (a[0] != NULL && a[1] != NULL && a[0]->expected < a[1]->expected)
			sa (a, b, str);
		else if (a[1] != NULL && a[2] != NULL && a[1] ->expected < a[2]->expected)
			rra(a, b, str);
		i ++;
	}
}

void	three(t_num **a, t_num **b, char **str)
{
	size_t	i;

	i = 0;
	while (i < 10)
	{
		if (sort_check(a, b) == 1)
			return  (ft_putstr_fd(*str, 1), free_arr(a), free_arr(b), free(*str), exit(1));
		if (a[1] != NULL && a[2] != NULL && a[1] ->expected < a[2]->expected && a[2]->expected <a[0]->expected)
			ra(a, b, str);
		else if (a[0] != NULL && a[1] != NULL && a[0]->expected > a[1]->expected)
			sa (a, b, str);
		else if (a[1] != NULL && a[2] != NULL && a[1] ->expected > a[2]->expected)
			rra(a, b, str);
		i ++;
	}
}
