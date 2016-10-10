# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 01:28:32 by jpirsch           #+#    #+#              #
#    Updated: 2015/03/25 02:04:55 by sven             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export FLAGS	= -Wall -Wextra -Werror
NAME			= ft_sh1
SRC_DIR			= ./sources
LIB_DIR			= ./libft

all:
	make -C $(LIB_DIR)
	make -C $(SRC_DIR)

clean:
	make -C $(LIB_DIR) clean
	make -C $(SRC_DIR) clean

fclean: clean
	make -C $(LIB_DIR) fclean
	make -C $(SRC_DIR) fclean

re: fclean all
