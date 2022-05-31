/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:09:09 by aoukhart          #+#    #+#             */
/*   Updated: 2022/04/21 01:55:59 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_param *param)
{
	if (param->map[param->player_y - 1][param->player_x] == 'C')
	{
		draw_floor(param, param->player_y, param->player_x);
		draw_floor(param, param->player_y - 1, param->player_x);
		param->c_count--;
		param->map[param->player_y - 1][param->player_x] = '0';
	}
	else
		draw_floor(param, param->player_y, param->player_x);
	if (param->map[param->player_y - 1][param->player_x] == 'E'
		&& param->c_count == 0)
	{
		ft_putstr_fd("GJ..WP", 1);
		exit(1);
	}
	if (param->map[param->player_y - 1][param->player_x] != 'E')
	{
		draw_player(param, --param->player_y,
			param->player_x, "Ressources/MoveUp.xpm");
		param->moves++;
	}
	else
		draw_player(param, param->player_y,
			param->player_x, "Ressources/MoveUp.xpm");
	ft_putnbr_fd(param->moves, 1);
}

void	move_right(t_param *param)
{
	if (param->map[param->player_y][param->player_x + 1] == 'C')
	{
		draw_floor(param, param->player_y, param->player_x);
		draw_floor(param, param->player_y, param->player_x + 1);
		param->c_count--;
		param->map[param->player_y][param->player_x + 1] = '0';
	}
	else
		draw_floor(param, param->player_y, param->player_x);
	if (param->map[param->player_y][param->player_x + 1] == 'E'
		&& param->c_count == 0)
	{
		ft_putstr_fd("GJ..WP", 1);
		exit(1);
	}
	if (param->map[param->player_y][param->player_x + 1] != 'E')
	{
		draw_player(param, param->player_y,
			++param->player_x, "Ressources/MoveRight.xpm");
		param->moves++;
	}
	else
		draw_player(param, param->player_y,
			param->player_x, "Ressources/MoveRight.xpm");
	ft_putnbr_fd(param->moves, 1);
}

void	move_left(t_param *param)
{
	if (param->map[param->player_y][param->player_x - 1] == 'C')
	{
		draw_floor(param, param->player_y, param->player_x);
		draw_floor(param, param->player_y, param->player_x - 1);
		param->c_count--;
		param->map[param->player_y][param->player_x - 1] = '0';
	}
	else
		draw_floor(param, param->player_y, param->player_x);
	if (param->map[param->player_y][param->player_x - 1] == 'E'
		&& param->c_count == 0)
	{
		ft_putstr_fd("GJ..WP", 1);
		exit(1);
	}
	if (param->map[param->player_y][param->player_x - 1] != 'E')
	{
		draw_player(param, param->player_y,
			--param->player_x, "Ressources/MoveLeft.xpm");
		param->moves++;
	}
	else
		draw_player(param, param->player_y,
			param->player_x, "Ressources/MoveLeft.xpm");
	ft_putnbr_fd(param->moves, 1);
}

void	move_down(t_param *param)
{
	if (param->map[param->player_y + 1][param->player_x] == 'C')
	{
		draw_floor(param, param->player_y, param->player_x);
		draw_floor(param, param->player_y + 1, param->player_x);
		param->c_count--;
		param->map[param->player_y + 1][param->player_x] = '0';
	}
	else
		draw_floor(param, param->player_y, param->player_x);
	if (param->map[param->player_y + 1][param->player_x] == 'E'
		&& param->c_count == 0)
	{
		ft_putstr_fd("GJ..WP", 1);
		exit(1);
	}
	if (param->map[param->player_y + 1][param->player_x] != 'E')
	{
		draw_player(param, ++param->player_y,
			param->player_x, "Ressources/MoveDown.xpm");
		param->moves++;
	}
	else
		draw_player(param, param->player_y,
			param->player_x, "Ressources/MoveDown.xpm");
	ft_putnbr_fd(param->moves, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
