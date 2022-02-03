/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:59:57 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/01 13:55:24 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATE_H
# define CALCULATE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_solution {
	int	x;
	int	y;
	int	size;
}	t_solution;

char		**calculate(char **map, int **ans, char *head, int *size);
char		**remap(char **map, int **ans, char *head, int *size);
char		map_symbol(char **map, char *head, int *pos, t_solution rect);
t_solution	find_largest(int **ans, int *size);
int			find_min(int **ans, int y, int x);
int			init_ans(char **map, int **ans, int *size);
int			ft_strlen(char *str);

#endif
