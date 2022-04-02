/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:48:31 by iouazzan          #+#    #+#             */
/*   Updated: 2022/04/01 23:53:28 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"

typedef struct t_so_long
{
	void		*mlx;
	void		*win;
	int			i;
	int			j;
	int			c;
	int			e;
	int			p;
	int			nb_coll;
	int			num_p;
	int			mouve;
	int			size;
	size_t		len;
	void		*wall;
	void		*player_1;
	void		*player_2;
	void		*space;
	void		*collectible;
	char		**map;
}	t_so_long;

t_so_long	ft_map(char *path);
t_so_long	ft_check_map(t_so_long *solong);
void		ft_char_map(int i, size_t j, t_so_long *solong);
void		ft_position(char **map, int i, int j, t_so_long *pos);
t_so_long	*ft_position_pec(t_so_long *solong);
void		ft_check_extention(int ac, char *av[]);
void		ft_afch_image(t_so_long *solong);
t_so_long	*ft_insert_image(void *mlx, t_so_long *solong);
void		fatal(char *s);
void		ft_up_hook(t_so_long *solong);
void		ft_down_hook(t_so_long *solong);
void		ft_left_hook(t_so_long *solong);
void		ft_right_hook(t_so_long *solong);
#endif