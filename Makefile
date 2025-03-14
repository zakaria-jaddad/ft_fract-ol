# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 21:59:32 by zajaddad          #+#    #+#              #
#    Updated: 2025/03/14 02:58:43 by zajaddad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MSRC =	./mandatory/fractol.c \
	./mandatory/utils/ft_print_usage.c \
	./mandatory/utils/ft_atof.c \
	./mandatory/utils/ft_putstr_fd.c \
	./mandatory/utils/ft_isdigit.c \
	./mandatory/utils/my_pixel_put.c \
	./mandatory/utils/map.c \
	./mandatory/utils/ft_strcmp.c \
	./mandatory/utils/get_name.c \
	./mandatory/utils/get_color.c \
	./mandatory/utils/fractol_util.c \

BSRC =	./bonus/fractol.c \
	./bonus/utils/ft_print_usage.c \
	./bonus/utils/ft_atof.c \
	./bonus/utils/ft_putstr_fd.c \
	./bonus/utils/ft_isdigit.c \
	./bonus/utils/my_pixel_put.c \
	./bonus/utils/map.c \
	./bonus/utils/ft_strcmp.c \
	./bonus/utils/get_name.c \
	./bonus/utils/get_color.c \
	./bonus/utils/fractol_util.c \

MOBJ = $(MSRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

INCLUDE = ./mandatory/fractol.h
INCLUDE_BONUS = ./bonus/fractol_bonus.h

NAME = fractol

all: $(NAME)

$(NAME): $(MOBJ)
	$(CC) $(MOBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

bonus: $(BOBJ)
	$(CC) $(MOBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

$(MOBJ): %.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(BOBJ): %.o: %.c $(INCLUDE_BONUS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
re: fclean all

clean: 
	rm -rf $(MOBJ) $(BOBJ)

fclean: clean
	rm -rf $(NAME)

.PHONY: clean
