#include "../include/so_long.h"

int	ft_choice_player(t_game *game, int i, int j)
{
	if (game->map[i + 1][j] == 'X' || game->map[i - 1][j] == 'X'
	|| game->map[i][j + 1] == 'X' || game->map[i][j - 1] == 'X')
		return (1);
	return (0);
}

static void	ft_render_sprites(t_game *game, int i, int j)
{
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_air, IMAGE_SIZE * j, IMAGE_SIZE * i);
	else if (game->map[i][j] == 'P' && ft_choice_player(game, i, j) == 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_bat_danger, IMAGE_SIZE * j, IMAGE_SIZE * i);
	else if (game->map[i][j] == 'P' && (game->nb_move % 2 == 0))
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_player_1, IMAGE_SIZE * j, IMAGE_SIZE * i);
	else if (game->map[i][j] == 'P' && (game->nb_move % 2 != 0))
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_player_2, IMAGE_SIZE * j, IMAGE_SIZE * i);
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_rock, IMAGE_SIZE * j, IMAGE_SIZE * i);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_collectible, IMAGE_SIZE * j, IMAGE_SIZE * i);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_end, IMAGE_SIZE * j, IMAGE_SIZE * i);
	else if (game->map[i][j] == 'X')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_sun, IMAGE_SIZE * j, IMAGE_SIZE * i);
}

void	ft_render_img(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			ft_render_sprites(game, i, j);
	}
}
