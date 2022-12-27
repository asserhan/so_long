NAME = so_long

SRC = mandatory/check_map.c mandatory/get_next_line.c mandatory/get_next_line_utils.c mandatory/map_reader.c \
		 mandatory/play_game.c mandatory/so_long.c mandatory/window.c mandatory/valid_path.c

BSRC = bonus/bonus.c bonus/check_map.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/map_reader.c \
			 bonus/play_game.c bonus/so_long.c bonus/window.c bonus/valid_path.c

LIBFT_LIB = libft.a
LIBFT = $(addprefix libft/, $(LIBFT_LIB))

FT_PRINTF_LIB = libftprintf.a
FT_PRINTF = $(addprefix ft_printf/, $(FT_PRINTF_LIB))

CFLAGS := -Wall -Wextra -Werror -g 
CC = cc
RM = rm -f
LIB = -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

%.o: %.c mandatory/so_long.h mandatory/get_next_line.h bonus/so_long.h bonus/get_next_line.h
	$(CC)  $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		make -C ft_printf/
		$(CC) $(CFLAGS) -I /usr/local/include $^ $(FT_PRINTF) $(LIBFT) $(LIB) -o $(NAME)

bonus: $(BOBJ)
		make -C libft/
		make -C ft_printf/
		$(CC) $(CFLAGS) -I /usr/local/include $^ $(FT_PRINTF) $(LIBFT) $(LIB) -o $(NAME)

clean:
	make clean -sC libft/
	make clean -sC ft_printf/
	$(RM) $(BOBJ) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/ 
	make fclean -C ft_printf/ 

re: fclean all

.PHONY: re all clean fclean