# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 10:49:52 by auskola-          #+#    #+#              #
#    Updated: 2023/09/21 14:34:01 by auskola-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = gcc 

CFLAGS	= -Wall -Wextra -Werror

MLXFLAGS = -framework OpenGL -framework AppKit 

MLX =  libmlx.a

SRC_FILES = src/animate.c src/check_load.c src/ft_itoa.c src/functions.c \
src/get_next_line.c src/get_next_line_util.c src/keyboard.c src/load.c \
src/main_load.c src/main.c src/map_draw.c src/memory.c src/move.c \
src/panel.c src/print.c src/so_long_utils.c src/sprites.c src/check_map.c

SRC_FILES_BONUS  = src_bonus/animate_bonus.c src_bonus/animate_bonus_2.c \
src_bonus/check_load_bonus.c src_bonus/enemy_bonus.c \
src_bonus/enemy_bonus2.c src_bonus/enemy_bonus_3.c \
src_bonus/enemy_bonus_4.c \
src_bonus/enemy_bonus_keys.c src_bonus/ft_itoa_bonus.c \
src_bonus/functions_bonus.c src_bonus/get_next_line_bonus.c \
src_bonus/get_next_line_util_bonus.c src_bonus/keyboard_bonus.c \
src_bonus/load_bonus.c src_bonus/main_bonus.c src_bonus/main_load_bonus.c \
src_bonus/map_draw_bonus.c src_bonus/memory_bonus.c \
src_bonus/move_bonus.c src_bonus/panel_bonus.c src_bonus/print_bonus.c \
src_bonus/so_long_utils_bonus.c src_bonus/sprites_bonus.c \
src_bonus/threads_bonus.c src_bonus/check_map_bonus.c

#MLXFLAGS = -framework OpenGL -framework AppKit

INCLUDE = src/so_long.h src/get_next_line.h 
INCLUDE_BONUS = src_bonus/so_long_bonus.h src_bonus/get_next_line_bonus.h 

OBJS = $(SRC_FILES:.c=.o)
OBJS_BONUS = $(SRC_FILES_BONUS:.c=.o)

#gcc src/*.c minilibx/libmlx.a -o so_long -framework OpenGL -framework AppKit -Werror -Wextra -Wall 
#gcc src_bonus/*.c minilibx/libmlx.a -o so_long_bonus -framework OpenGL -framework AppKit -Werror -Wextra -Wall 

all: mlx $(NAME) 

bonus: mlx $(NAME_BONUS)

mlx:
	@make -C minilibx all 2> mlx_warning 
	@cp minilibx/$(MLX) $(MLX)

$(NAME): $(OBJS)  $(INCLUDE)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX) -o $(NAME)  
#	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -> si fuera un ejecutable
#	ar rc $(NAME) $(OBJS) $(BONUS_OBJS) >  ar rc para hacer libreria

$(NAME_BONUS): $(OBJS_BONUS) $(INCLUDE_BONUS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS_BONUS) $(MLX) -o $(NAME_BONUS) 

clean:
	rm -f $(OBJS)   
	rm -f $(OBJS_BONUS)
	rm -f $(MLX)
	make -C minilibx clean
	rm -f mlx_warning 
fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re bonus