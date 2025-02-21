
SRC =	./fractol.c \
	./ft_atof.c \
	./utils/ft_putstr_fd.c \
	./utils/ft_isdigit.c \

OBJ = $(SRC:.c=.o)

INCLUDE = fractol.h

NAME = fractol

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) -Wall -Wextra -Werror -Imlx -O3 -c $< -o $@

clean: 
	rm -rf $(OBJ)
