/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:17:13 by iouazzan          #+#    #+#             */
/*   Updated: 2022/03/24 18:43:58 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int ac, char *av[])
{
	int		len_ac;
	void	*mlx;
	void	*image;
	// char	*image_data;
	void	*win;
	int		bpp;
	int		size_len;
	
	bpp = 8 * 4;
	size_len = 400;
	len_ac = 0;
	if (ac != 2)
	{
		ft_prnt("error6\n");
		exit (1);
	}
	len_ac =  ft_strlen(av[ac - 1]);
	if (av[1][len_ac - 1] != 'r' || av[1][len_ac - 2] != 'e'
		|| av[1][len_ac - 3] != 'b' || av[1][len_ac - 4] != '.')
	{
		ft_prnt("error7\n");
		exit (1);
	}
	ft_map(av[ac - 1]);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 360, "so long");
	image = mlx_new_image(mlx, 100, 100);
	// image_data = mlx_get_data_addr(image, &bpp, &size_len, 0);
    mlx_loop(mlx);
}
