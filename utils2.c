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
#include "pushswap.h"

int	fill_struct(t_num ***stacka, long *arr)
{
	size_t	i;
	t_num	*element;
	long	*sorted;

	i = 0;
	sorted = buble_sort(arr);
	if (sorted == NULL)
		return (free(*stacka), free(arr), 0);
	while (arr[i] != (long)INT_MIN - 1)
	{
		element = ft_calloc(sizeof(t_num), 1);
		if (element == NULL)
			return (free_arr(*stacka), free(arr), free(sorted), 0);
		element->org_nbr = arr[i];
		element->expected = get_index(sorted, arr[i]);
		(*stacka)[i] = element;
		i++;
	}
	return (free(sorted), 1);
}

void	initialize(long *arr)
{
	t_num	**stacka;
	t_num	**stackb;
	size_t	i;

	i = 0;
	while (arr[i] != (long)INT_MIN -1)
		i++;
	stacka = ft_calloc(sizeof(t_num **), i + 2);
	stackb = ft_calloc(sizeof(t_num **), i + 2);
	if (stacka == NULL || stackb == NULL)
		return (free(stacka), free(stackb), free(arr), put_error(), exit(1));
	if (fill_struct(&stacka, arr) == 0)
		return (free(stackb), put_error(), exit(1));
	free(arr);
	sort(stacka, stackb);
	return (exit(1));
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
