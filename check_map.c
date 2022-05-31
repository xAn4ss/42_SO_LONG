/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 02:24:36 by aoukhart          #+#    #+#             */
/*   Updated: 2022/05/26 15:34:09 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_param *param, int i)
{
	if (i == 1)
		ft_putstr_fd("Error.\n", 2);
	ft_free(param->map);
	exit(0);
}

void	check_lenth(t_param *param)
{
	int	i;
	int	size;

	i = 1;
	size = ft_strlen(param->map[0]);
	while (param->map[i])
	{
		if ((int)ft_strlen(param->map[i]) != size)
			ft_error(param, 1);
		i++;
	}
}

int	check_x(t_param *param)
{
	int	lastlineindex;

	lastlineindex = 0;
	while (*(param->map + lastlineindex))
		lastlineindex++;
	lastlineindex--;
	while (param->map[0][param->size_x])
	{
		if (param->map[0][param->size_x] == '1'
			&& param->map[lastlineindex][param->size_x] == '1')
				param->size_x++;
		else
			ft_error(param, 1);
	}
	return (lastlineindex);
}

void	*window_size(t_param *param)
{
	int	lastlineindex;

	lastlineindex = check_x(param);
	while (param->size_y <= lastlineindex)
	{
		if (param->map[param->size_y][0] == '1'
			&& param->map[param->size_y][param->size_x - 1] == '1')
				param->size_y++;
		else
			ft_error(param, 1);
	}
	check_lenth(param);
	return (param);
}

void	check_arg(char *av)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(av);
	size--;
	if (av[size - 3] != '.' || av[size - 2] != 'b' || av[size - 1] != 'e'
		|| av[size] != 'r')
	{
		ft_putstr_fd("Error.\n", 2);
		exit (0);
	}
}
