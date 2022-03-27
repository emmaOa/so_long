#include "so_long.h"
#include <stdio.h>

void	ft_prnt(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void fatal(char *s)
{
	ft_prnt("Error\n");
	ft_prnt(s);
	exit(1);
}

t_so_long	ft_map(char *path)
{
	t_list *map;
	char *tmp;
	// char	**vl_map;
	t_so_long	solong;
	int	fd;
	int i;

	i = 0;
	map = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_prnt("error8");
		exit (1);
	}
	tmp = get_next_line(fd);
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
		if ((map->next == NULL && solong.len - 1 != ft_strlen(map->content)) || (solong.len != ft_strlen(map->content) && map->next != NULL))
		{
			ft_prnt("error4");
			exit (1);
		}
		solong.map[i++] = map->content;
		ft_prnt(solong.map[i - 1]); 
		map = map->next;
	}
	solong.len = ft_strlen(solong.map[0]);
	ft_check_map(solong.map, solong);
	return (solong);
}

void	ft_check_map(char **map, t_so_long solong)
{
	int	i;
	size_t	j;
	int	p;

	i = 0;
	p = 0;
	solong.c = 0;
	solong.p = 0;
	solong.e = 0;
	while (i < solong.size)
	{
		j = 0;
		while (j < solong.len - 1)
		{
			if (map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E'
				&& map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
			{
				ft_prnt("error2");
				exit (1);
			}
			if (map[i][j] != '1')
			{
				if (map[i][j] == 'C')
					solong.c = 1;
				if (map[i][j] == 'P' || map[i][j] == 'E')
				{
					if (map[i][j] == 'P')
						solong.p = 1;
					if (map[i][j] == 'E')
						solong.e = 1;
					ft_position(map, i, j, &solong);
					if (solong.num_p == 1)
						p++;
					if (p > 1)
					{
						ft_prnt("error4");
						exit (1);
					}
				}
				
				ft_char_map(map, i, j, solong);
			}
			j++;
		}
		i++;
	}
	if (solong.c == 0 || solong.e == 0 || solong.p == 0)
	{
		ft_prnt("error5");
		exit (1);
	}
}

void	ft_char_map(char **map, int i,size_t j, t_so_long solong)
{
	if (j == solong.len - 2 || i == solong.size - 1 || j == 0 || i == 0)
	{
		ft_prnt("error3");
		exit (1);
	}
	if (map[i][j + 1] == ' ' || map[i][j - 1] == ' ' || map[i + 1][j] == ' ' || map[i - 1][j] == ' ')
	{
		ft_prnt("error1");
		exit (1);
	}
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
