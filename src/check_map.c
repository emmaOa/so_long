/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:00:51 by iouazzan          #+#    #+#             */
/*   Updated: 2022/04/01 23:42:08 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>


t_so_long	ft_map(char *path)
{
	t_so_long	solong;
	t_list		*map;
	char		*tmp;
	int			fd;
	int			i;

	i = 0;
	map = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		fatal("!map");
	tmp = get_next_line(fd);
	if (!tmp)
		fatal("!map");
	solong.len = ft_strlen(tmp);
	while (tmp != NULL)
	{
		ft_lstadd_back(&map, ft_lstnew(tmp));
		tmp = get_next_line(fd);
	}	
	solong.size = ft_lstsize(map);
	solong.map = malloc(( solong.size + 1) * sizeof(char *));
	while (map != NULL)
	{
		if ((map->next == NULL && solong.len - 1 != ft_strlen(map->content))
			|| (solong.len != ft_strlen(map->content) && map->next != NULL))
			fatal("line not valid");
		solong.map[i++] = map->content;
		free(map);
		map = map->next;
	}
	solong.len = ft_strlen(solong.map[0]);
	solong = ft_check_map(&solong);
	return (solong);
}

// void	ft_check_map_2()
// {

// }

t_so_long	ft_check_map(t_so_long *solong)
{
	size_t	j;
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (i < solong->size)
	{
		j = 0;
		while (j < solong->len - 1)
		{
			if (solong->map[i][j] != 'P' && solong->map[i][j] != 'C' && solong->map[i][j] != 'E'
				&& solong->map[i][j] != '0' && solong->map[i][j] != '1' && solong->map[i][j] != ' ')
				fatal("line not valid");
			if (solong->map[i][j] != '1')
			{
				if (solong->map[i][j] == 'C')
				{
					solong->c = 1;
					solong->nb_coll++;
				}
				if (solong->map[i][j] == 'P' || solong->map[i][j] == 'E')
				{
					if (solong->map[i][j] == 'P')
						solong->p = 1;
					if (solong->map[i][j] == 'E')
						solong->e = 1;
					ft_position(solong->map, i, j, solong);
					if (solong->num_p == 1)
						p++;
					if (p > 1)
						fatal("line not valid");
				}
				
				ft_char_map(i, j, solong);
			}
			j++;
		}
		i++;
	}
	if (solong->c == 0 || solong->e == 0 || solong->p == 0)
		fatal("line not valid");
	return (*solong);
}

void	ft_char_map(int i,size_t j, t_so_long *solong)
{
	if (j == solong->len - 2 || i == solong->size - 1 || j == 0 || i == 0)
		fatal("line not valid");
	if (solong->map[i][j + 1] == ' ' || solong->map[i][j - 1] == ' '
		|| solong->map[i + 1][j] == ' ' || solong->map[i - 1][j] == ' ')
		fatal("line not valid");
}

void	ft_position(char **map, int i, int j, t_so_long *pos)
{
	pos->num_p = 0;
	if (map[i][j] == 'P')
	{
		pos->i = i;
		pos->j = j;
		pos->num_p = 1;
	}
	if (map[i][j] == 'E')
	{
		pos->i = i;
		pos->j = j;
	}
}
