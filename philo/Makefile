# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 08:54:25 by fvon-nag          #+#    #+#              #
#    Updated: 2023/07/31 14:30:39 by fvon-nag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES = main.c \
		ft_atoi.c \
		utils.c \
		locking.c \
		libft_functions.c \
		main_2.c \
		utils_2.c \





BSOURCES =





OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread -fsanitize=thread

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

bonus: $(BOBJECTS) libft
	$(CC) $(CFLAGS) -o checker $(BOBJECTS)

clean:
	rm -f $(OBJECTS) $(BOBJECTS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus libft clean fclean re

noflags: $(OBJECTS) libft
	$(CC) -o $@ $(OBJECTS)

