# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 20:18:10 by mel-yous          #+#    #+#              #
#    Updated: 2023/08/09 18:24:39 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
RM = rm -f
AR = ar rc
HDR = libft.h
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c\

OBJ = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o\
	ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o\
	ft_strlcpy.o ft_strlcat.o ft_toupper.o ft_tolower.o ft_strchr.o\
	ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o ft_atoi.o\
	ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o\
	ft_itoa.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o\
	ft_putendl_fd.o ft_putnbr_fd.o\

all : ${NAME}

${NAME} : ${OBJ}
	@${AR} ${NAME} ${OBJ}

%.o : %.c ${HDR}
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "\033[1;32mCompiling\033[0m" $< "\033[1;32m...\033[0m"
	@clear

fclean : clean
	@${RM} ${NAME}

clean :
	@${RM} ${OBJ}

re: fclean all

.PHONY : clean fclean