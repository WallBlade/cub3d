SRCS 	=	src/parsing/parsing.c \

OBJ		=	$(SRCS:.c=.o)

CC		=	@cc
RM		=	@rm -rf
CFLAGS	=	-Wall -Werror -Wextra -g3 -I./includes

NAME	=	cub3D

all:		$(NAME)

$(NAME):	$(OBJ)
				@echo "\n"
				@echo "\033[32m$ ----- CUB ! -----"
				@echo "\n"
				$(CC) $(OBJ) -o $(NAME)

clean:
				@$(RM) $(OBJ)

fclean:		clean
				$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re