/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:35:18 by mwilline          #+#    #+#             */
/*   Updated: 2025/06/11 17:38:39 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_game *game, int height)
{
	int	i;

	i = 0;
	game->copy = malloc(sizeof(char *) * (height + 1));
	if (!game->copy)
		ft_error_pr("Error\n malloc");
	while (i < height)
	{
		game->copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->copy[i] = NULL;
}

void	get_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->copy[i])
	{
		j = 0;
		while (game->copy[i][j])
		{
			if (game->copy[i][j] == 'P')
			{
				game->y = i;
				game->x = j;
			}
			j++;
		}
		i++;
	}
}

void	fill_flood(char **map, int y_, int x_, t_game *game)
{
	if (y_ < 0 || x_ < 0 || y_ >= game->height || x_ >= game->width)
		return ;
	if (map[y_][x_] == '1' || map[y_][x_] == 'F')
		return ;
	if (map[y_][x_] == 'E')
	{
		game->check_e++;
		map[y_][x_] = 'F';
		return ;
	}
	if (map[y_][x_] == 'C')
		game->check_c++;
	map[y_][x_] = 'F';
	fill_flood(map, y_, x_ + 1, game);
	fill_flood(map, y_, x_ - 1, game);
	fill_flood(map, y_ + 1, x_, game);
	fill_flood(map, y_ - 1, x_, game);
}

void	freee_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->copy)
	{
		while (game->copy[i])
		{
			free(game->copy[i]);
			i++;
		}
		free(game->copy);
	}
}

void	control_map(t_game *game)
{
	int		y_;
	int		x_;

	copy_map(game, game->height);
	get_player(game);
	y_ = game->y;
	x_ = game->x;
	fill_flood(game->copy, y_, x_, game);
	if (game->coin != game->check_c)
		ft_error_pr("Error con monedas");
	if (game->exit != game->check_e)
		ft_error_pr("Error con exit");
	freee_map(game);
}
