UNAME := $(shell uname)

# Includes y Flags
ifeq ($(UNAME), Linux)
    INCLUDES = -I./minilibx-linux -I/usr/include -Imlx
    MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib/X11 -lXext -lX11
else
    INCLUDES = -I/opt/X11/include -Imlx
    MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

# Variables
NAME = so_long
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
SRCS = src/so_long.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Reglas
all: $(MLX_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_DIR) clean

re: fclean all
