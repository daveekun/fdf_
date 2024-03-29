/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:37:15 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/11 14:02:40 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1000
# define HEIGHT 1000

#include <MLX42/MLX42.h>
#include <stdio.h>
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;


typedef struct s_point3
{
	double	x;
	double	y;
	double	z;
	t_color	color;
}	t_point3;

typedef struct	s_point2
{
	double	x;
	double	y;
	t_color	color;
}	t_point2;

typedef struct s_settings
{
	float	rotation;
	int		center_x;
	int		center_y;
	int		index_offset_x;
	int		index_offset_y;
	double	zoom;
	double	elips_a;
	double	elips_b;
	int		map_width;
	int		map_height;
	double	depth;
	double	rotation_speed;
}	t_settings;

typedef struct s_mouse_event
{
	t_point2	start;
	t_point2	start_iso;
	t_point2	end;
} t_mouse_event;

typedef struct s_vector2
{
	double x;
	double y;	
}	t_vector2;

typedef struct s_param
{
	t_settings		*settings;
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_point3		**map;
	t_mouse_event	*mouse;
}	t_param;

void		render(mlx_image_t *image, t_point3 **map, t_settings *settings, mlx_t *mlx);
void		ft_hook(mlx_t *mlx, mlx_image_t *image, t_point3 **map, t_settings *settings);
t_point3	**parse_map(char *s, t_settings *settings);
void		get_base_vectors(t_vector2 *u, t_vector2 *v, t_settings *settings);
int			get_color(t_color color);
#endif