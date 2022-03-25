/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:17:13 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/25 11:16:11 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_check_extention(int ac, char *av[])
{
	int		len_ac;

	len_ac =  ft_strlen(av[ac - 1]);
	if (ac != 2)
	{
		ft_prnt("error6\n");
		exit (1);
	}
	len_ac =  ft_strlen(av[ac - 1]);
	if (len_ac < 4)
	{
		ft_prnt("error8\n");
		exit (1);
	}
	if (av[1][len_ac - 1] != 'r' || av[1][len_ac - 2] != 'e'
		|| av[1][len_ac - 3] != 'b' || av[1][len_ac - 4] != '.')
	{
		ft_prnt("error7\n");
		exit (1);
	}
}

int	main(int ac, char *av[])
{
	
	void	*mlx;
	void	*image;
	void	*win;
	int		wd;
	int		ht;
	
	ft_check_extention(ac, av);
	ft_map(av[ac - 1]);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 360, "so long");
	image = mlx_xpm_file_to_image(mlx, "resources/images/wall.xpm", &wd, &ht);
	mlx_put_image_to_window(mlx, win, image, 0, 0);
    mlx_loop(mlx);
}
