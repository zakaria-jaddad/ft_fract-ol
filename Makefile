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

BSRC =	./bonus/fractol_bonus.c \
	./bonus/utils/ft_print_usage_bonus.c \
	./bonus/utils/ft_atof_bonus.c \
	./bonus/utils/ft_putstr_fd_bonus.c \
	./bonus/utils/ft_isdigit_bonus.c \
	./bonus/utils/my_pixel_put_bonus.c \
	./bonus/utils/map_bonus.c \
	./bonus/utils/ft_strcmp_bonus.c \
	./bonus/utils/get_name_bonus.c \
	./bonus/utils/get_color_bonus.c \
	./bonus/utils/fractol_util_bonus.c \

MOBJ = $(MSRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = fractol
NAME_BONUS = fractol_bonus

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(MOBJ)
	$(CC) $(CFLAGS) $(MOBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -O3 -o $(NAME)

$(NAME_BONUS): $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -O3 -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c -O3 $< -o  $@ -MMD

re: fclean all

clean: 
	rm -rf $(MOBJ) $(BOBJ)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS) $(MOBJ:.o=.d) $(BOBJ:.o=.d)

.PHONY: clean

-include $(MOBJ:.o=.d)
-include $(BOBJ:.o=.d)
