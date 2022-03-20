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

void	ft_map(char *path)
{
	t_list *map;
	char *tmp;
	char	**vl_map;
	int	fd;
	int i;
	size_t len;
	int size;

	i = 0;
	fd = open(path, O_RDONLY); // protect fd
	tmp = get_next_line(fd);
	len = ft_strlen(tmp);
	while (tmp != NULL)
	{
		ft_lstadd_back(&map, ft_lstnew(tmp));
		tmp = get_next_line(fd);
	}

	size = ft_lstsize(map);
	vl_map = malloc(( size + 1) * sizeof(char *));
	while (map != NULL)
	{
		if ((map->next == NULL && len - 1 != ft_strlen(map->content)) || (len != ft_strlen(map->content) && map->next != NULL))
		{
			ft_prnt("error4");
			exit (1);
		}
		vl_map[i++] = map->content;
		ft_prnt(vl_map[i - 1]); 
		map = map->next;
	}
	len = ft_strlen(vl_map[0]);
	ft_check_map(vl_map, size, len);
}

void	ft_check_map(char **map, int size, int len)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < len - 1)
		{
			if (map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
			{
				printf("%c", map[i][j]);
				ft_prnt("error2");
				exit (1);
			}
			if (map[i][j] != '1')
			{
				ft_char_map(map, i, j, size, len);
			}
			j++;
		}
		i++;
	}
}

void	ft_char_map(char **map, int i, int j, int size, int len)
{
	if (j == len - 2 || i == size - 1 || j == 0 || i == 0)
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