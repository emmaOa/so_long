/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:01:23 by iouazzan          #+#    #+#             */
/*   Updated: 2022/04/01 23:27:50 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up_hook(t_so_long *solong)
{
	solong = ft_position_pec(solong);
	if (solong->map[solong->i - 1][solong->j] == '0'
		|| solong->map[solong->i - 1][solong->j] == 'C')
	{
		solong->mouve++;
		ft_printf("NB : %d\n", solong->mouve);
		if (solong->map[solong->i - 1][solong->j] == 'C')
			solong->nb_coll--;
		solong->map[solong->i - 1][solong->j] = 'P';
		solong->map[solong->i][solong->j] = '0';
		ft_afch_image(solong);
	}
	if (solong->map[solong->i - 1][solong->j] == 'E' && solong->nb_coll == 0)
	{
		solong->mouve++;
		ft_printf("NB : %d\n", solong->mouve);
		exit (0);
	}
}

void	ft_down_hook(t_so_long *solong)
{
	solong = ft_position_pec(solong);
	if (solong->map[solong->i + 1][solong->j] == '0'
		|| solong->map[solong->i + 1][solong->j] == 'C')
	{
		solong->mouve++;
		ft_printf("NB : %d\n", solong->mouve);
		if (solong->map[solong->i + 1][solong->j] == 'C')
			solong->nb_coll--;
		solong->map[solong->i + 1][solong->j] = 'P';
		solong->map[solong->i][solong->j] = '0';
		ft_afch_image(solong);
	}
	if (solong->map[solong->i + 1][solong->j] == 'E' && solong->nb_coll == 0)
	{
		solong->mouve++;
		ft_printf("NB : %d\n", solong->mouve);
		exit (0);
	}
}

void	ft_left_hook(t_so_long *solong)
{
	solong = ft_position_pec(solong);
	if (solong->map[solong->i][solong->j - 1] == '0'
		|| solong->map[solong->i][solong->j - 1] == 'C')
	{
		solong->mouve++;
		ft_printf("NB : %d\n", solong->mouve);
		if (solong->map[solong->i][solong->j - 1] == 'C')
			solong->nb_coll--;
		solong->map[solong->i][solong->j - 1] = 'P';
		solong->map[solong->i][solong->j] = '0';
		ft_afch_image(solong);
	}
	if (solong->map[solong->i][solong->j - 1] == 'E' && solong->nb_coll == 0)
	{
		solong->mouve++;
		ft_printf("NB : %d\n", solong->mouve);
		exit (0);
	}
}

void	ft_right_hook(t_so_long *solong)
{
	solong = ft_position_pec(solong);
	if (solong->map[solong->i][solong->j + 1] == '0'
		|| solong->map[solong->i][solong->j + 1] == 'C')
	{
		solong->mouve++;
		ft_printf("NB : %d\n", solong->mouve);
		if (solong->map[solong->i][solong->j + 1] == 'C')
			solong->nb_coll--;
		solong->map[solong->i][solong->j + 1] = 'P';
		solong->map[solong->i][solong->j] = '0';
		ft_afch_image(solong);
	}
	if (solong->map[solong->i][solong->j + 1] == 'E' && solong->nb_coll == 0)
	{
		solong->mouve++;
		ft_printf("NB : %d\n", solong->mouve);
		exit (0);
	}
}
