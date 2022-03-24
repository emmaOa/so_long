#include "so_long.h"
#include <stdio.h>

t_position	ft_position_pec(char **map, char a, int size, int len)
{
	int i;
	int j;
	t_position position;

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
				position.p = a;
				exit (0);
			}
			j++;
		}
		i++;
	}
	return (position);
}