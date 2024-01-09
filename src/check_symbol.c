#include "../include/so_long.h"

int ft_return(t_game *game)
{
    if(game->player != 1 || game->end != 1 
        || game->collectible < 1)
        return(INVALID_SYMBOLS);
    return(SUCCESS);
}

void    fill_struct(t_game *game, int i, int j)
{
    game->player_pos_x = i;
    game->player_pos_y = j;
    game->player++;
}

int    t_check_symbol(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
				fill_struct(game, i, j);
			else if (game->map[i][j] == 'E')
				game->end++;
			else if (game->map[i][j] == 'C')
				game->collectible++;
			// else if (game->map[i][j] == 'X'
			// 	&& ft_subword(game->filename, "bonus") == ERROR)
			// 	return (INVALID_SYMBOLS);
			else if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'X')
				return (INVALID_SYMBOLS);
		}
	}
	return (ft_return(game));
}
