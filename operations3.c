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
#include <stdio.h> //remove

void	rrb(t_num **a, t_num **b, char **str)
{
	t_num	*tmp;
	size_t	i;

	i = 0;
	if (*str != NULL)
	{
		*str = ft_strjoinf1(*str, "rrb\n");
		if (*str == NULL)
			return (free_arr(a), free_arr(b), put_error(), exit(1));
	}
	while (b[i])
		i++;
	tmp = b[i];
	b[i] = NULL;
	push_arr(b);
	b[0] = tmp;
}

void	rra(t_num **a, t_num **b, char **str)
{
	t_num	*tmp;
	size_t	i;

	i = 0;
	if (*str != NULL)
	{
		*str = ft_strjoinf1(*str, "rra\n");
		if (*str == NULL)
			return (free_arr(a), free_arr(b), put_error(), exit(1));
	}
	while (a[i])
		i++;
	tmp = a[i - 1];
	// printf("<|%lu|>\n", tmp->org_nbr);
	a[i - 1] = NULL;
// printf("%lu == i\n", i);
	// i = 0;
	// while(a[i])
	// {
		// printf("\\|%lu|/\n", a[i]->org_nbr);
		// i ++;
	// }
	push_arr(a);
	a[0] = tmp;
	i = 0;
	while(a[i])
	{
		printf("|%lu|\n", a[i]->org_nbr);
		i ++;
	}
}

void	rrr(t_num **a, t_num **b, char **str)
{
	char	*s;

	s = NULL;
	if (*str != NULL)
	{
		*str = ft_strjoinf1(*str, "rrr\n");
		if (*str == NULL)
			return (free_arr(a), free_arr(b), put_error(), exit(1));
	}
	rra(a, b, &s);
	rrb(a, b, &s);
}
