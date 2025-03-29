NAME = libft.a


SRCS = ft_memset.c \
		ft_atoi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c  ft_putnbr_fd.c 


OBJS = ${SRCS:.c=.o}


LIBC = ar rc
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	$(LIBC) $(NAME) $(OBJS)


%.o: %.c libft.h
	@${CC} ${CFLAGS} -c $< -o $@



clean:
	@${RM} ${OBJS} 
	
fclean: clean
	@${RM} ${NAME} 

re: fclean all

.PHONY: clean 