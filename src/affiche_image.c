#include "so_long.h"
#include <stdio.h>

t_so_long	*ft_insert_image(void *mlx, t_so_long *solong)
{
	int		wd;
	int		ht;

	solong->wall = mlx_xpm_file_to_image(mlx, "resources/images/wall.xpm", &wd, &ht);
	solong->player_1 = mlx_xpm_file_to_image(mlx, "resources/images/player_1.xpm", &wd, &ht);
	solong->player_2 = mlx_xpm_file_to_image(mlx, "resources/images/player_2.xpm", &wd, &ht);
	solong->space = mlx_xpm_file_to_image(mlx, "resources/images/space.xpm", &wd, &ht);
	solong->collectible = mlx_xpm_file_to_image(mlx, "resources/images/collectible.xpm", &wd, &ht);
	return (solong);
}

void	ft_image(t_so_long *solong,int i, int j, void *mlx, void *win)
{
	if (solong->map[i][j] == '1')
		mlx_put_image_to_window(mlx, win, solong->wall, j * 64, i * 64);
	if (solong->map[i][j] == '0')
		mlx_put_image_to_window(mlx, win, solong->space, j * 64, i * 64);
	if (solong->map[i][j] == 'P')
	{
		mlx_put_image_to_window(mlx, win, solong->space, j * 64, i * 64);
		mlx_put_image_to_window(mlx, win, solong->player_1, j * 64, i * 64);
	}
	if (solong->map[i][j] == 'E')
	{
		mlx_put_image_to_window(mlx, win, solong->space, j * 64, i * 64);
		mlx_put_image_to_window(mlx, win, solong->player_2, j * 64, i * 64);
	}
	if (solong->map[i][j] == 'C')
	{
		mlx_put_image_to_window(mlx, win, solong->space, j * 64, i * 64);
		mlx_put_image_to_window(mlx, win, solong->collectible, j * 64, i * 64);
	}
}

void	ft_afch_image(t_so_long *solong)
{
	int		i;
	size_t	j;

	i = 0;
	solong = ft_insert_image(solong->mlx, solong);
	while (i < solong->size)
	{
		j = 0;
		while (j < solong->len - 1)
		{
			ft_image(solong, i, j, solong->mlx, solong->win);
			j++;
		}
		i++;
	}
}
