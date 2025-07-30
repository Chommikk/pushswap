/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:00:37 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/30 13:23:59 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"
#include <stdio.h> //remove

char	**formating_input(int argc, char **argv)
{
	char	**arr;
	size_t	i;

	arr = NULL;
	i = 0;
	if (argc == 2)
	{
		arr = ft_split (argv[1], ' ');
		if (arr == NULL)
			return (put_error(), NULL);
	}
	else 
	{
		arr = ft_calloc (sizeof(void *), argc);
		if (arr == NULL)
			return (put_error(), NULL);
		while(i < (unsigned long) argc - 1)
		{
			arr[i]  = ft_strdup(argv[i + 1]);
			if (arr[i] == NULL)
				return (put_error(), free_arr((t_num **)arr), NULL);
			i ++;
		}
	}
	return (arr);
}

int	double_check(long *arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while(arr[i] != (long) INT_MIN - 1)
	{
		if (arr[i] == (long) INT_MAX + 1)
			return (0);
		j = i + 1;
		while(arr[j] != (long)INT_MIN - 1)
		{
			if (arr[j] == arr[i])
				return (0);
			j ++;
		}
		i ++;
	}
	if (i == 0)
		return (0);
	return (1);
}

long	get_index(long *arr, long j)
{
	size_t	i;

	i = 0;
	while (arr[i] != (long) INT_MIN -1)
	{
		if (arr[i] == j)
			return (i);
		i++;
	}
	return (i);
}

int	fill_struct(t_num ***stacka, long *arr)
{
	size_t	i;
	t_num	*element;
	long	*sorted;

	i = 0;
	sorted = buble_sort(arr);
	if (sorted == NULL)
		return (free(*stacka), free(arr), 0);
	while(arr[i] != (long)INT_MIN - 1)
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

void	sort(t_num **a, t_num **b)
{
	char	*str;

	str = ft_strdup("");
	if (str == NULL)
	{
		free_arr(a);
		free_arr(b);
		put_error();
		exit (0);
	}
	
	radix(a, b, str);
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

int main(int argc, char **argv)
{
	long	*stack;
	//long	i;
	char	**arr;
	size_t j;

	j = 0;
	if (argc == 1)
		return (0);
	arr = formating_input(argc, argv);
	if (arr == NULL)
		return (1);
	stack = split_to_arr(arr);
	if (stack == NULL)
		return (put_error(), 1);
	if (double_check(stack) == 0)
		return (free(stack), put_error(), 1);
	
	initialize(stack);
	return (0);
}
