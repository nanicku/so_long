# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshad <mshad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 22:09:50 by mshad             #+#    #+#              #
#    Updated: 2022/03/10 14:28:28 by mshad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -I. -Imlx -Ilibft

ifeq ($(MAKECMDGOALS),bonus)
	OBJ = $(SRC_BONUS:%.c=%.o)
else
	OBJ = $(SRC:%.c=%.o)
endif

SRC		= src/main.c \
		src/parser_map.c \
		src/check_map.c \
		src/exit.c \
		src/draw_map.c \
		src/moves.c \
		src/player_collectibles.c

SRC_BONUS	= src_bonus/main_b.c \
		src_bonus/parser_map_b.c \
		src_bonus/check_map_b.c \
		src_bonus/exit_b.c \
		src_bonus/draw_map_b.c \
		src_bonus/moves_b.c \
		src_bonus/player_collectibles_b.c \
		src_bonus/coconut_anim_b.c


.PHONY: all re clean fclean libft mlx

.o: .c
	$(CC) $(CFLAGS) -Imlx $< -o $@

all: mlx libft $(NAME)

$(NAME): $(OBJ) so_long.h
	$(CC) $(OBJ) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

bonus: mlx libft $(NAME)

mlx:
	make -C mlx/

libft:
	make -C libft/

clean:
	make -C mlx/ clean
	make -C libft/ clean
	rm -f $(OBJ)
	rm -f src_bonus/*.o

fclean: clean
	rm -f mlx/libmlx.a
	rm -f libft/libft.a
	rm -f $(NAME)
	rm -f so_long
	rm -rf a.out*
	rm -rf */a.out*
	rm -rf *.gch
	rm -rf */*.gch
	rm -f libft/libft.a
	
re: fclean all
