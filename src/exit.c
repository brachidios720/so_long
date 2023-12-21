/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:58:22 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/12/21 15:34:39 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_game *game)
{
	int	i;

	i = -1;
	if (game->map)
	{
		while (++i < game->map_hight)
			free(game->map[i]);
		free(game->map);
	}
}

void	ft_print_error(int err)
{
	if (err == ERROR_MALLOC)
		ft_putstr_fd("Error\nMalloc_Failed\n", 2) 
	if (err ==)
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
	t_game *ga;
	ft_print_error()
}