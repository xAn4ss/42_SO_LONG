/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:30:44 by aoukhart          #+#    #+#             */
/*   Updated: 2022/05/30 21:19:49 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	x;

	x = 1;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		while (x <= (n / 10))
		{
			x *= 10;
		}
		while (x > 0)
		{
			ft_putchar_fd((n / x) + '0', fd);
			n = n % x;
			x /= 10;
		}
	}
	write(fd, "\n", 1);
}

void	draw_env(t_param *param, int j, int i)
{
	if (param->map[j][i] == 'E')
	{	
		draw_floor(param, j, i);
		draw_exit(param, j, i);
		param->exit_x = i;
		param->exit_y = j;
		param->e_count++;
	}
	else if (param->map[j][i] == 'C')
	{	
		draw_floor(param, j, i);
		draw_collectible(param, j, i);
		param->c_count++;
	}
	else if (param->map[j][i] == 'P')
	{
		draw_floor(param, j, i);
		draw_player(param, j, i, "Ressources/MoveRight.xpm");
		param->player_x = i;
		param->player_y = j;
		param->p_count++;
	}
	else
		ft_error(param, 1);
}

void	map_check(t_param *param, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			if (s[i - 1] != '1' || s[i + 1] != '1')
			{
				ft_putstr_fd("Error.\n", 2);
				free(s);
				exit(0);
			}
		}
		i++;
	}
	param->map = ft_split(s, '\n');
	free(s);
}

void	map_reader(t_param *param, char *av)
{
	char	*buf;
	int		end;
	char	*s;

	end = 1;
	s = ft_calloc(1, 1);
	buf = ft_calloc(11, 1);
	if (!buf)
		exit(0);
	param->fd = open(av, O_RDONLY);
	while (end != 0)
	{
		end = read(param->fd, buf, 20);
		if (end == -1)
		{
			free(buf);
			exit (0);
		}
		buf[end] = '\0';
		if (end != 0)
			s = ft_strjoin(s, buf);
	}
	free(buf);
	map_check(param, s);
}
