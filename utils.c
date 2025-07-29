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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while(str[i])
		i ++;
	return (i);
}

void	put_str_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	put_error()
{
	put_str_error("Error\n");
}
