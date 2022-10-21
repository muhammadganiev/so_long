/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:54:57 by muganiev          #+#    #+#             */
/*   Updated: 2022/10/21 20:11:09 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_img_render(t_game *game, char *path, int x, int y)
{
	int	size;

	size = 64;
	x = x * size;
	y = y * size;
	game->img = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, x, y);
	mlx_destroy_image(game->mlx, game->img);
}

void	put_image_and_find_player(t_game *game, char c, int x, int y)
{
	if (c == '0')
		ft_img_render(game, GROUND, x, y);
	if (c == '1')
	{
		ft_img_render(game, GROUND, x, y);
		ft_img_render(game, WALL, x, y);
	}
	if (c == 'P')
	{
		game->ppx = x;
		game->ppy = y;
		ft_img_render(game, GROUND, x, y);
		ft_img_render(game, PLAYER, x, y);
	}
	if (c == 'C')
	{
		ft_img_render(game, GROUND, x, y);
		ft_img_render(game, COIN, x, y);
	}
	if (c == 'E')
	{
		ft_img_render(game, GROUND, x, y);
		ft_img_render(game, EXIT, x, y);
	}
}

void	ft_render_window(t_game *game)
{
	int	ww;
	int	wh;

	ww = game->w * 100;
	wh = game->h * 100;
	game->mlx_win = mlx_new_window(game->mlx, ww, wh, "SO_LONG");
}

void	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	ft_render_window(game);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put_image_and_find_player(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}