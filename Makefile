# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 13:36:18 by ebansse           #+#    #+#              #
#    Updated: 2025/02/05 13:55:20 by ebansse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I/usr/include -Ilibft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LD_FLAGS = -Llibft -l:libft.a

SRC = main.c utils.c lst_utils.c push.c rotate.c r_rotate.c swap.c tiny_sort.c split.c

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