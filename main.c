#include "pushswap.h"
#include "libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long	*split_to_arr(char **arr);

long	satoi_safe(char *str)
{
	long	number;
	long	pon;
	size_t	i;

	pon = 1;
	i = 0;
	number = 0;
	if (str [i] && str[i] == '-' && ++ i)
		pon = -1;
	if (!(str[i] <= '9' && str[i] >= '0'))
		return ((long) INT_MAX + 1);
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		number = number * 10 + str[i] - '0';
		if ((pon == 1 && number > (long)INT_MAX) || (pon == -1 && number < (long)INT_MIN))
			return ((long)INT_MAX + 1);
		i ++;
	}
	if (str[i])
		return ((long)INT_MAX + 1);
	number = number * pon;
	if ((pon == 1 && number > (long)INT_MAX) || (pon == -1 && number < (long)INT_MIN))
		return ((long)INT_MAX + 1);
	return (number);
}

//end of array is (long)INT_MIN - 1
long	*append_long(long *stack, long thing)
{
	size_t	i;
	long	*ptr;

	if(stack == NULL)
	{
		ptr = malloc (sizeof(long) * 2);
		if(!ptr)
			return (NULL);
		ptr[0] = thing;
		ptr[1] = (long)INT_MIN - 1;
		return (ptr);
	}
	i = 0;
	while(stack[i] != (long)INT_MIN - 1)
		i ++;
	ptr = malloc (sizeof(long) * i + 2);
	if (ptr == NULL)
		return (free(stack), ptr);
	i = 0;
	while(stack[i ++] != (long)INT_MIN - 1)
		ptr[i - 1] = stack[i - 1];
	ptr[i - 1] = thing;
	ptr[i] = (long)INT_MIN - 1;
	return (free(stack), ptr);
}

void	free_split(char ***arr)
{
	size_t	i;

	i = 0;
	if (*arr)
	{
		while(*arr[i])
		{
			free(*arr[i]);
			i ++;
		}
		free(*arr);
		*arr = NULL;
	}
}

char	*ft_strjoinf1(char *s1, char *s2)
{
	char	*fin;

	fin = ft_strjoin(s1, s2);
	return (free(s1), fin);
}

char	**read_fromt_stdin(void)
{
	size_t	i;
	char	buff[1024];
	char	*str;
	char	**arr;
	ssize_t	read_stuff;

	str = NULL;
	while (1)
	{
		read_stuff = read(1, buff, 1023);
		buff[read_stuff] = 0;
		if (read_stuff == 0)
			break;
		if (read_stuff == -1)
			return (free(str), NULL);
		str = ft_strjoinf1(str, buff);
		if (str == NULL)
			return (NULL);
	}
	arr  = ft_split(str, ' ');
	return (arr);
}

char	**formating_input(int argc, char **argv)
{
	char	**arr;
	size_t	i;

	arr = NULL;
	i = 0;
	if (argc == 1)
		arr = read_from_stdin();
	if (argc == 2)
	{
		arr = ft_split (argv[1], ' ');
		if (arr == NULL)
			return (NULL); //print error\n
	}
	else 
	{
		arr = ft_calloc (sizeof(void *), argc);
		if (arr == NULL)
			return (NULL); //print error \n
		while(i < argc - 1)
		{
			arr[i]  = ft_strdup(argv[i + 1]); //you need trim here i dont knwo why it doens't work
			i ++;
		}
	}
	return (arr)
}

int main(int argc, char **argv)
{
	long	*stack;
	long	i;
	char	**arr;
	size_t j;

	j = 0
	arr = formating_input(argc, argv);
	if (arr == NULL)
		return (1); //print error\n
	stack = split_to_arr(arr);
	if (stack == NULL)
		return (1); //print error \n
	
	while(stack && stack[j] != (long)INT_MIN - 1)
	{
		printf("%li \n", stack[j]);
		j ++;
	}
	return (free(stack), 0);
	
}

//takes array of malloced strings and atoi tham to a array of longs int 
//INT_MIN -1  is end of array INT_MAX + 1 is invalid valu
//frees the strings
long	*split_to_arr(char **arr)
{
	size_t	i;
	long	*stack;

	i = 0;
	while(arr[i])
		i ++;
	stack = malloc (sizeof(long) * (i + 1));
	if (stack == NULL)
		return (free_split(arr), NULL);
	i = 0;
	while(arr[i]) 
	{
		stack[i] = satoi_safe(arr[i]);
		if (stack [i] == (long) INT_MAX + 1)
			return (free_split(arr), free(stack), NULL);
		i ++;
	}
	stack[i] = (long)INT_MIN  -1;
	free_split(arr);
	return (stack);
}
