/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:22:39 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/12/21 15:45:07 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, char **argv)
{
	game->filename = argv[1];
	game->player = 0
	game->x = 0;
	game->y = 0;
	game->end = 0;
	game->nb_move = 0;
	game->width = 0;
	game->height = 0;
	game->sprite_player_1 = NULL;
	game->sprite_player_2 = NULL;
	game->sprite_end = NULL;
	game->sprite_collectible = NULL;
	game->sprite_air = NULL;
	game->sprite_rock = NULL;
	game->mlx = mlx_init();
	if(game->mlx != mlx_init)
		ft_exit()
	game->window = NULL;
	game->image_size = 0;
	game->sprite_sun = NULL;
	game->sprite_bat_danger = NULL;
}

int	main(int argc, char **argv)
{
	t_game *game;
	void	*mlx;
	
	mlx = mlx_init();
	if (argc != 2)
		return ();
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return ();
	// verifier les .ber
	// gerer mlx init pour gerer les erruer d ouverture
	// utilisation de get_next_line
	// verifier la map rectangle
	// verifier les carracterer de la map
	// que des mur autour
	// xpm ok utilisation de mlx_new-windows, mlx_xpm_file_to_image
	//
}