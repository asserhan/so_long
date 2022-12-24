NAME = so_long

SRC_F = check_map.c map_reader.c play_game.c \
			so_long.c window.c
MADATORY =  $(addprefix mandatory/, $(SRC_F))
SRC = $(SRC_F) $(GNL)

BONUS_F = bonus.c check_map.c map_reader.c \
			play_game.c so_long.c window.c
BONUS = $(addprefix bonus/, $(BONUS_F))
BSRC = $(BONUS) $(GNL)

LIBFT_LIB = libft.a
LIBFT = $(addprefix libft/, $(LIBFT_LIB))

GNL_F = get_next_line.c get_next_line_utiles.c
GNL = $(addprefix get_next_line/, $(GNL_F))

FT_PRINTF_LIB =  libftprintf.a
FT_PRINTF = $(addprefix ft_printf /, $(FT_PRINTF_LIB))

CFLAGS := -Wall -Wextra -Werror
CC = cc
RM = rm -f
LIB = -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT_LIB) $(FT_PRINTF_LIB)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -I /usr/local/include $(LIB) -o $(NAME)

%.o: %.c  so_long.h
	$(CC)  $(CFLAGS) -c $< -o $@

bonus: $(BOBJ)
		make -C $(LIBFT_LIB) $(FT_PRINTF_LIB)
		$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) $(FT_PRINTF) -I /usr/local/include $(LIB) -o $(NAME)

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean