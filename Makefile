# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mekundur <mekundur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 16:21:47 by mekundur          #+#    #+#              #
#    Updated: 2025/03/04 17:08:27 by mekundur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT = ./libft/libft.a
MLX42 = ./MLX42/build/libmlx42.a
SOURCES = main.c get_scene_data.c parse_map.c utils_2dstr.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME) 

$(LIBFT) :
	@echo "<Compiling libft>"
	@make -C ./libft

%.o: %.c Makefile $(LIBFT)
	@cc -c -g -Werror -Wall -Wextra $< -o $@ 

$(NAME) : $(HEADER) $(LIBFT) $(OBJECTS) Makefile
	@echo "Creating the program <cub3D>"
	@cc -g -Werror -Wall -Wextra $(OBJECTS) $(LIBFT) -Iinclude -ldl -lglfw -lm -o $(NAME)

#$(MLX42) :
#	@if [ ! -d "MLX42" ]; then \
#		git clone https://github.com/codam-coding-college/MLX42.git; \
#	fi
#	@cd MLX42 && cmake -B build && cmake --build build -j4

#%.o: %.c Makefile $(LIBFT) $(MLX42) 
#	@cc -c -g -Werror -Wall -Wextra $< -o $@ 

#$(NAME) : $(HEADER) $(MLX42) $(LIBFT) $(OBJECTS) Makefile
#	@echo "Creating the program <fdf>"
#	@cc -g -Werror -Wall -Wextra $(OBJECTS) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

clean :
	@echo "Removing object files"
	@rm -f $(OBJECTS)
	@make clean -C ./libft	
#	@make clean -C ./MLX42/build

fclean : clean 
	@echo "Removing the executable <cub3D>"
	@rm -f cub3D
	@make fclean -C ./libft

re : fclean all

.PHONY: all, clean, fclean, re
