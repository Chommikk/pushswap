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
		while (i < (unsigned long) argc - 1)
		{
			arr[i] = ft_strdup(argv[i + 1]);
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
	while (arr[i] != (long) INT_MIN - 1)
	{
		if (arr[i] == (long) INT_MAX + 1)
			return (0);
		j = i + 1;
		while (arr[j] != (long)INT_MIN - 1)
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

void	sort(t_num **a, t_num **b)
{
	char	*str;
	size_t	len;

	str = ft_strdup("");
	if (str == NULL)
	{
		free_arr(a);
		free_arr(b);
		put_error();
		exit (0);
	}
	len = stack_len(a);
	if (len <= 3)
	{
		three(a, b, &str);
		exit(1);
	}
	if (len <= 6)
	{
		six(a, b, &str);
		exit(1);
	}
	radix(a, b, str);
}

int	main(int argc, char **argv)
{
	long	*stack;
	char	**arr;

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
