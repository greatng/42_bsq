/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:34:45 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/01 19:25:29 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate.h"

char	**calculate(char **map, int **ans, char *head, int *size)
{
	int	i;
	int	j;
	int	min;

	init_ans(map, ans, size);
	i = 2;
	j = 1;
	min = 0;
	while (i < size[0])
	{
		while (j < size[1])
		{
			if (map[i][j] == '0')
				min = 0;
			else
				min = find_min(ans, i, j);
			ans[i][j] = min;
			j++;
		}
		j = 1;
		i++;
	}
	remap(map, ans, head, size);
	return (map);
}

char	**remap(char **map, int **ans, char *head, int *size)
{
	int			i;
	int			j;
	t_solution	solution;
	int			pos[2];

	i = 1;
	j = 0;
	solution = find_largest(ans, size);
	while (i < size[0])
	{
		while (j < size[1])
		{
			pos[0] = i;
			pos[1] = j;
			map[i][j] = map_symbol(map, head, pos, solution);
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

char	map_symbol(char **map, char *head, int *pos, t_solution rect)
{
	if (pos[0] <= rect.y && pos[0] > (rect.y - rect.size))
		if (pos[1] <= rect.x && pos[1] > (rect.x - rect.size))
			return (head[ft_strlen(head) - 1]);
	if (map[pos[0]][pos[1]] == '0')
		return (head[ft_strlen(head) - 2]);
	else
		return (head[ft_strlen(head) - 3]);
	return (0);
}

t_solution	find_largest(int **ans, int *size)
{
	int			i;
	int			j;
	t_solution	solution;

	i = 1;
	j = 0;
	solution.size = 0;
	while (i < size[0])
	{
		while (j < size[1])
		{
			if (ans[i][j] > solution.size)
			{
				solution.size = ans[i][j];
				solution.x = j;
				solution.y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (solution);
}
