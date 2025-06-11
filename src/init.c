/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:08:11 by mwilline          #+#    #+#             */
/*   Updated: 2025/06/11 22:16:45 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game)
{
	int		fd;
	char	*line;
	char	*line_trim;

	fd = open(game->temp, O_RDONLY);
	if (fd < 0)
		ft_error_pr("Error\nFD\n");
	line = get_next_line(fd);
	if (!line)
		ft_error_pr("Error\nMap not valid\n");
	line_trim = ft_strtrim(line, " \t\n");
	game->width = ft_strlen(line_trim);
	game->height = 0;
	while (line)
	{
		game->height++;
		if ((int)ft_strlen(line_trim) != game->width)
			ft_error_pr("Error\nMap not valid\n");
		free(line_trim);
		free(line);
		line = get_next_line(fd);
		if (line)
			line_trim = ft_strtrim(line, " \t\n");
	}
	close(fd);
}

void	create_map(t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		ft_error_pr("Error\nCreate malloc\n");
	fd = open(game->temp, O_RDONLY);
	if (fd < 0)
		ft_error_and_free(game);
	i = 0;
	line = get_next_line(fd);
	while (i < game->height && line)
	{
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
			ft_free_and_close(fd, game, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (i < game->height)
		ft_free_and_close(fd, game, line);
	game->map[i] = NULL;
	close(fd);
}
