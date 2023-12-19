/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:22:49 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/12/19 12:00:16 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
# include <mlx.h>
# include <unistd.h>

# define ERROR_MALLOC		-2


typedef struct s_game
{
	char **map;
	char *filename;
	int	 player;
	int		x;
	int		y;
	int		end;
	int		nb_move;
	int		width;
	int		height;
	void	*sprite_player_1;
	void	*sprite_player_2;
	void	*sprite_end;
	void	*sprite_collectible;
	void	*sprite_air;
	void	*sprite_rock;
	void	*mlx;
	void	*window;
	int		image_size;
	void	*sprite_sun;
	void	*sprite_bat_danger;
}				t_game;

// inttiate struct

// open file 

// maps checks

// Prasing

// render & key

//exit
void	ft_print_error(int err);
void	ft_free_map(t_game *game);
void	ft_exit(int fd, int err);

#endif