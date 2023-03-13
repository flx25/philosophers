# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 08:54:25 by fvon-nag          #+#    #+#              #
#    Updated: 2023/03/13 13:44:41 by fvon-nag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES = main.c \
		ft_atoi.c \


BSOURCES =





OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

all: $(NAME) bonus

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

