# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: medeana <medeana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 18:51:43 by medeana           #+#    #+#              #
#    Updated: 2022/01/05 19:00:36 by medeana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =      philo

HEADER = philo.h

LIST =      end.c \
			ft_atoi.c \
			init.c \
			main.c \
			prosecc.c \
			sleeping.c \
			take_fork.c \
			time.c \
			valid.c
			

OBJ = $(LIST:.c=.o)

FLAGS = -Wall -Wextra -Werror

all :	$(NAME)

$(NAME) : $(OBJ) $(HEADER)
	gcc $(FLAGS) $(LIST) -o $(NAME)

clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)

re :	fclean all
.PHONY : all clean fclean re bonus