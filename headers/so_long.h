/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:48:31 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/25 10:58:52 by iouazzan         ###   ########.fr       */
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

typedef struct t_position
{
	int	i;
	int	j;
	int	p;
}	t_position;

typedef struct t_valid
{
	int	c;
	int	e;
	int	p;
}	t_valid;

void		ft_map(char *path);
void	ft_prnt(char *str);
void		ft_check_map(char **map, int size, int len);
void		ft_char_map(char **map, int i, int j, int size, int len);
t_position	ft_position(char **map, int i, int j);
t_position	ft_position_pec(char **map, char a, int size, int len);
void	ft_check_extention(int ac, char *av[]);
#endif