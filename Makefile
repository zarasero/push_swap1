# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zserobia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 15:55:01 by zserobia          #+#    #+#              #
#    Updated: 2024/07/23 14:03:43 by zserobia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAMESC =	action_2.c action_3.c action.c check_argum.c create_sort_stack.c \
		create_stack.c create_tlist.c radix_sort.c main.c \
		create_sort_stack_2.c create_stack_2.c
		
		
NAMESO = $(NAMESC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = cc

all: $(NAME)

$(NAME): $(NAMESO)
	cc -o $(NAME) $(NAMESO)

%.o: %.c
	@echo "Compiling $< into $@"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAMESO)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean
