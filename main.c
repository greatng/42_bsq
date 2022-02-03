/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:41:27 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/02 09:18:14 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

void	open_close_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		maperror();
	else
	{
		readmap(path, fd);
		close(fd);
	}
}

int	main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
	{
		open_close_file(read_input());
	}
	else
	{
		while (i < argc)
		{
			open_close_file(argv[i]);
			i++;
			if (argc > 2 && i < argc)
				write(1, "\n", 1);
		}
	}
}
