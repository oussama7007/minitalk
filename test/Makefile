NAME = client server

CC = cc 

INCLUDES = -I includes

CFLAGS = -Wall -Werror -Wextra

LIBFT_SRC_FILES = $(addprefix libft/, ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_putchar_fd.c ft_striteri.c ft_strmapi.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c)

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
