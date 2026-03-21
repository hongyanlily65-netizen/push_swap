NAME      := push_swap
CC        := cc
CFLAGS    := -Wall -Wextra -Werror -g -O0
RM        := rm -f

LIBFT_DIR := ./libft
LIBFT     := $(LIBFT_DIR)/libft.a

INC_DIR   := include/
HEADER    := $(INC_DIR)/push_swap.h
INCLUDES  := -I$(INC_DIR) -I$(LIBFT_DIR)

SRC_DIR   := src/
UTILS_DIR   := utils/
SRC       := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parse.c \
	$(UTILS_DIR)/stack_utils.c \
	$(SRC_DIR)/index.c \
	$(SRC_DIR)/init_config.c \
	$(SRC_DIR)/handle_flags.c\
	$(UTILS_DIR)/utils_sort.c \
	$(SRC_DIR)/radix_sort.c \
	$(SRC_DIR)/selection_sort.c \
	$(SRC_DIR)/chunk_sort.c \
	$(SRC_DIR)/instrucciones_push.c \
	$(SRC_DIR)/instrucciones_rotate.c \
	$(SRC_DIR)/instrucciones_reverse.c \
	$(SRC_DIR)/instrucciones_swap.c \
	$(SRC_DIR)/free.c \
	$(SRC_DIR)/disorder_indice.c \
	$(SRC_DIR)/init_bench.c \
	$(UTILS_DIR)/parse_utils.c\
	$(UTILS_DIR)/stack_init.c 

OBJS      := $(SRC:.c=.o)

.PHONY: all clean fclean re libft

all: $(NAME)

# 1) build libft first
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# 2) link executable with libft
$(NAME): $(OBJS) $(LIBFT)
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
