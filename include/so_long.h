/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:22:49 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/12/24 01:58:25 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include <stdio.h>

  
# define IMAGE_SIZE			50
# define SUCCESS			1
# define ERROR_MALLOC		-2
# define MLX_PROB			-3
# define OPEN_ERROR			-4
# define ERROR_USAGE		-4

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

// maps checks

// Prasing
int ft_parse_xpm(t_game *game);

// render & key

//exit
void	ft_print_error(int err);
void	ft_free_map(t_game *game);
static void	ft_clean_sprite(t_game *game);
void	ft_exit(t_game *game, int err);

#endif