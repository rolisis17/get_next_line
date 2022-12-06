/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:14:44 by dcella-d          #+#    #+#             */
/*   Updated: 2022/12/06 11:18:44 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	int			posnextline;
	static char	*keep[1024];

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 1024)
		return (NULL);
	if (gnl_check(keep[fd]) == 0)
		keep[fd] = full_line(fd, keep[fd]);
	if (!keep[fd] || keep[fd][0] == '\0')
	{
		free (keep[fd]);
		keep[fd] = NULL;
		return (NULL);
	}
	posnextline = gnl_check(keep[fd]);
	line = makeline(keep[fd], posnextline);
	if (posnextline > 0)
		keep[fd] = ft_strjoin(keep[fd], keep[fd] + posnextline, -1);
	else
	{
		free (keep[fd]);
		keep[fd] = NULL;
	}	
	return (line);
}

char	*makeline(char *keep, int posnextline)
{
	int		f;
	char	*line;

	f = -1;
	if (!keep)
		return (NULL);
	if (posnextline == 0)
		posnextline = ft_strlen(keep);
	line = ft_calloc(posnextline + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (keep[++f] && f < posnextline)
		line[f] = keep[f];
	return (line);
}

char	*full_line(int fd, char *keep)
{
	int		f;
	char	*line;

	f = BUFFER_SIZE;
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (f > 0)
	{
		if (gnl_check(line) > 0)
			break ;
		f = read(fd, line, BUFFER_SIZE);
		if (f < 0)
		{
			if (keep)
				free (keep);
			keep = NULL;
			break ;
		}
		if (f < BUFFER_SIZE && line[0] != '\0')
			line[f] = 0;
		keep = ft_strjoin(keep, line, 0);
	}
	free (line);
	return (keep);
}
