/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:22:39 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/12/31 16:37:32 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		ft_exit(game, MLX_PROB);
	game->window = NULL;
	game->img_size = 0;
	game->win_width = 0;
	game->win_height = 0;
	game->sprite_sun = NULL;
	game->sprite_bat_danger = NULL;
}


// int	main(int argc, char **argv)
// {
// 	t_game *game;
// 	void	*mlx;
	
// 	mlx = mlx_init();
// 	if (argc != 2)
// 		ft_exit(game, ERROR_USAGE);
// 	game = (t_game *)malloc(sizeof(t_game));
// 	if (!game)
// 		ft_exit(game, ERROR_MALLOC);
// 	ft_init_structure(game, argv);
	
// 	// verifier les .ber
// 	// gerer mlx init pour gerer les erruer d ouverture
// 	// utilisation de get_next_line
// 	// verifier la map rectangle
// 	// verifier les carracterer de la map
// 	// que des mur autour
// 	// xpm ok utilisation de mlx_new-windows, mlx_xpm_file_to_image
// 	//
// }

static int	close_with_cross(t_game *game)
{
	ft_exit(game, END_GAME);
	return (SUCCESS);
}

static void	ft_check_errors(t_game *game)
{
	int	err;

	err = open_file(game);
	if (err < 0)
		ft_exit(game, err);
	err = ft_check_rectangle(game);
	if (err < 0)
		ft_exit(game, err);
	err = check_symbol(game);
	if (err < 0)
		ft_exit(game, err);
	err = ft_check_wall(game);
	if (err < 0)
		ft_exit(game, err);
	err = ft_parse_xpm(game);
	if (err < 0)
		ft_exit(game, err);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_exit(NULL, ERROR_USAGE);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		ft_exit(game, ERROR_MALLOC);
	ft_init_structure(game, argv);
	// if (check_extension(game) == ERROR)
	// 	ft_exit(game, ERROR_USAGE);
	ft_check_errors(game);
	ft_render_img(game);
	mlx_key_hook(game->window, ft_event_key, game);
	mlx_hook(game->window, 33, 1L << 22, close_with_cross, game);
	mlx_loop(game->mlx);
	return (SUCCESS);
}

int     mlx_destroy_window(void *mlx_ptr, void *win_ptr);