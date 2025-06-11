/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:38:50 by mwilline          #+#    #+#             */
/*   Updated: 2025/06/11 17:39:36 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"

void	w_key(t_game *game)
{
	if (game->map[game->y - 1][game->x] != '1' && game->map[game->y
		- 1][game->x] != 'E')
	{
		if (game->map[game->y - 1][game->x] == '0' || game->map[game->y
			- 1][game->x] == 'C')
		{
			if (game->map[game->y - 1][game->x] == 'C')
				game->coin--;
			game->map[game->y][game->x] = '0';
			game->map[game->y - 1][game->x] = 'P';
		}
		game->y -= 1;
		game->steps++;
		write(1, "MOVIMIENTOS: ", 13);
		ft_putnbr_fd(game->steps, 1);
		write(1, "\n", 1);
	}
	else if (game->map[game->y - 1][game->x] == 'E' && game->coin == 0)
		ft_exit(game);
}

void	s_key(t_game *game)
{
	if (game->map[game->y + 1][game->x] != '1' && game->map[game->y
		+ 1][game->x] != 'E')
	{
		if (game->map[game->y + 1][game->x] == '0' || game->map[game->y
			+ 1][game->x] == 'C')
		{
			if (game->map[game->y + 1][game->x] == 'C')
				game->coin--;
			game->map[game->y][game->x] = '0';
			game->map[game->y + 1][game->x] = 'P';
		}
		game->y++;
		game->steps++;
		write(1, "MOVIMIENTOS: ", 13);
		ft_putnbr_fd(game->steps, 1);
		write(1, "\n", 1);
	}
	else if (game->map[game->y + 1][game->x] == 'E' && game->coin == 0)
		ft_exit(game);
}

void	a_key(t_game *game)
{
	if (game->map[game->y][game->x - 1] != '1' && game->map[game->y][game->x
		- 1] != 'E')
	{
		if (game->map[game->y][game->x - 1] == '0' || game->map[game->y][game->x
			- 1] == 'C')
		{
			if (game->map[game->y][game->x - 1] == 'C')
				game->coin--;
			game->map[game->y][game->x] = '0';
			game->map[game->y][game->x - 1] = 'P';
		}
		game->x--;
		game->steps++;
		write(1, "MOVIMIENTOS: ", 13);
		ft_putnbr_fd(game->steps, 1);
		write(1, "\n", 1);
	}
	else if (game->map[game->y][game->x - 1] == 'E' && game->coin == 0)
		ft_exit(game);
}

void	d_key(t_game *game)
{
	if (game->map[game->y][game->x + 1] != '1' && game->map[game->y][game->x
		+ 1] != 'E')
	{
		if (game->map[game->y][game->x + 1] == '0' || game->map[game->y][game->x
			+ 1] == 'C')
		{
			if (game->map[game->y][game->x + 1] == 'C')
				game->coin--;
			game->map[game->y][game->x] = '0';
			game->map[game->y][game->x + 1] = 'P';
		}
		game->x++;
		game->steps++;
		write(1, "MOVIMIENTOS: ", 13);
		ft_putnbr_fd(game->steps, 1);
		write(1, "\n", 1);
	}
	else if (game->map[game->y][game->x + 1] == 'E' && game->coin == 0)
		ft_exit(game);
}

int	ft_press_key(int key, t_game *game)
{
	if (key == 65307)
		ft_exit(game);
	else if (key == 119)
		w_key(game);
	else if (key == 97)
		a_key(game);
	else if (key == 115)
		s_key(game);
	else if (key == 100)
		d_key(game);
	return (0);
}
