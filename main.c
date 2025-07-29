/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:00:37 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/29 13:25:41 by mchoma           ###   ########.fr       */
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
			i ++;
		}
	}
	return (arr);
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
		return (put_error(), 1);
	stack = split_to_arr(arr);
	if (stack == NULL)
		return (put_error(), 1);
	if (double_check(stack) == 0)
		return (put_error(), 0);
	
	while(stack && stack[j] != (long)INT_MIN - 1)
	{
		printf("%li \n", stack[j]);
		j ++;
	}
	return (free(stack), 0);
	
}
