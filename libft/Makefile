# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshad <mshad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 22:12:38 by mshad             #+#    #+#              #
#    Updated: 2021/12/08 22:19:59 by mshad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -I.
CC		= gcc

SRC		= src/ft_itoa.c \
		  src/ft_strchr.c \
		  src/ft_strdup.c \
		  src/ft_strlen.c \
		  src/ft_strncmp.c \
		  src/get_next_line.c \
		  src/ft_strjoin.c \
		  src/ft_strcpy.c \
		  src/ft_memcmp.c \
		  src/ft_putstr_fd.c \
		  
OBJ		= $(SRC:%.c=%.o)

.PHONY: all clean fclean re norm

all: $(NAME)

.o: .c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	ar rcs $@ $?
	ranlib $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
