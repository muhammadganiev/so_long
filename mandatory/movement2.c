/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:04:05 by muganiev          #+#    #+#             */
/*   Updated: 2022/10/19 16:02:58 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_if_flag2_flag3_render(t_game *game, int next_x, int next_y)
{
	if (game->flag == 2)
	{
		ft_img_render(game, GROUND, next_x, next_y);
		ft_img_render(game, PLAYER, next_x, next_y);
		ft_img_render(game, EXIT, game->ppx, game->ppy);
		game->ppx = next_x;
		game->ppy = next_y;
		game->flag = 0;
	}
	if (game->flag == 3)
	{
		ft_img_render(game, EXIT, next_x, next_y);
		ft_img_render(game, PLAYER, next_x, next_y);
		ft_img_render(game, EXIT, game->ppx, game->ppy);
		game->ppx = next_x;
		game->ppy = next_y;
		game->flag = 1;
	}
}

void	ft_render_move(t_game *game, int next_x, int next_y)
{
	if (game->flag == 0)
	{
		ft_img_render(game, GROUND, next_x, next_y);
		ft_img_render(game, PLAYER, next_x, next_y);
		ft_img_render(game, GROUND, game->ppx, game->ppy);
		game->ppx = next_x;
		game->ppy = next_y;
	}
	if (game->flag == 1)
	{
		ft_img_render(game, EXIT, next_x, next_y);
		ft_img_render(game, PLAYER, next_x, next_y);
		ft_img_render(game, GROUND, game->ppx, game->ppy);
		game->ppx = next_x;
		game->ppy = next_y;
	}
	ft_if_flag2_flag3_render(game, next_x, next_y);
}

void	ft_met_exit(t_game *game, int next_x, int next_y)
{
	if (game->map[next_y][next_x] == 'E' && game->collectible_item == 0)
		ft_close_window(game);
	if (game->map[next_y][next_x] == 'E' && game->collectible_item > 0)
	{
		game->flag = 1;
		game->map[next_y][next_x] = 'P';
		game->map[game->ppy][game->ppx] = '0';
	}
}