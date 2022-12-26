NAME = so_long

SRC_F = check_map.c map_reader.c play_game.c \
			so_long.c window.c \
MANDATORY =  $(addprefix ./mandatory/, $(SRC_F))
SRC = $(MANDATORY) $(GNL)

BONUS_F = bonus.c check_map.c map_reader.c \
			play_game.c so_long.c window.c
BONUS = $(addprefix ./bonus/, $(BONUS_F))
BSRC = $(BONUS) $(GNL)

LIBFT_LIB = libft.a
LIBFT = $(addprefix ./libft/, $(LIBFT_LIB))

GNL_F = get_next_line.c get_next_line_utils.c
GNL = $(addprefix ./get_next_line/, $(GNL_F))

FT_PRINTF_LIB = libftprintf.a
FT_PRINTF = $(addprefix ./ft_printf/, $(FT_PRINTF_LIB))

CFLAGS := -Wall -Wextra -Werror
CC = cc
RM = rm -f
LIB = -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

%.o: %.c 
	$(CC)  $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):
		make -C ./libft/
		make -C ./ft_printf/
		$(CC) $(CFLAGS) -I /usr/local/include  $(SRC) $(FT_PRINTF) $(LIBFT)  $(LIB) -o $(NAME)


bonus:
		make -C $(LIBFT_LIB) $(FT_PRINTF_LIB)
		$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) $(FT_PRINTF) -I /usr/local/include $(LIB) -o $(NAME)

clean:
	make clean -sC ./libft/
	make clean -sC ./ft_printf/
	

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft/ 
	make fclean -C ./ft_printf/ 

re: fclean all

.PHONY: re all clean fclean