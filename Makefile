
SRC = ./fractol.c
OBJ = $(SRC:.c=.o)

INCLUDE = fractol.h

NAME = fractol

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
	# $(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) -Wall -Wextra -Werror -Imlx -O3 -c $< -o $@
