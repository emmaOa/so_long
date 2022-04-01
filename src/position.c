#include "so_long.h"
#include <stdio.h>

t_so_long	*ft_position_pec(t_so_long *solong)
{
	int i;
	size_t j;

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
