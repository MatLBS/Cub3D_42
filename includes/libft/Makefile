# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 10:26:01 by matle-br          #+#    #+#              #
#    Updated: 2024/11/07 10:33:26 by matle-br         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
		ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
		ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
		ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memcpy.c \
		ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
		ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
		ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
		ft_printf.c print_smt.c ft_strcpy.c ft_strcmp.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

RM = rm -f
OBJS = $(SRC_DIR:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
RAN = ranlib
AR = ar -rc

all: $(NAME)

%.o : %.c
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RAN) $(NAME)

bonus : $(OBJS) $(BONUS_OBJS)
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	@$(RAN) $(NAME)

clean :
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
