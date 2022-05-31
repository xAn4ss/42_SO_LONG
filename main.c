/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:20:01 by aoukhart          #+#    #+#             */
/*   Updated: 2022/05/30 22:37:13 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit(int keycode, t_param *param)
{
	if (keycode > 0)
		ft_free(param->map);
	exit(0);
}

int	key_hook(int button, t_param *param)
{
	if (button == 53)
		ft_error(param, 0);
	else if (button == 13 || button == 126)
	{
		if (param->map[param->player_y - 1][param->player_x] != '1')
			move_up(param);
	}
	else if (button == 2 || button == 124)
	{
		if (param->map[param->player_y][param->player_x + 1] != '1')
			move_right(param);
	}
	else if (button == 0 || button == 123)
	{
		if (param->map[param->player_y][param->player_x - 1] != '1')
			move_left(param);
	}
	else if (button == 1 || button == 125)
	{
		if (param->map[param->player_y + 1][param->player_x] != '1')
			move_down(param);
	}
	return (0);
}

void	img_to_screen(t_param *param)
{
	int	i;
	int	j;

	j = 0;
	while (param->map[j])
	{
		i = 0;
		while (param->map[j][i])
		{
			if (param->map[j][i] == '1')
			{
				draw_floor(param, j, i);
				draw_wall(param, j, i);
			}
			else if (param->map[j][i] == '0')
				draw_floor(param, j, i);
			else
				draw_env(param, j, i);
			i++;
		}
		j++;
	}
	if (param->c_count == 0 || param->e_count == 0 || param->p_count != 1)
		ft_error(param, 1);
}

void	param_init(t_param *param)
{
	param->size_x = 0;
	param->size_y = 0;
	param->img = 0;
	param->c_count = 0;
	param->e_count = 0;
	param->p_count = 0;
	param->mlx = 0;
	param->win = 0;
	param->exit_x = 0;
	param->exit_y = 0;
	param->moves = 0;
	param->h8 = 0;
	param->mlx = mlx_init();
}

int	main(int ac, char **av)
{
	t_param	prm;

	if (ac == 2)
	{
		param_init(&prm);
		check_arg(av[1]);
		map_reader(&prm, av[1]);
		if (!(window_size(&prm)))
			ft_error(&prm, 1);
		prm.win = mlx_new_window
			(prm.mlx, 40 * prm.size_x, 40 * prm.size_y, "So_long");
		if (!prm.win)
			ft_error(&prm, 1);
		img_to_screen(&prm);
		mlx_key_hook(prm.win, key_hook, &prm);
		mlx_hook(prm.win, 17, 1L << 2, quit, &prm);
		mlx_loop(prm.mlx);
	}
	else
	{
		ft_putstr_fd("Error.\n", 2);
		exit(0);
	}
}
