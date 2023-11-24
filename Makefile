# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 11:09:11 by ttavares          #+#    #+#              #
#    Updated: 2023/11/24 16:14:20 by heda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#LIBS
LIBFT= ${LIBFT_DIR}/libft.a
LIBFT_LIB= -L${LIBFT_DIR} -lft

MINILIBX = ./minilibx-linux/libmlx_Linux.a
MINILIBX_DIR = ./minilibx-linux

CC	= cc -Wall -Wextra -Werror
RM	= rm -f

#DIRECTORIES
SRCS_DIR= srcs
INC= includes
OBJ_DIR= obj
LIBFT_DIR= libft

VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

ifdef DEBUG

CC += -g

endif

ifdef LOG

VFLAGS+= --log-file=mem.log

endif

SRCF =	main read_map init player_position \
		keys keys_utils error raycast raycast_utils textures textures_utils texture_check \
		texture_check_utils map_check map_check_utils \
		debug

SRCS= $(addprefix ${SRCS_DIR}/, $(addsuffix .c, ${SRCF}))
OBJS= $(addprefix ${OBJ_DIR}/, $(addsuffix .o, ${SRCF}))
SRCSB= $(addprefix ${SRCS_DIR}/, $(addsuffix .c, ${SRCBF}))
OBJSB= $(addprefix ${OBJ_DIR}/, $(addsuffix .o, ${SRCBF}))

NAME = cub3d

all: $(NAME)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(OBJS) -I./${INC} ${LIBFT_LIB} $(MINILIBX) -lXext -lX11 -lm -o $(NAME)

${OBJ_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJ_DIR}
	${CC} ${CFLAGS} -I./${INC} -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re:	fclean all

debug:
	${MAKE} DEBUG=1 re

run: all
	${MAKE} clean
	./cub3d ./assets/maps/valid/map.cub

mem:
	${MAKE} DEBUG=1
	${MAKE} clean
	valgrind ${VFLAGS} ./cub3d ./assets/maps/valid/map.cub
