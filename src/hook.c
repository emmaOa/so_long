#include "so_long.h"
#include <stdio.h>

void	ft_up_hook(t_so_long *solong)
{
	solong = ft_position_pec(solong);
	if (solong->map[solong->i - 1][solong->j] == '0' || solong->map[solong->i - 1][solong->j] == 'C')
	{
		solong->mouve++;
		if (solong->map[solong->i - 1][solong->j] == 'C')
			solong->nb_coll--;
		solong->map[solong->i - 1][solong->j] = 'P';
		solong->map[solong->i][solong->j] = '0';
		ft_afch_image(solong);
	}
	if (solong->map[solong->i - 1][solong->j] == 'E' && solong->nb_coll == 0)
		exit (0);
}

void	ft_down_hook(t_so_long *solong)
{
	solong = ft_position_pec(solong);
	if (solong->map[solong->i + 1][solong->j] == '0' || solong->map[solong->i + 1][solong->j] == 'C')
	{
		if (solong->map[solong->i + 1][solong->j] == 'C')
			solong->nb_coll--;
		solong->map[solong->i + 1][solong->j] = 'P';
		solong->map[solong->i][solong->j] = '0';
		ft_afch_image(solong);
	}
	if (solong->map[solong->i + 1][solong->j] == 'E' && solong->nb_coll == 0)
		exit (0);
}

void	ft_left_hook(t_so_long *solong)
{
	solong = ft_position_pec(solong);
	if (solong->map[solong->i][solong->j - 1] == '0' || solong->map[solong->i][solong->j - 1] == 'C')
	{
		if (solong->map[solong->i][solong->j - 1] == 'C')
			solong->nb_coll--;
		solong->map[solong->i][solong->j - 1] = 'P';
		solong->map[solong->i][solong->j] = '0';
		ft_afch_image(solong);
	}
	if (solong->map[solong->i][solong->j - 1] == 'E' && solong->nb_coll == 0)
		exit (0);
}

void	ft_right_hook(t_so_long *solong)
{
	solong = ft_position_pec(solong);
	if (solong->map[solong->i][solong->j + 1] == '0' || solong->map[solong->i][solong->j + 1] == 'C')
	{
		if (solong->map[solong->i][solong->j + 1] == 'C')
			solong->nb_coll--;
		solong->map[solong->i][solong->j + 1] = 'P';
		solong->map[solong->i][solong->j] = '0';
		ft_afch_image(solong);
	}
	if (solong->map[solong->i][solong->j + 1] == 'E' && solong->nb_coll == 0)
		exit (0);
}
