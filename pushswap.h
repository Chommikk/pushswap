/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:03:02 by mchoma            #+#    #+#             */
/*   Updated: 2025/07/30 13:23:54 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//smallest is index 0 and that is also top
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_num
{
	size_t	expected;
	long	org_nbr;
}	t_num;

/*takes array of malloced strings and atoi tham to a array of longs int 
INT_MIN -1  is end of array INT_MAX + 1 is invalid valu
frees the strings*/
long	*split_to_arr(char **arr);
void	three(t_num **a, t_num **b, char **str);
long	*buble_sort(long *arr);
size_t	stack_len(t_num **a);
int	sort_check(t_num **a, t_num **b);
size_t	ft_pow(size_t x, size_t y);
void	six(t_num **a, t_num **b, char **str);
void	free_arr(t_num **arr);
long	satoi_safe(char *str);
//end of array is (long)INT_MIN - 1
size_t	sq_rt(size_t x, size_t y);
long	*append_long(long *stack, long thing);
void	free_split(char **arr);
char	*ft_strjoinf1(char *s1, char *s2);
void	put_error();
void	radix(t_num **a, t_num **b, char *str);
void	sa(t_num **a, t_num **b, char **str);
void	sb(t_num **a, t_num **b, char **str);
void	ss(t_num **a, t_num **b, char **str);
void	pa(t_num **a, t_num **b, char **str);
void	pb(t_num **a, t_num **b, char **str);
void	ra(t_num **a, t_num **b, char **str);
void	rb(t_num **a, t_num **b, char **str);
void	rr(t_num **a, t_num **b, char **str);
void	rra(t_num **a, t_num **b, char **str);
void	rrb(t_num **a, t_num **b, char **str);
void	rrr(t_num **a, t_num **b, char **str);
void	pull_arr(t_num **arr);
void	push_arr(t_num **arr);

#endif
