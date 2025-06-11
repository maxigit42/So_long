/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:18:33 by mwilline          #+#    #+#             */
/*   Updated: 2025/06/11 22:32:57 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game)
{
	ft_check_outline(game);
	ft_check_valid(game);
	ft_check_elements(game);
}

void	ft_check_ber(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len < 5)
		ft_error_pr("Error\nInvalid extension\n");
	if (ft_strncmp(map + len - 4, ".ber", 4) != 0)
		ft_error_pr("Error\n.ber");
}

void	ft_check_outline(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			write(2, "Error\nOutline\n", 15);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			write(2, "Error\noutline\n", 15);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_check_valid(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P' &&
				game->map[i][j] != 'C' && game->map[i][j] != 'E')
			{
				write(2, "Error\nValidate\n", 16);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
				game->player += 1;
			if (game->map[i][j] == 'C')
				game->coin += 1;
			if (game->map[i][j] == 'E')
				game->exit += 1;
			j++;
		}
		i++;
	}
	if (game->player != 1 || game->exit != 1 || game->coin == 0)
	{
		write(2, "Error\nElements\n", 16);
		exit(EXIT_FAILURE);
	}
}
