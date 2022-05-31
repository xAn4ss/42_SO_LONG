/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:20:15 by aoukhart          #+#    #+#             */
/*   Updated: 2022/05/26 15:35:20 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_param
{
	void	*mlx;
	void	*win;
	void	*img;
	int		size_x;
	int		size_y;
	int		c_count;
	int		p_count;
	int		e_count;
	int		exit_x;
	int		exit_y;
	int		player_x;
	int		player_y;
	char	**map;
	int		h8;
	int		moves;
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	int		fd;
}	t_param;

void	*ft_memset(void *b, int c, size_t len);
void	img_to_screen(t_param *param);
void	draw_env(t_param *param, int j, int i);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
void	move_right(t_param *param);
void	move_up(t_param *param);
void	move_left(t_param *param);
void	move_down(t_param *param);
void	draw_wall(t_param *param, int j, int i);
void	draw_floor(t_param *param, int j, int i);
void	draw_collectible(t_param *param, int j, int i);
void	draw_player(t_param *param, int j, int i, char *PathToXpm);
void	draw_exit(t_param *param, int j, int i);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
void	*window_size(t_param *param);
void	map_reader(t_param *param, char *av);
void	ft_error(t_param *param, int i);
char	**ft_free(char **str);
void	check_arg(char *av);

#endif