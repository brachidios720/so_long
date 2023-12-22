/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:22:49 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/12/22 15:20:23 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
# include <mlx.h>
# include <unistd.h>

# define ERROR_MALLOC		-2
# define MLX_PROB			-3

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
void	ft_init_structure(t_game *game, char **argv)

// open file 

// maps checks

// Prasing

// render & key

//exit
void	ft_print_error(int err);
void	ft_free_map(t_game *game);
void	ft_exit(int fd, int err);

#endif