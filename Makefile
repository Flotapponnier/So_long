CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/ -I./libft/includes -I./mlx
RM = rm -rf
NAME = so_long

SRCS = srcs/so_long.c
SRCSMAPVERIF = srcs/map_verification/verify_map.c \
               srcs/map_verification/utils/mapvalid_utils.c \
               srcs/map_verification/utils/ismap_valid.c \
               srcs/map_verification/utils/floodmap.c \
               srcs/mlx_game/launch_game.c

# Combine both source variables
OBJS = $(SRCS:.c=.o) $(SRCSMAPVERIF:.c=.o)

# Conditional to differentiate between macOS and Linux
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
    LFLAGS = -L./mlx -lmlx -lz -framework OpenGL -framework AppKit  # For macOS
else
    LFLAGS = -L./mlx -lmlx -lz -lX11 -lXext -lXrender -lm  # For Linux
endif

# Default rule to build the project
all: $(NAME)

# Linking object files and creating the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS) -Llibft -lft

# Clean object files
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

# Clean object and binary files
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Phony targets to avoid conflicts with file names
.PHONY: all clean fclean re

