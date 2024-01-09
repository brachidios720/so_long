
#include "../include/so_long.h"

static int ft_close(int fd, int i)
{
    if(i == 1)
    {
        close(fd);
        return(ERROR_MALLOC);
    }
    else if(i == 2)
    {
        close(fd);
        return(SUCCESS);
    }
    return(ERROR);
}

int     open_sec(t_game *game, int i)
{
    char *line;
    int fd;

    fd = open(game->filename, O_RDONLY);
    if(fd == -1)
        ft_exit(game, OPEN_ERROR);
    while(i < game->map_height)
    {
        line = get_next_line(fd);
        if(!line)
            ft_close(fd, 1);
        if(i != game->map_height -1)
            line[ft_strlen(line) - 1] = '\0';
        game->map[i] = ft_strdup(line);
        if(!game->map[i])
        {
            free(line);
            return(ft_close(fd, 1));
        }
        free(line);
        i++;
    }
    return(ft_close(fd, 2));
}

int     open_file(t_game *game)
{
    int fd;
    char *line;

    fd = open(game->filename, O_RDONLY);
    if(fd == -1)
        ft_exit(game, OPEN_ERROR);
    while(1)
    {
        line = get_next_line(fd);
        if(line == NULL)
            break;
        game->map_height++;
        free(line);
    }
    close(fd);
    game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
    if(!game->map)
        return(ERROR_MALLOC);
    game->map[game->map_height] = NULL;
    open_sec(game, 1);
    return (SUCCESS);
}
