/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:46:50 by mwilline          #+#    #+#             */
/*   Updated: 2024/12/09 18:07:12 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <X11/X.h> // Para los eventos como DestroyNotify
# include <X11/keysym.h> // Para las constantes de teclas como 65361 (Left Arrow)

# define MAP_WIDTH 9
# define MAP_HEIGHT 5

// Estructura para texturas
typedef struct s_textures
{
    void    *floor_img;
    void    *wall_img;
    void    *player_img;
    int     width;
    int     height;
}           t_textures;

// Estructura principal de datos
typedef struct s_data
{
    void        *mlx_ptr;
    void        *win_ptr;
    t_textures  textures;
    char        **map;
}               t_data;

int     load_textures(t_data *data, t_textures *textures);
void    draw_map(t_data *data, t_textures *textures);
int     move_player(int keycode, void *param);
int     on_destroy(t_data *data);

#endif
