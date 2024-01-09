/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:58:22 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/12/29 14:33:10 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_map(t_game *game)
{
	int	i;

	i = -1;
	if (game->map)
	{
		while (++i < game->map_height)
			free(game->map[i]);
		free(game->map);
	}
}

void	ft_print_error(int err)
{
	if (err == ERROR_MALLOC)
		ft_putstr_fd("Error\nMalloc_Failed\n", 2); 
	if (err == MLX_PROB)
		ft_putstr_fd("Error\nMLX_Failed\n", 2);
	if (err == OPEN_ERROR)
		ft_putstr_fd("Error\nOpen_Error\n", 2);
	if (err == ERROR_USAGE)
		ft_putstr_fd("Error\nInvalid_Arguments\n", 2);
	if	(err == INVALID_SYMBOLS)
		ft_putstr_fd("Error\nInvalid_Symbols\n", 2);
}	

static void	ft_clean_sprite(t_game *game)
{
	if (game->sprite_air)
		mlx_destroy_image(game->mlx, game->sprite_air);
	if (game->sprite_end)
		mlx_destroy_image(game->mlx, game->sprite_end);
	if (game->sprite_rock)
		mlx_destroy_image(game->mlx, game->sprite_rock);
	if (game->sprite_collectible)
		mlx_destroy_image(game->mlx, game->sprite_collectible);
	if (game->sprite_player_1)
		mlx_destroy_image(game->mlx, game->sprite_player_1);
	if (game->sprite_player_2)
		mlx_destroy_image(game->mlx, game->sprite_player_2);
	if (game->sprite_sun)
		mlx_destroy_image(game->mlx, game->sprite_sun);
	if (game->sprite_bat_danger)
		mlx_destroy_image(game->mlx, game->sprite_bat_danger);
}

void	ft_exit(t_game *game, int err)
{
	ft_print_error(err);
	if(game)
	{
		if(game->map)
			ft_free_map(game);
		ft_clean_sprite(game);
		if(game->window)
			mlx_destroy_window(game->mlx, game->window);
		// if(game->mlx)
		// {
		// 	mlx_destroy_display(game->mlx);
		// 	free(game->mlx);
		// }
		free(game);
	}
	exit(0);
}
