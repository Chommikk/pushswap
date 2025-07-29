# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 12:26:33 by mchoma            #+#    #+#              #
#    Updated: 2025/07/29 13:22:45 by mchoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./libft.h
FILES = main.c\
		utils.c\
		inputcheck.c
OBJ = $(FILES:.c=.o)


all : $(OBJ) $(NAME)
	

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -o $(NAME)


%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	rm -f $(OBJ) $(BOBJ) bonus

fclean : clean
	rm -f $(NAME) bonus

re : fclean all


test: 
	$(CC) $(CFLAGS)  $(OBJ) libft.a -o $(NAME)
	
bonus : $(BOBJ) $(NAME)
	ar rsc $(NAME) $(BOBJ)
	touch bonus

.PHONY: re fclean clean all
