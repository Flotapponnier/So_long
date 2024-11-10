CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/ -I./libft/includes -I./mlx
RM = rm -rf
NAME = so_long

SRCS = srcs/so_long.c
SRCSMAPVERIF = srcs/map_verification/verify_map.c \
               srcs/map_verification/utils/mapvalid_utils.c \
               srcs/map_verification/utils/ismap_valid.c \
               srcs/map_verification/utils/floodmap.c \
               srcs/map_verification/utils/check_row.c \
               srcs/mlx_game/launch_game.c \
               srcs/mlx_game/mapping/background.c \
               srcs/mlx_game/mapping/draw_map.c \
               srcs/mlx_game/event/key_event.c \
               srcs/mlx_game/event/movement/player_movement_right.c \
               srcs/mlx_game/event/movement/player_movement_up.c \
               srcs/mlx_game/event/movement/player_movement_left.c \
               srcs/mlx_game/event/movement/player_movement_down.c \
			   srcs/mlx_game/event/movement/player_movement_utils.c \
               srcs/mlx_game/event/is_move_valid.c \
               srcs/error/error.c \
               srcs/mlx_game/initialisation/initialisation.c

OBJS = $(SRCS:.c=.o) $(SRCSMAPVERIF:.c=.o)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
    LFLAGS = -L./mlx -lmlx -lz -framework OpenGL -framework AppKit  # For macOS
else
    LFLAGS = -L./mlx -lmlx -lz -lX11 -lXext -lXrender -lm  # For Linux
endif

all: $(NAME)

# Linking object files and creating the executable
$(NAME): $(OBJS)
	$(MAKE) -C ./libft  # Ensure libft is built
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS) -Llibft -lft

clean:
	$(MAKE) clean -C ./libft  # Clean libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft  # Clean libft completely
	$(RM) $(NAME)

re: fclean all

libft:
	$(MAKE) -C ./libft

