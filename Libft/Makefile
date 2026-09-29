NAME = libft.a

CC = cc

CFLAGS = -Werror -Wall -Wextra -I includes

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
