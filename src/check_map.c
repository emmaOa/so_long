/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:00:51 by iouazzan          #+#    #+#             */
/*   Updated: 2022/04/02 21:03:34 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_2(t_so_long *solong, t_list *map)
{
	int			i;
	t_list		*tm;

	i = 0;
	solong->map = malloc((solong->size + 1) * sizeof(char *));
	while (map != NULL)
	{
		if ((map->next == NULL && solong->len - 1 != ft_strlen(map->content))
			|| (solong->len != ft_strlen(map->content) && map->next != NULL))
			fatal("line not valid");
		solong->map[i++] = map->content;
		tm = map;
		map = map->next;
		free(tm);
	}
	solong->len = ft_strlen(solong->map[0]);
}

t_so_long	ft_map(char *path)
{
	t_so_long	solong;
	t_list		*map;
	char		*tmp;
	int			fd;

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
	fd = 0;
	solong.size = ft_lstsize(map);
	ft_map_2(&solong, map);
	solong = ft_check_map(&solong);
	return (solong);
}

int	ft_check_map_2(t_so_long *solong, int i, int j)
{
	int	p;

	p = 0;
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
			{
				solong->p = 1;
				p = 1;
			}
			if (solong->map[i][j] == 'E')
				solong->e = 1;
			ft_position(solong->map, i, j, solong);
		}
		ft_char_map(i, j, solong);
	}
	return (p);
}

t_so_long	ft_check_map(t_so_long *solong)
{
	size_t	j;
	int		i;
	int		p;

	i = -1;
	p = 0;
	while (++i < solong->size)
	{
		j = -1;
		while (++j < solong->len - 1)
		{
			if (solong->map[i][j] != 'P' && solong->map[i][j]
				!= 'C' && solong->map[i][j] != 'E'
				&& solong->map[i][j] != '0' && solong->map[i][j]
				!= '1' && solong->map[i][j] != ' ')
				fatal("line not valid");
			if (ft_check_map_2(solong, i, j) == 1)
				p++;
		}
	}
	if (solong->c == 0 || solong->e == 0 || solong->p == 0 || p != 1)
		fatal("line not valid");
	return (*solong);
}

void	ft_char_map(int i, size_t j, t_so_long *solong)
{
	if (j == solong->len - 2 || i == solong->size - 1 || j == 0 || i == 0)
		fatal("line not valid");
	if (solong->map[i][j + 1] == ' ' || solong->map[i][j - 1] == ' '
		|| solong->map[i + 1][j] == ' ' || solong->map[i - 1][j] == ' ')
		fatal("line not valid");
}
