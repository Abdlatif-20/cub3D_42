# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 20:18:10 by mel-yous          #+#    #+#              #
#    Updated: 2022/11/02 20:43:33 by mel-yous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_isprint.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcat.c ft_substr.c\
		ft_bzero.c ft_lstnew.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strlen.c\
		ft_toupper.c ft_isalnum.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strncmp.c\
		ft_isascii.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_isdigit.c	ft_memset.c	ft_striteri.c ft_strrchr.c ft_strlcat.c

OBJS = $(SRCS:.c=.o)

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c

BOBJS = $(BSRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus : $(NAME) $(BOBJS)
	ar rc $(NAME) $(BOBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $<

clean:	
	rm -rf $(OBJS) $(BOBJS)

fclean:	clean
	rm -rf $(NAME)
re : fclean all
