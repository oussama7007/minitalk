NAME = minitalk

CLIENT = client
SERVER = server

CC = cc 

INCLUDES = -I includes

Cflags = -Wall -Werror -Wextra 

SRC = mandatory/client.c \
	  mandatory/server.c

OBJS = $(SRC:.c=.o)

LIBFT = libft/libft.a

all = $(NAME)

$(LIBFT) : 
	make -C libft

$(NAME) : $(OBJS)
	$(CC) $(Cflags) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)

%.o : %.c includes/minitalk.h libft/libft.h
	$(CC) $(Cflags) $(INCLUDES) -c $< -o $@

clean :
	rm -rf $(OBJS)
	make clean -C libft

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: clean

