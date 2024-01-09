#include "../include/so_long.h"

int ft_parse_xpm(t_game *game)
{
    game->img_size = IMAGE_SIZE;
    game->win_height = game->img_size * game->win_height;
    game->win_width = game->img_size * game->win_width;
    game->window = mlx_new_window(game->mlx, game->win_width,
			game->win_height, "so_long");
    game->sprite_end = mlx_xpm_file_to_image(game->mlx,
        "xpm/sleeping_bat.xpm", &game->img_size, &game->img_size);
    game->sprite_air = mlx_xpm_file_to_image(game->mlx,
        "xpm/air.xpm", &game->img_size, &game->img_size);
    game->sprite_bat_danger = mlx_xpm_file_to_image(game->mlx,
        "xpm/bat_danger.xpm", &game->img_size, &game->img_size);
    game->sprite_collectible = mlx_xpm_file_to_image(game->mlx,
        "xpm/blood.xpm", &game->img_size, &game->img_size);
    game->sprite_player_1 = mlx_xpm_file_to_image(game->mlx,
        "xpm/bat_1.xpm", &game->img_size, &game->img_size);
    game->sprite_player_2 = mlx_xpm_file_to_image(game->mlx,
        "xpm/bat_2.xpm", &game->img_size, &game->img_size);
    game->sprite_rock = mlx_xpm_file_to_image(game->mlx,
        "xpm/rock.xpm", &game->img_size, &game->img_size);
    game->sprite_sun = mlx_xpm_file_to_image(game->mlx,
        "xpm/sunny.xpm", &game->img_size, &game->img_size);
    if(!game->sprite_air || !game->sprite_bat_danger || !game->sprite_collectible
        || !game->sprite_end || !game->sprite_player_1 || !game->sprite_player_2
        || !game->sprite_rock || !game->sprite_sun)
        ft_exit(game, OPEN_ERROR);
    return(SUCCESS);
}
