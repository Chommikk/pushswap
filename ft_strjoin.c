/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:50:27 by mchoma            #+#    #+#             */
/*   Updated: 2025/04/26 14:50:30 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	counter;
	int		counter2;
	char	*str;

	counter = 0;
	counter2 = 0;
	while (s1[++ counter - 1])
		;
	while (s2[++ counter2 - 1])
		;
	str = malloc(sizeof(char) * (counter + counter2 - 1));
	if (!str)
		return (NULL);
	counter = 0;
	counter2 = 0;
	while (s1[++ counter -1])
		str[counter -1] = s1[counter -1];
	while (s2[++ counter2 -1])
		str[counter + counter2 - 2] = s2[counter2 -1];
	str[counter2 + counter - 2] = 0;
	return (str);
}
