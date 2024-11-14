# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 21:07:58 by matle-br          #+#    #+#              #
#    Updated: 2024/11/07 12:58:02 by matle-br         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
FLAGS = -Wall -Wextra -Werror -O3 -mtune=native -flto -g3
MLX_FLAGS = -L$(PATH_MINILIBX) -lmlx -lX11 -lXext -lm -lz -lXfixes
GREEN = \033[32m
YELLOW = \033[33m
ROUGE = \033[1;31m

LIBFT_A = ./includes/libft/libft.a
PATH_MINILIBX = /home/matle-br/sgoinfre/minilibx-linux

RM = rm -f

SRC_DIR = src
SRC_EVENTS_DIR = events
SRC_INIT_DIR = init
SRC_OTHER_DIR = other
SRC_PARSING_DIR = parsing
SRC_RAYCASTING_DIR = raycasting

EVENTS_FILES = events.c events2.c events3.c
INIT_FILES = init.c init2.c
OTHER_FILES = free.c get_next_line.c images.c
PARSING_FILES = check_input.c check_map.c parsing_utils.c parsing_utils2.c parsing_utils3.c
RAYCASTING_FILES = raycasting_utils.c raycasting_utils2.c raycasting.c minimap.c sprites.c sprites2.c

SRCS = $(addprefix $(SRC_DIR)/,main.c \
	$(addprefix $(SRC_EVENTS_DIR)/,$(EVENTS_FILES)) \
	$(addprefix $(SRC_INIT_DIR)/,$(INIT_FILES)) \
	$(addprefix $(SRC_OTHER_DIR)/,$(OTHER_FILES)) \
	$(addprefix $(SRC_PARSING_DIR)/,$(PARSING_FILES)) \
	$(addprefix $(SRC_RAYCASTING_DIR)/,$(RAYCASTING_FILES)))

OBJ_DIR = obj_dir
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)


all: $(NAME)

$(NAME) : $(LIBFT_A) $(OBJ) $(SRCS)
		@$(CC) $(SRCS) $(LIBFT_A) $(FLAGS) $(MLX_FLAGS) -o $(NAME)
		@echo "$(YELLOW)Creating the objects..."
		@echo "$(GREEN)$(NAME) has compiled !"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -I$(PATH_MINILIBX) -c $< -o $@

$(LIBFT_A) :
	@echo "$(YELLOW)Libft is compiling..."
	@make bonus --no-print-directory -C ./includes/libft

clean :
	@$(RM) -r $(OBJ_DIR)
	@make clean --no-print-directory -C ./includes/libft

fclean : clean
	@$(RM) $(NAME) $(OBJ_DIR)
	@make fclean --no-print-directory -C ./includes/libft
	@echo "$(ROUGE)Fclean is running..."

re : fclean all

bonus : all

.PHONY: all clean fclean re
