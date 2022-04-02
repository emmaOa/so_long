/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:01:30 by iouazzan          #+#    #+#             */
/*   Updated: 2022/04/02 08:55:59 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fatal(char *s)
{
	ft_printf("Error\n");
	ft_printf("%s\n", s);
	exit(1);
}

t_so_long	*ft_position_pec(t_so_long *solong)
{
	int		i;
	size_t	j;

	i = 0;
	solong->p = -1;
	while (i < solong->size)
	{
		j = 0;
		while (j < solong->len - 1)
		{
			if (solong->map[i][j] == 'P')
			{
				solong->i = i;
				solong->j = j;
			}
			j++;
		}
		i++;
	}
	return (solong);
}

void	ft_position(char **map, int i, int j, t_so_long *pos)
{
	if (map[i][j] == 'P')
	{
		pos->i = i;
		pos->j = j;
	}
	if (map[i][j] == 'E')
	{
		pos->i = i;
		pos->j = j;
	}
}
