/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:28:59 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/02 08:06:47 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

int		ft_atoi(char *str);
//utility1
int		ft_strlen(char *str);
void	maperror(void);
//mapper
void	assignmap(char **map, int **ans, char *path);
//memory
void	setfree(char **map, int **ans, int line);
void	formalloc(int line, int length, char *path);
//checkvalid
void	readmap(char *path, int fd);
int		checkhead(char *head, int line);
//calculate
char	**calculate(char **map, int **ans, char *head, int *size);
//printresult
void	printresult(char **map, int *size);
//read_input
char	*read_input(void);
int		temp_map(char *file_path);
#endif
