# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smhah <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 15:14:20 by smhah             #+#    #+#              #
#    Updated: 2019/11/20 15:14:21 by smhah            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G = gcc -Wall -Wextra -Werror -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit -Ofast -o cub3D
SRC = ft_atoi.c ft_split.c get_next_line.c cast_rays.c check_next_step_x.c check_next_step_y.c cub3d.c cub3d_utils.c file.c horizontal_intersect.c vertical_intersect.c render_walls.c render_sprite.c sprite1.c textures.c update.c walk.c get_next_line_utils.c keypress_keyreleased.c sort_sprite.c
NAME = cub3D

all: $(NAME)

$(NAME):
	$(G) $(SRC)
clean: 
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
