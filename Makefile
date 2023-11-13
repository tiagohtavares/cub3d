# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 11:09:11 by ttavares          #+#    #+#              #
#    Updated: 2023/11/13 12:22:43 by ttavares         ###   ########.fr        #
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

SRCS =	./srcs/main ./srcs/read_map ./srcs/init ./srcs/player_position\
		./srcs/keys ./srcs/error ./srcs/raycast ./srcs/draw \
		./get_next_line/get_next_line ./get_next_line/get_next_line_utils

OBJS = $(SRCS:=.o)

NAME = cub3d

all:	$(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) -g $(OBJS) $(MINILIBX) -I./includes -lXext -lX11 -lm $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re:	fclean all bonus

debug:
	${MAKE} DEBUG=1 all

run: all
	${MAKE} clean
	./cub3d ./assets/test.cub

mem:
	${MAKE} DEBUG=1
	${MAKE} clean
	valgrind ${VFLAGS} ./cub3d ./assets/test.cub
