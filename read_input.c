/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 05:55:01 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/03 11:27:59 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

char	*read_input(void)
{
	int		bytes_read;
	char	buffer;
	int		fd;
	char	*file_path;
	char	last_char;

	bytes_read = 1;
	file_path = "temp.map";
	fd = (temp_map(file_path));
	if (fd == 0)
		return (NULL);
	while (bytes_read > 0)
	{
		last_char = buffer;
		bytes_read = read(0, &buffer, 1);
		write(fd, &buffer, bytes_read);
	}
	write(fd, "\0", 1);
	close(fd);
	return (file_path);
}

int	temp_map(char *file_path)
{
	int	fd;

	fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 2)
		return (0);
	return (fd);
}
