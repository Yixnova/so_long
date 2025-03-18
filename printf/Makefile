NAME = libftprintf.a

SRCS = ft_printf.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar -rc

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@echo "Library $(NAME) built successfully."

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
