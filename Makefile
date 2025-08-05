# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 12:26:33 by mchoma            #+#    #+#              #
#    Updated: 2025/07/30 13:34:06 by mchoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = main.c\
		utils.c\
		utils2.c\
		inputcheck.c\
		operations.c\
		operations2.c\
		operations3.c\
		radix.c\
		edgecases.c\
		ft_calloc.c\
		ft_putstr_fd.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_split.c\
		ft_strdup.c\
		ft_substr.c
OBJ = $(FILES:.c=.o)


all : $(OBJ) $(NAME)
	

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -o $(NAME)


%.o : %.c libft.h
	$(CC) $(CFLAGS) -c   $< -o $@
	
clean :
	rm -f $(OBJ) $(BOBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all


test: 
	cc -Wall -Wextra *.c libft.a -g -o $(NAME)
	
bonus : $(BOBJ) $(NAME)
	ar rsc $(NAME) $(BOBJ)
	touch bonus

.PHONY: re fclean clean all
