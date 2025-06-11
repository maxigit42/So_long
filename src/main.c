/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:46:56 by mwilline          #+#    #+#             */
/*   Updated: 2025/06/11 19:28:27 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	int	img_width;
	int	img_height;

	game->textures = malloc(sizeof(t_textures));
	game->textures->ground = mlx_xpm_file_to_image(game->mlx_ptr, GROUND,
			&img_width, &img_height);
	game->textures->wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL,
			&img_width, &img_height);
	game->textures->player = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER,
			&img_width, &img_height);
	game->textures->exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT,
			&img_width, &img_height);
	game->textures->coin = mlx_xpm_file_to_image(game->mlx_ptr, COIN,
			&img_width, &img_height);
}

void	resetdata(t_game *data, char *file)
{
	data->height = 0;
	data->width = 0;
	data->player = 0;
	data->coin = 0;
	data->exit = 0;
	data->x = 0;
	data->y = 0;
	data->temp = file;
	data->steps = 0;
	data->finish = 0;
	data->check_c = 0;
	data->check_e = 0;
	load_textures(data);
}

int	ft_frame(t_game *game)
{
	draw_map(game);
	return (0);
}

void	ft_init(t_game *game, char *argv)
{
	ft_check_ber(argv);
	resetdata(game, argv);
	read_map(game);
	create_map(game);
	check_map(game);
	control_map(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.mlx_ptr = mlx_init();
		if (!game.mlx_ptr)
			ft_error_pr("Error\nMLX initialization failed\n");
		ft_init(&game, argv[1]);
		game.win_ptr = mlx_new_window(game.mlx_ptr, game.width * 40, game.height
				* 40, "so_long");
		if (!game.win_ptr)
			ft_error_pr("Error\nFailed to create window\n");
		mlx_hook(game.win_ptr, 2, 1L << 0, ft_press_key, &game);
		mlx_hook(game.win_ptr, 17, 1L << 17, ft_exit, &game);
		mlx_loop_hook(game.mlx_ptr, ft_frame, &game);
		mlx_loop(game.mlx_ptr);
	}
	else
		ft_error_pr("Error\nInvalid arguments\n");
	return (0);
}
