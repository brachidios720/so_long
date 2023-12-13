/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:22:49 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/12/13 11:58:36 by rcarbonn         ###   ########.fr       */
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
	int		width;
	int		height;
	void	sprit_player;
	void	sprit_end;
	void	sprit_wall;
	void	sprit_collectible;
	void	sprit_enemy;
	void	sprit_rock;
	int		image_size;
}				t_game;

// inttiate struct

// open file 

// maps checks

// Prasing

// render & key

//exit
void	ft_print_error(int err);
void	ft_free_map(t_game *game);

#endif