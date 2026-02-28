# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hohu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/28 13:24:55 by hohu              #+#    #+#              #
#    Updated: 2026/02/28 14:47:39 by hohu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      := push_swap
CC        := cc
CFLAGS    := -Wall -Wextra -Werror -g -O0
RM        := rm -f

LIBFT_DIR := libft
LIBFT     := $(LIBFT_DIR)/libft.a

INC_DIR   := inc
HEADER    := $(INC_DIR)/push_swap.h
INCLUDES  := -I$(INC_DIR) -I$(LIBFT_DIR)

SRC_DIR   := src
SRC       := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parse.c \
	$(SRC_DIR)/stack_utils.c

OBJS      := $(SRC:.c=.o)

.PHONY: all clean fclean re libft

all: $(NAME)

# 1) build libft first
libft:
	$(MAKE) -C $(LIBFT_DIR)

# 2) link executable with libft
$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# 3) compile .c -> .o
%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
