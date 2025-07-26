# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 12:26:33 by mchoma            #+#    #+#              #
#    Updated: 2025/05/01 12:26:38 by mchoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./libft.h
FILES = ft_bzero.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_itoa.c  ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c \
ft_strchr.c ft_strdup.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c \
ft_substr.c ft_tolower.c ft_toupper.c \
ft_calloc.c ft_split.c
OBJ = $(FILES:.c=.o)
BFILE = ft_lstadd_back_bonus.c\
ft_lstadd_front_bonus.c\
ft_lstclear_bonus.c\
ft_lstiter_bonus.c\
ft_lstlast_bonus.c\
ft_lstmap_bonus.c\
ft_lstnew_bonus.c\
ft_lstdelone_bonus.c\
ft_lstsize_bonus.c
BOBJ = $(BFILE:.c=.o)
INV = .inviz


all : $(OBJ) $(NAME)
	

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)


%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
	
test% : ft_test_%.c $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@
	$(CC) $(CFLAGS) $< $(NAME) -lcriterion -o -g $@.out
	@./$@.out

clean :
	rm -f $(OBJ) $(BOBJ) bonus

fclean : clean
	rm -f $(NAME) bonus

re : fclean all

$(INV) :
	touch .inviz

bonus : $(BOBJ) $(NAME)
	ar rsc $(NAME) $(BOBJ)
	touch bonus

.PHONY: re fclean clean all
