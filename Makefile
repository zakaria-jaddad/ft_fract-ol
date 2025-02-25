
SRC =	./fractol.c \
	./utils/ft_atof.c \
	./utils/ft_putstr_fd.c \
	./utils/ft_isdigit.c \
	./utils/my_pixel_put.c \
	./utils/map.c \
	./utils/ft_abs.c \
	./utils/ft_strcmp.c \
	./utils/get_name.c \
	./utils/get_color.c \
	./utils/fractol_util.c \


OBJ = $(SRC:.c=.o)

INCLUDE = fractol.h

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean: 
	rm -rf $(OBJ)
