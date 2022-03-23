# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 20:00:00 by salegre-          #+#    #+#              #
#    Updated: 2022/03/23 14:32:53 by salegre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
LIB1	= ar -rcs

RM		= /bin/rm -f

NAME	= libps.a

INCLUDE	= minilibx_macos/mlx.h

SRCS	= testes.c
			
OBJS	= $(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB1) $(NAME) $(OBJS)
			$(CC) testes.c  -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.c.o:
			$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
