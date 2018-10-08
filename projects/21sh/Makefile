# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppavlich <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/04 15:28:56 by ppavlich          #+#    #+#              #
#    Updated: 2017/09/05 17:06:49 by ppavlich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

IDIR = includes/

VPATH = src:includes

FLAGS = -Wall -I$(IDIR) -g

LIB = libft/libft.a

SRCS = main.c										\
			check_command.c 						\
			splitspaces.c							\
			errors.c								\
			functions.c								\
			functions2.c							\
			functions3.c							\
			comands.c								\

BINS = $(SRCS:.c=.o)

all: $(NAME)

makelib:
	make -C libft/

libclean:
	make -C libft/ clean

libfclean:
	make -C libft/ fclean

$(NAME): $(BINS)
	make -C libft/
	gcc -o $(NAME) $(FLAGS) $(BINS) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	make -C libft/ clean
	/bin/rm -f $(BINS)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
