CLIENT = client
SERVER = server

CC = cc 

INCLUDES = -I includes

CFLAGS = -Wall -Werror -Wextra 

SRC_CLIENT = mandatory/client.c
SRC_SERVER = mandatory/server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

LIBFT = libft/libft.a

# Correct target format
all: $(CLIENT) $(SERVER)

# Ensure Libft is compiled before client/server
$(LIBFT): 
	make -C libft

# Compile client
$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

# Compile server
$(SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)

# Rule to compile .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Cleanup
clean:
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)
	make clean -C libft

fclean: clean
	rm -rf $(CLIENT) $(SERVER)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
