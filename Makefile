# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 16:08:42 by lucmart3          #+#    #+#              #
#    Updated: 2024/09/17 17:03:06 by lucmart3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOLONG = so_long.a

LIBFT = ./libft/libft.a

MLX42 = ./MLX42/libmlx42.a

LIB_SYS = -Iinclude -ldl -lglfw -pthread -lm

WHITE=\033[0m
GREEN=\033[0;32m
RED=\033[0;31m

FILES =	src/check_map.c\
		src/init_struct.c\
		src/moves.c\
		src/read_map.c\
		src/so_long.c\
		src/textures.c\
		src/utils.c

CC = clang -Wall -Wextra -Werror -g 
#-fsanitize=address

OBJECTS = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJECTS) $(LIBFT) $(MLX42)
		ar rcs $(SOLONG) $(OBJECTS)
		$(CC) $(FLAGS) $(SOLONG) $(MLX42) $(LIBFT) $(LIB_SYS) -o $(NAME)

$(LIBFT):
				@make -s -C ./libft

$(MLX42):
				@make -s -C ./MLX42

$(OBJECTS):	src/%.o : src/%.c
						gcc $(FLAGS) -c $< -o $@

all:				$(NAME)

clean:
					@ rm -f $(OBJECTS)
					@ make clean -s -C ./MLX42
					@ make clean -s -C ./libft
					@echo "\n$(GREEN) ✓  $(RED)Removed  objects $(WHITE)"

fclean:
					@ rm -f $(NAME) $(OBJECTS) $(SOLONG) $(LIBFT) $(MLX42)
					@ make fclean -s -C ./MLX42
					@ make fclean -s -C ./libft

re:					fclean all

.PHONY: all re clean fclean bonus