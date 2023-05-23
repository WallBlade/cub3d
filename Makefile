SRCS 	=	src/parsing/parsing.c src/parsing/get_next_line.c src/parsing/garbage_collector.c \
			src/parsing/parsing_utils.c src/parsing/err_map_closed.c src/parsing/init.c src/utils/utils.c \
			src/parsing/err_map_elem.c src/display/draw/draw.c src/display/draw/events.c \
			src/display/raycaster/raycasting.c src/display/raycaster/raycasting_utils.c src/display/draw/events_utils.c \
			src/utils/free.c src/display/raycaster/get_textures.c src/parsing/init_utils.c \
			src/display/draw/draw_utils.c src/main.c \

OBJ		=	$(SRCS:.c=.o)

CC		=	@cc
RM		=	@rm -rf
CFLAGS	=	-Wall -Wextra -g3 -I./includes

NAME	=	cub3D

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
				@echo "\n"
				@echo "\033[32m$ ----- CUB ! -----"
				@echo "\n"
				@make -C libft
				@ar -rcs libft/libft.a
				@cp libft/libft.a libft.a
				$(CC) $(OBJ) libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
clean:
				@$(RM) $(OBJ)
				@make clean -sC libft
				@$(RM) libft.a

fclean:		clean
				$(RM) $(NAME)
				@$(RM) libft.a
				@make fclean -sC libft

re:			fclean $(NAME)

.PHONY:		all clean fclean re