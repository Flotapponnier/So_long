CC = cc 
CFLAGS = -Wall -Wextra -Werror -I./includes/ -I./libft/includes
RM = rm -rf
NAME = so_long

SRCS = srcs/so_long.c
SRCSMAPVERIF = srcs/map_verification/verify_map.c \
			   srcs/map_verification/utils/mapvalid_utils.c \
			   srcs/map_verification/utils/ismap_valid.c \
			   srcs/map_verification/utils/floodmap.c

# Combine both source variables
OBJS = $(SRCS:.c=.o) $(SRCSMAPVERIF:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT:
