# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 11:09:11 by ttavares          #+#    #+#              #
#    Updated: 2023/10/30 16:06:01 by ttavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	= ./libft/libft.a
LIBFT_DIR = ./libft

MINILIBX = ./minilibx-linux/libmlx_Linux.a
MINILIBX_DIR = ./minilibx-linux

CC	= cc -Wall -Wextra -Werror
RM	= rm -f

SRCS =	./srcs/main ./srcs/read_map ./srcs/init ./srcs/draw ./srcs/player_position \
		./srcs/keys \
		./get_next_line/get_next_line ./get_next_line/get_next_line_utils

OBJS = $(SRCS:=.o)

NAME = cub3d

all:	$(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) -g $(OBJS) $(MINILIBX) -lXext -lX11 -lm $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS) 
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

fclean:	clean
	$(RM) $(NAME) 
	make fclean -C $(LIBFT_DIR)

re:	fclean all bonus
