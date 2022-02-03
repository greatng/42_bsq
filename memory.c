/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:54:35 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/02 08:31:02 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

void	setfree(char **map, int **ans, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		free(map[i]);
		free(ans[i]);
		i++;
	}
	free(map);
	free(ans);
}

void	formalloc(int line, int length, char *path)
{
	int		i;
	char	**map;
	int		**ans;

	map = (char **)malloc(sizeof(char *) * line);
	ans = (int **)malloc(sizeof(int *) * line);
	i = 0;
	if (map == NULL || ans == NULL)
	{
		free(map);
		free(ans);
		return ;
	}
	while (i < line)
	{
		map[i] = (char *)malloc(sizeof(char) * length);
		ans[i] = (int *)malloc(sizeof(int) * length);
		i++;
	}
	assignmap(map, ans, path);
	setfree(map, ans, line);
}
