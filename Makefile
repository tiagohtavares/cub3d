# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 11:09:11 by ttavares          #+#    #+#              #
#    Updated: 2023/11/29 16:32:47 by heda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	= ./libft/libft.a
LIBFT_DIR = ./libft

MINILIBX = ./minilibx-linux/libmlx_Linux.a
MINILIBX_DIR = ./minilibx-linux

CC	= cc -Wall -Wextra -Werror
RM	= rm -f

includes = includes

VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

ifdef DEBUG

CC += -g

endif

ifdef LOG

VFLAGS+= --log-file=mem.log

endif

SRCS =	./srcs/main ./srcs/read_map ./srcs/init ./srcs/player_position \
	./srcs/keys ./srcs/keys_utils ./srcs/error ./srcs/raycast \
	./srcs/raycast_utils ./srcs/textures ./srcs/textures_utils \
	./srcs/texture_check ./srcs/texture_check_utils ./srcs/map_check \
	./srcs/map_check_utils \
	./srcs/debug \
	./get_next_line/get_next_line ./get_next_line/get_next_line_utils

SRCS_B = ./bonus/srcs/main ./bonus/srcs/read_map ./bonus/srcs/init \
	./bonus/srcs/player_position ./bonus/srcs/keys ./bonus/srcs/keys_utils \
	./bonus/srcs/error ./bonus/srcs/raycast ./bonus/srcs/raycast_utils \
	./bonus/srcs/textures ./bonus/srcs/textures_utils ./bonus/srcs/texture_check \
	./bonus/srcs/texture_check_utils ./bonus/srcs/map_check \
	./bonus/srcs/map_check_utils ./bonus/srcs/mouse \
	./bonus/srcs/debug \
	./get_next_line/get_next_line ./get_next_line/get_next_line_utils

OBJS = $(SRCS:=.o)
OBJS_B = $(SRCS_B:=.o)

NAME = cub3d
NAME_B = cub3d_bonus

all: $(NAME)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) -g $(OBJS) $(MINILIBX) -I./includes -lXext -lX11 -lm $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

fclean:	clean
	$(RM) $(NAME) $(NAME_B)
	make fclean -C $(LIBFT_DIR)

re:	fclean all

bonus: $(NAME_B)

$(NAME_B): $(OBJS_B) $(LIBFT) $(MINILIBX)
	$(CC) -g $(OBJS_B) $(MINILIBX) -I./includes -lXext -lX11 -lm $(LIBFT) -o $(NAME_B)

debug:
	${MAKE} DEBUG=1 re

run: all
	${MAKE} clean
	./cub3d ./assets/maps/valid/map.cub

mem:
	${MAKE} DEBUG=1
	${MAKE} clean
	valgrind ${VFLAGS} ./cub3d ./assets/maps/valid/map.cub

debugb:
	${MAKE} fclean
	${MAKE} DEBUG=1 bonus

runb: bonus
	${MAKE} clean
	./cub3d_bonus ./assets/maps/bonus/valid/map.cub

memb:
	${MAKE} DEBUG=1 bonus
	${MAKE} clean
	valgrind ${VFLAGS} ./cub3d_bonus ./assets/maps/bonus/valid/map.cub
