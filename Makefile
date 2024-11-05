CC = cc
CFLAGS = -Wall -Wextra -Werror -I../includes/ -I./libft/includes
RM = rm -rf
NAME = so_long

SRCS = srcs/so_long.c srcs/verify_map.c
OBJS = $(SRCS:.c=.o)

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
