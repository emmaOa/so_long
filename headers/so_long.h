/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:48:31 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/27 02:12:08 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
// # define WIN_WIDTH 1024
// # define WIN_HEIGHT 640

typedef struct t_so_long
{
	int		i;
	int		j;
	int		c;
	int		e;
	int		p;
	int		num_p;
	int		size;
	size_t		len;
	void	*wall;
	void	*player_1;
	void	*player_2;
	void	*space;
	void	*collectible;
	char	**map;
}		t_so_long;  

t_so_long	ft_map(char *path);
void	ft_prnt(char *str);
void	ft_check_map(char **map, t_so_long solong);
void	ft_char_map(char **map, int i, size_t j, t_so_long solong);
void	ft_position(char **map, int i, int j, t_so_long *pos);
t_so_long	ft_position_pec(char **map, char a, int size, int len);
void	ft_check_extention(int ac, char *av[]);
void	ft_afch_image(void *mlx, void *win, t_so_long solong);
t_so_long	ft_insert_image(void *mlx, t_so_long *solong);
void fatal(char *s);
#endif