NAME := so_long
SRC :=  *.c \
		./get_next_line/*.c \
		./ft_printf/*.c \
		./libft/*.c \

CFLAGS := -Wall -Wextra -Werror
CC := cc
RM := rm -f
LIB := -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit
OBJ := $(SRC:.c=.o)
MINILIBX := minilibx/


%.o: %.c so_long.h
	$(CC)  $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
 	$(CC) $(CFLAGS) -I /usr/local/include  $(SRC) $(LIB) -o $(NAME)

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean