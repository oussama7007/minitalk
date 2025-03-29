NAME = client server

CC = cc 

INCLUDES = -I includes

CFLAGS = -Wall -Werror -Wextra

LIBFT_SRC_FILES = $(addprefix libft/,ft_memset.c ft_atoi.c ft_putchar_fd.c  ft_putstr_fd.c  ft_putnbr_fd.c )

SRC_FILES = $(addprefix mandatory/, server.c client.c)

OBJS = $(SRC_FILES:.c=.o)

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_SRC_FILES)
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) mandatory/client.o $(LIBFT) -o client
	$(CC) $(CFLAGS) $(INCLUDES) mandatory/server.o $(LIBFT) -o server

%.o: %.c includes/minitalk.h  libft/libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS)
	@make clean -C libft

fclean: clean
	rm -rf $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re