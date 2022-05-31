/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_Drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:08:00 by aoukhart          #+#    #+#             */
/*   Updated: 2022/05/20 19:48:53 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_floor(t_param *param, int j, int i)
{
	param->img = mlx_xpm_file_to_image
		(param->mlx, "Ressources/Floor.xpm", &param->h8, &param->h8);
	if (param->img == 0)
		ft_error(param, 1);
	mlx_put_image_to_window(param->mlx, param->win, param->img, i * 40, j * 40);
}

void	draw_wall(t_param *param, int j, int i)
{
	param->img = mlx_xpm_file_to_image
		(param->mlx, "Ressources/Wall.xpm", &param->h8, &param->h8);
	if (param->img == 0)
		ft_error(param, 1);
	mlx_put_image_to_window(param->mlx, param->win, param->img, i * 40, j * 40);
}

void	draw_collectible(t_param *param, int j, int i)
{
	param->img = mlx_xpm_file_to_image
		(param->mlx, "Ressources/PokeCollec.xpm", &param->h8, &param->h8);
	if (param->img == 0)
		ft_error(param, 1);
	mlx_put_image_to_window(param->mlx, param->win, param->img, i * 40, j * 40);
}

void	draw_player(t_param *param, int j, int i, char *PathToXpm)
{
	param->img = mlx_xpm_file_to_image
		(param->mlx, PathToXpm, &param->h8, &param->h8);
	if (param->img == 0)
		ft_error(param, 1);
	mlx_put_image_to_window(param->mlx, param->win, param->img, i * 40, j * 40);
}

void	draw_exit(t_param *param, int j, int i)
{
	param->img = mlx_xpm_file_to_image
		(param->mlx, "Ressources/Exit.xpm", &param->h8, &param ->h8);
	if (param->img == 0)
		ft_error(param, 1);
	mlx_put_image_to_window(param->mlx, param->win, param->img, i * 40, j * 40);
}
