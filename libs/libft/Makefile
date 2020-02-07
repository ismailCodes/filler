# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/07 21:31:23 by ielmoudn          #+#    #+#              #
#    Updated: 2020/02/07 21:36:57 by ielmoudn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_itoa.c ft_memcpy.c ft_strcat.c ft_strjoin.c\
	ft_atoi.c ft_lstadd.c ft_memdel.c ft_strchr.c ft_strlcat.c\
	ft_strsplit.c ft_bzero.c ft_memmove.c ft_strclr.c\
	ft_strlen.c ft_lstdel.c ft_memset.c\
	ft_strcmp.c ft_strmap.c ft_strstr.c ft_isalnum.c ft_lstdelone.c\
	ft_putchar.c ft_strmapi.c ft_strsub.c ft_isalpha.c\
	ft_lstiter.c ft_putchar_fd.c ft_strncat.c\
	ft_strtrim.c ft_isascii.c ft_lstmap.c ft_putendl.c ft_strcpy.c\
	ft_strncmp.c ft_tolower.c ft_isdigit.c ft_lstnew.c ft_putendl_fd.c\
	ft_strdel.c ft_strncpy.c ft_toupper.c ft_memalloc.c\
	ft_putnbr.c ft_strdup.c ft_strnequ.c ft_isprint.c ft_memccpy.c\
	ft_putnbr_fd.c ft_strequ.c ft_strnew.c ft_memchr.c\
	ft_putstr.c ft_striter.c ft_strnstr.c ft_memcmp.c\
	ft_putstr_fd.c ft_striteri.c ft_strrchr.c\
	safe_malloc_utils.c safe_malloc.c


HEADS = libft.h

FLAGS = -Wall -Wextra -Werror

all:  $(NAME)

$(NAME) :
		gcc $(FLAGS) -c $(SRCS) $(HEADS)
			ar rc $(NAME) *.o

clean :
		rm -f *.o

fclean : clean
		rm -f  $(NAME)

re : fclean all