/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:59:45 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/27 13:19:40 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long/so_long.h"

void	map_validity(t_mlx *mlx, int argc, char *mapf)
{
	if (argc == 2)
	{
		init_map(mlx);
		mlx->fd = open(mapf, O_RDONLY);
		if (mlx->fd < 0)
			exit_error(3);
		mlx->line = get_next_line(mlx->fd);
		mlx->len = ft_strlen(mlx->line);
		mlx->columns = mlx->len - 1;
		map_name(mapf);
		map_top(mlx->line, mlx);
		map_mid_end(mlx->line, mlx);
		map_pec_size(mlx);
		mlx->map_in_array = map_in_array(mapf, mlx);
	}
	else
		exit_error(10);		// не забыть очистить массив
}

void	map_name(char	*name)
{
	int	i;

	i = 0;
	while (name[i] != '.')
		i++;
	i++;
	if (name[i] != 'b' && name[i + 1] != 'e'
		&& name[i + 2] != 'r' && name[i + 3] != '\0')
		exit_error(6);
}

void	p_e_c_num(char	*line, t_mlx *mlx)
{
	while (mlx->line[mlx->j])
	{
		if (mlx->line[mlx->j] == 'E')
			mlx->ee++;
		if (mlx->line[mlx->j] == 'P')
			mlx->pp++;
		if (mlx->line[mlx->j] == 'C')
			mlx->cc++;
		mlx->j++;
	}
	mlx->j = 0;
}

void	map_pec_size(t_mlx	*mlx)
{
	if (mlx->ee < 1 || mlx->pp != 1 || mlx->cc < 1)
		exit_error(1);
	if (mlx->len - 1 == mlx->lines)
		exit_error(2);
}


