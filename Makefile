CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
NAME = so_long
MINILIBX_LINUX = minilibx

SRCS = ./srcs/main.c ./srcs/map_sizer.c ./srcs/ber_check.c \
	./srcs/get_next_line.c ./srcs/get_next_line_utils.c \
	./srcs/ft_strlen.c ./srcs/map_creation.c ./srcs/ft_strtrim.c \
	./srcs/check_map.c ./srcs/layout_errors.c \
	./srcs/print_moves.c ./srcs/symbol_control.c \
	./srcs/struct_initiation.c ./srcs/elements_control.c \
	./srcs/lets_play.c ./srcs/find_xpm.c ./srcs/render_map.c \
	./srcs/find_player.c ./srcs/movements.c ./srcs/game_over.c \
	./srcs/flood_fill.c ./srcs/handle_mov.c ./srcs/handle_updates.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

${NAME}: ${OBJS}
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) -L./minilibx-linux -lXext -lX11 minilibx-linux/libmlx.a -o $(NAME)

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME) so_little
	
re: fclean all

# Rule used to make so_long work on my personal laptop:

little_laptop: ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) minilibx-linux/libmlx.a -lGL -lGLU -lXrandr -lXext -lX11 -o so_little

# This last make rule was used (a lot) while working on 
# this project in order to quickly download and configure
# minilibx-linux. It depends on https://github.com/42Paris/minilibx-linux,
# and it was last used 20/04/2023:

minilibx:
	git clone git@github.com:42Paris/minilibx-linux.git
	make -C minilibx-linux
