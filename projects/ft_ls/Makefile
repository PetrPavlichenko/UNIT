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

NAME = ft_ls

IDIR = includes/

VPATH = src:includes

FLAGS = -Wall -Wextra -Werror -I$(IDIR) -g

LIB = libft/libft.a

SRCS = main.c										\
			check_inp.c								\
			errors.c								\
			init.c									\
			list.c									\
			sort.c									\
			sort2.c									\
			l.c										\
			ft_itoa_base.c							\
			calc_space.c							\
			output.c 								\
			input.c									\
			calc_space2.c							\

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
