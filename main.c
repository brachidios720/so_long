/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:22:39 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/12/13 01:18:40 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game *game;

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