# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pngamcha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 10:50:15 by pngamcha          #+#    #+#              #
#    Updated: 2022/02/02 11:28:34 by pngamcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

FLAGS = -Wall -Werror -Wextra

SRC = main.c calculate.c calculate2.c checkhead.c\
      		ft_atoi.c mapper.c memory.c printresult.c\
		read_input.c utility1.c\

all : $(NAME)

$(NAME) :
	$(CC) $(FLAG) -o $(NAME) $(SRC)

fclean :
	rm -f $(NAME)
