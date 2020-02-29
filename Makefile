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

G = gcc -Wall -Wextra -Werror -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit -Ofast -o cub3D -g
SRC = sprite2.c render_walls1.c last_correct.c check1.c fill.c check_colors.c stock_paths.c read_map.c checks.c errors.c exit_free.c ft_strcmp.c ft_substr.c ft_substr_trim.c ft_trim.c ft_atoi.c ft_split.c get_next_line.c cast_rays.c check_next_step_x.c check_next_step_y.c cub3d.c cub3d_utils.c file.c horizontal_intersect.c vertical_intersect.c render_walls.c render_sprite.c sprite1.c textures.c update.c walk.c get_next_line_utils.c keypress_keyreleased.c sort_sprite.c screen_shot.c
NAME = cub3D

all: $(NAME)

$(NAME):
	$(G) $(SRC)
clean: 
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
