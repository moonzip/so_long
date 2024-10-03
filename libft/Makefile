# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/13 22:08:06 by lucmart3          #+#    #+#              #
#    Updated: 2024/09/11 18:35:47 by lucmart3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GREEN=\033[0;32m
RED=\033[0;31m

SOURCES = \
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isprint.c\
			ft_isascii.c\
			ft_strlen.c\
			ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strncmp.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strnstr.c\
			ft_atoi.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_strmapi.c\
			ft_itoa.c\
			ft_striteri.c\
			ft_split.c\
			get_next_line_bonus.c\
			get_next_line_utils_bonus.c\
			ft_printf.c\
			ft_nosigne.c\
			ft_numhex.c\
			ft_pointer.c\
			ft_putcharf.c\
			ft_putnbrf.c\
			ft_putstrf.c\

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?


clean:
		rm -f $(OBJECTS)
		@echo "\n$(GREEN) ✓  $(RED)Removed  objects $(WHITE)"

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re