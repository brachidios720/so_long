/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:22:49 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/12/31 16:27:18 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"
# include <stdio.h>
# include "../mlx/mlx.h"

  
# define IMAGE_SIZE			50
# define ERROR				0
# define SUCCESS			1
# define ERROR_MALLOC		-2
# define MLX_PROB			-3
# define OPEN_ERROR			-4
# define ERROR_USAGE		-5
# define ERROR_WALL			-6
# define ERROR_MAP_SIZE		-7
# define END_GAME			-8
# define INVALID_SYMBOLS	-9
# define KEY_W						119
# define KEY_S						115
# define KEY_A						97
# define KEY_D						100
# define KEY_ESC					65307

typedef struct s_game
{
	char	**map;
	char	*filename;
	int		map_width;
	int		map_height;
	int		collectible;
	int		player;
	int		end;
	int		nb_move;
	int		player_pos_x;
	int		player_pos_y;
	void	*sprite_player_1;
	void	*sprite_player_2;
	void	*sprite_end;
	void	*sprite_collectible;
	void	*sprite_air;
	void	*sprite_rock;
	void	*mlx;
	void	*window;
	int		img_size;
	int		win_width;
	int		win_height;
	void	*sprite_sun;
	void	*sprite_bat_danger;

}	t_game;


// inttiate struct
void	ft_init_structure(t_game *game, char **argv);

// open file 
// static int ft_close(int fd, int i);
int     open_sec(t_game *game, int i);
int     open_file(t_game *game);

// maps checks
int ft_check_rectangle(t_game *game);
int ft_check_wall(t_game *game);
int ft_return(t_game *game);
void    fill_struct(t_game *game, int i, int j);
int    check_symbol(t_game *game);
int	ft_event_key(int key_code, t_game *game);

// Prasing
int ft_parse_xpm(t_game *game);

// render & key
void    ft_print_msg(int i);
void    check_key(t_game *game, int x, int y);
void	ft_render_img(t_game *game);
// static void	ft_render_sprites(t_game *game, int i, int j);
int	ft_choice_player(t_game *game, int i, int j);

//exit
void	ft_print_error(int err);
void	ft_free_map(t_game *game);
// static void	ft_clean_sprite(t_game *game);
void	ft_exit(t_game *game, int err);

#endif
