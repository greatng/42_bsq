/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:42:06 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/01 14:21:52 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate.h"

int	find_min(int **ans, int y, int x)
{
	int	out;

	out = 0;
	if (ans[y][x - 1] < ans[y - 1][x])
		out = ans[y][x - 1];
	else
		out = ans[y - 1][x];
	if (ans[y - 1][x - 1] < out)
		out = ans[y - 1][x - 1];
	out = out + 1;
	return (out);
}

int	init_ans(char **map, int **ans, int *size)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < size[0])
	{
		ans[i][0] = (map[i][0] - '0');
		i++;
	}
	while (j < size[1])
	{
		ans[1][j] = (map[1][j] - '0');
		j++;
	}
	return (1);
}
