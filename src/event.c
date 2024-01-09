#include "../include/so_long.h"

void    ft_print_msg(int i)
{
    if(i == 1)
    {
        ft_printf("------------------------");
        ft_printf("\n--------YOU_WIN---------\n");
        ft_printf("------------------------\n");
    }
    else if(i == 2)
    {
        ft_printf("------------------------");
        ft_printf("\n-------YOU_LOSE---------\n");
        ft_printf("------------------------\n");
    }
}

void    check_keys(t_game *game, int x, int y)
{
    if( (game->map[x][y] == '0' || game->map[x][y] == 'C')
        || ( game->map[x][y] == 'E' && game->collectible == 0))
    {
        if(game->map[x][y] == 'C')
            game->collectible--;
        else if(game->collectible == 0 && game->map[x][y] == 'E')
        {
            ft_print_msg(1);
            ft_exit(game, END_GAME);
        }
        game->map[x][y] = 'P';
        game->map[game->player_pos_x][game->player_pos_y] = '0';
        game->player_pos_x = x;
        game->player_pos_y = y;
        game->nb_move++;
        printf("%d\n", game->nb_move);  
    }
    if(game->map[x][y] == 'X')
    {
        ft_print_msg(2);
        ft_exit(game, END_GAME);
    }
}
int	ft_event_key(int key_code, t_game *game)
{
	char	*printed_moves;

	if (key_code == KEY_W)
		check_key(game, game->player_pos_x - 1, game->player_pos_y);
	else if (key_code == KEY_S)
		check_key(game, game->player_pos_x + 1, game->player_pos_y);
	else if (key_code == KEY_A)
		check_key(game, game->player_pos_x, game->player_pos_y - 1);
	else if (key_code == KEY_D)
		check_key(game, game->player_pos_x, game->player_pos_y + 1);
	else if (key_code == KEY_ESC)
		ft_exit(game, END_GAME);
	ft_render_img(game);
	printed_moves = ft_itoa(game->nb_move);
	if (!(printed_moves))
		ft_exit(game, ERROR_MALLOC);
	mlx_string_put(game->mlx, game->window, 47, 55, 010100, printed_moves);
	free(printed_moves);
	return (SUCCESS);
}
