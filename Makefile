cc = clang
fl = -Wall -Werror -Wextra
link = libft/libft.a mlx/libmlx.a
exe = so_long

src = 	./src/check_map.c \
    	./src/check_symbol.c \
    	./src/event.c \
    	./src/exit.c \
    	./src/main.c \
    	./src/parse_map.c \
    	./src/parse_xpm.c \
    	./src/render.c \

all:
	make -C mlx/
	make -C libft/
	$(cc) $(fl) $(link) $(src) -o $(exe)
fclean:
	make clean -C mlx/
	make fclean -C libft/
