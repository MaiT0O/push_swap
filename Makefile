# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 13:36:18 by ebansse           #+#    #+#              #
#    Updated: 2025/02/10 15:50:37 by ebansse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I/usr/include -Ilibft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LD_FLAGS = -Llibft -l:libft.a

SRC = main.c tiny_sort.c turkey_sort.c move.c cost.c
MOVEMENTS = movements/push.c movements/rotate.c movements/r_rotate.c movements/swap.c
TOOLS = tools/lst_utils.c tools/split.c tools/utils.c tools/utils2.c tools/pars_free.c

OBJ = $(SRC:.c=.o)
MOVEMENTS_OBJ = $(MOVEMENTS:.c=.o)
TOOLS_OBJ = $(TOOLS:.c=.o)

TARGET = push_swap

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET): make_libs $(OBJ) $(MOVEMENTS_OBJ) $(TOOLS_OBJ)
	$(CC) $(OBJ) $(MOVEMENTS_OBJ) $(TOOLS_OBJ) $(CFLAGS) $(LD_FLAGS) -o $(TARGET) 

make_libs:
	make -C libft

clean:
	rm -rf $(OBJ) $(MOVEMENTS_OBJ) $(TOOLS_OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(TARGET)
	make -C libft fclean

re: fclean all