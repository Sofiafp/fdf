# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 20:00:00 by salegre-          #+#    #+#              #
#    Updated: 2022/03/28 21:49:04 by salegre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
LIB1	= ar -rcs

RM		= /bin/rm -f

NAME	= libfdf.a

INCLUDE1	= minilibx_macos/mlx.h 
INCLUDE2	= libfdf.h

SRCS	=  libft/ft_isascii.c libft/ft_isprint.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c \
			libft/ft_tolower.c libft/ft_toupper.c libft/ft_strlen.c libft/ft_strlcpy.c libft/ft_strlcat.c \
			libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strnstr.c libft/ft_strncmp.c libft/ft_atoi.c \
			 libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memmove.c \
			libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strdup.c libft/ft_calloc.c libft/ft_itoa.c \
			libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
			libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_strmapi.c \
			ft_fdf.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
			
OBJS	= $(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE1) $(INCLUDE2)
			$(LIB1) $(NAME) $(OBJS)
			$(CC) ft_fdf.c -L. -lmlx -lfdf -framework OpenGL -framework AppKit -o fdf 

.c.o:
			$(CC) $(CFLAGS) -I$(INCLUDE1) -I$(INCLUDE2) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
