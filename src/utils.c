/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:05:51 by mwilline          #+#    #+#             */
/*   Updated: 2025/06/11 22:37:52 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_and_free(t_game *game)
{
	free_map(game);
}

void	ft_error_pr(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(EXIT_FAILURE);
}

int	ft_exit(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	printf("\033[1;32m");
	printf("\n🎉🎉 YOU WON! 🎉🎉\n");
	printf("🏆 Congratulations, you collected all the items!\n");
	printf("\033[0m");
	exit(EXIT_SUCCESS);
}

void	ft_free_and_close(int fd, t_game *game, char *line)
{
	if (line)
		free(line);
	close(fd);
	free_map(game);
	ft_error_pr("Error\nMap height mismatch\n");
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}
