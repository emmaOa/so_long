/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:17:13 by iouazzan          #+#    #+#             */
/*   Updated: 2022/04/02 08:55:26 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_extention(int ac, char *av[])
{
	int	len_ac;

	len_ac = ft_strlen(av[ac - 1]);
	if (ac != 2)
		fatal("ac != 2");
	len_ac = ft_strlen(av[ac - 1]);
	if (len_ac < 4)
		fatal("extension not valid");
	if (av[1][len_ac - 1] != 'r' || av[1][len_ac - 2] != 'e'
		|| av[1][len_ac - 3] != 'b' || av[1][len_ac - 4] != '.')
		fatal("extension not valid");
}

int	key_hook(int keycode, t_so_long *solong)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 0 || keycode == 123)
		ft_left_hook(solong);
	if (keycode == 1 || keycode == 125)
		ft_down_hook(solong);
	if (keycode == 2 || keycode == 124)
		ft_right_hook(solong);
	if (keycode == 13 || keycode == 126)
		ft_up_hook(solong);
	return (0);
}

int	ft_exit(void)
{
	exit(1);
}

int	main(int ac, char *av[])
{
	t_so_long	solong;

	ft_check_extention(ac, av);
	solong = ft_map(av[ac - 1]);
	solong.mlx = mlx_init();
	solong.win = mlx_new_window(solong.mlx,
			(solong.len - 1) * 64, solong.size * 64, "so long");
	ft_afch_image(&solong);
	mlx_hook(solong.win, 17, 0, ft_exit, NULL);
	mlx_key_hook(solong.win, key_hook, &solong);
	mlx_loop(solong.mlx);
}
