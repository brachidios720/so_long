/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:22:39 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/12/22 15:19:14 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_structure(t_game *game, char **argv)
{
	game->filename = argv[1];
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->collectible = 0;
	game->player = 0;
	game->end = 0;
	game->nb_move = 0;
	game->player_pos_x = 0;
	game->player_pos_y = 0;
	game->sprite_player_1 = NULL;
	game->sprite_player_2 = NULL;
	game->sprite_collectible = NULL;
	game->sprite_end = NULL;
	game->sprite_air = NULL;
	game->sprite_rock = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit(game, ERROR_MLX);
	game->window = NULL;
	game->img_size = 0;
	game->win_width = 0;
	game->win_height = 0;
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