SRC	=	get_next_line.c get_next_line_utils.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc
RM	=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
AR     =	ar

NAME	=	gnl.a

all:	$(OBJ)
	@$(AR) rc $(NAME) $(OBJ)
	@echo "Build complete: $(NAME)"

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all
