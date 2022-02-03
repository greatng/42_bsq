/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkhead.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:50:59 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/02 10:13:40 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	checkdup(char *head)
{
	int	l;

	l = ft_strlen(head);
	if (head[l - 2] == head[l - 3] || head[l - 2] == head[l - 4])
		return (0);
	if (head[l - 3] == head[l - 4])
		return (0);
	return (1);
}

int	checkhead(char *head, int line)
{
	int		i;
	char	buffer[10];

	i = 0;
	while (i < (ft_strlen(head) - 3))
	{
		if (head[i] < '0' || head[i] > '9')
		{
			maperror();
			return (0);
		}
		buffer[i] = head[i];
		i++;
	}
	buffer[i] = '\0';
	if (line - 1 != ft_atoi(buffer))
	{
		maperror();
		return (0);
	}
	if (!checkdup(head))
		return (0);
	return (1);
}
