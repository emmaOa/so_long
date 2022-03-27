#include "so_long.h"
#include <stdio.h>

t_so_long	ft_position_pec(char **map, char a, int size, int len)
{
	int i;
	int j;
	t_so_long position;

	i = 0;
	position.p = -1;
	while (i < size)
	{
		j = 0;
		while (j < len - 1)
		{
			if (map[i][j] == a)
			{
				position.i = i;
				position.j = j;
				exit (0);
			}
			j++;
		}
		i++;
	}
	return (position);
}