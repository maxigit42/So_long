/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:46:50 by mwilline          #+#    #+#             */
/*   Updated: 2025/06/11 21:30:15 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define GROUND "./images/empty.xpm"
# define EXIT "./images/exit.xpm"
# define PLAYER "./images/player.xpm"
# define WALL "./images/wall.xpm"
# define COIN "./images/collect.xpm"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

// Estructura para texturas
typedef struct s_textures
{
	void		*player;
	void		*wall;
	void		*exit;
	void		*coin;
	void		*ground;
}				t_textures;

// Estructura principal de datos
typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			width;
	int			height;
	int			player;
	int			y;
	int			x;
	int			coin;
	int			steps;
	int			exit;
	int			finish;
	int			redraw;
	char		*temp;
	char		**copy;
	int			check_c;
	int			check_e;
	t_textures	*textures;
}				t_game;

// map

void			create_map(t_game *game);
void			draw_map(t_game *game);
void			put_wall(t_game *game, int *i, int *j);
void			put_player(t_game *game, int *i, int *j);
void			put_ground(t_game *game, int *j, int *i);
void			put_exit(t_game *game, int *j, int *i);

//init

void			read_map(t_game *game);
void 			clean_n(t_game *game, int fd);

//keys

void			d_key(t_game *game);
void			a_key(t_game *game);
void			s_key(t_game *game);
void			w_key(t_game *game);
int				ft_press_key(int key, t_game *game);
void			update_position(t_game *game, int new_y, int new_x);

//check

void			check_map(t_game *game);
void			ft_check_outline(t_game *game);
void			ft_check_valid(t_game *game);
void			ft_check_elements(t_game *game);
void			ft_check_ber(char *map);

//utils

void			ft_error(void);
int				ft_exit(t_game *game);
void			ft_error_pr(char *msg);
void			ft_free_and_close(int fd, t_game *game, char *line);
void			ft_error_and_free(t_game *game);
void			free_map(t_game *game);

void			control_map(t_game *game);

#endif