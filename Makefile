INCLUDES = -I/usr/include -Ilibft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LD_FLAGS = -Llibft -l:libft.a

SRC = main.c utils.c lst_utils.c

OBJ = $(SRC:.c=.o)

TARGET = push_swap

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET): make_libs $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LD_FLAGS) -o $(TARGET) 

make_libs:
	make -C libft

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(TARGET)
	make -C libft fclean

re: fclean all