/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:03:02 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/29 13:15:43 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>


/*takes array of malloced strings and atoi tham to a array of longs int 
INT_MIN -1  is end of array INT_MAX + 1 is invalid valu
frees the strings*/
long	*split_to_arr(char **arr);
long	satoi_safe(char *str);
//end of array is (long)INT_MIN - 1
long	*append_long(long *stack, long thing);
void	free_split(char **arr);
char	*ft_strjoinf1(char *s1, char *s2);
void	put_error();
#endif
