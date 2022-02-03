/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:11:23 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/02 09:17:45 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	checkmap(char **map, int **ans, int line)
{
	int	i;
	int	error;
	int	size[2];

	i = 0;
	error = 0;
	if (checkhead(map[i], line))
	{
		while (i < line - 2)
		{
			i++;
			if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
				error = 1;
		}
		if (error)
			maperror();
		else
		{
			size[0] = line;
			size[1] = ft_strlen(map[1]);
			calculate(map, ans, map[0], size);
			printresult(map, size);
		}
	}
}

void	map_parsing(char **map, char buffer, int i, int j)
{
	if (buffer == map[0][ft_strlen(map[0]) - 3])
		map[i][j] = '1';
	else if (buffer == map[0][ft_strlen(map[0]) - 2])
		map[i][j] = '0';
}

void	assignmap(char **map, int **ans, char *path)
{
	int		fd;
	int		i;
	int		j;
	char	buffer;

	fd = open(path, O_RDONLY);
	i = 0;
	while (read(fd, &buffer, 1) > 0)
	{	
		if (buffer != '\n' && i == 0)
			map[0][j++] = buffer;
		if (buffer != '\n' && i > 0)
		{
			map_parsing(map, buffer, i, j);
			j++;
		}
		if (buffer == '\n')
		{
			map[i][j] = '\0';
			j = 0;
			i++;
		}
	}
	close(fd);
	checkmap(map, ans, i);
}

void	readmap(char *path, int fd)
{
	int		i;
	int		line;
	int		length;
	char	buffer;

	i = 0;
	line = 0;
	length = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			line++;
		length++;
	}
	if (line < 2)
	{
		maperror();
		return ;
	}
	return (formalloc(line, 2 * (length / line), path));
}
