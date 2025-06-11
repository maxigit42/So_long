/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:40:01 by mwilline          #+#    #+#             */
/*   Updated: 2025/06/11 17:57:29 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(t_game *game, int *i, int *j)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->textures->wall, *j * 40, *i * 40);
}

void	put_player(t_game *game, int *i, int *j)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->textures->player, *j * 40, *i * 40);
	game->y = *i;
	game->x = *j;
}

void	put_ground(t_game *game, int *i, int *j)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->textures->ground, *j * 40, *i * 40);
}

void	put_exit(t_game *game, int *i, int *j)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->textures->exit, *j * 40, *i * 40);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				put_wall(game, &i, &j);
			else if (game->map[i][j] == '0')
				put_ground(game, &i, &j);
			else if (game->map[i][j] == 'P')
				put_player(game, &i, &j);
			else if (game->map[i][j] == 'E')
				put_exit(game, &i, &j);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->textures->coin, j * 40, i * 40);
			j++;
		}
		i++;
	}
}
