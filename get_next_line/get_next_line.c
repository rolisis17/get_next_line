/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:23:38 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/29 17:03:45 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		f;
	int		countkeep;
	int		posnextline;
	static char	*keep;
	
	f = -1;
	line = full_line(fd, keep);
	posnextline = gnl_check(line);
	countkeep = ft_strlen(line + posnextline);
	keep = ft_calloc(countkeep + 1, sizeof(char));
	if (countkeep > 0)
	{
		while (line[posnextline + f] && ++f < countkeep)
			keep[f] = line[posnextline + f];
	}
	while (line[posnextline])
		line[posnextline++] = 0;
	return (line);
}

char	*full_line(int fd, char *keep)
{
	int	f;
	char	*line;
	
	f = 0;
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (gnl_check(keep) < 1)
	{
		f = read(fd, line, BUFFER_SIZE);
		if (f < 0)
		{
			free (line);
			return (NULL);
		}
		keep = ft_strjoin(keep, line);
		if (!keep)
			return (NULL);
	}
	free (line);
	return (keep);
}

int	gnl_check(char *line)
{
	int	f;
	
	f = -1;
	if (!line)
		return (0);
	while (line[++f])
		if (line[f] == '\n')
			return (f + 1);
	return (0);
}

/* 
#include <fcntl.h>

int	main(void)
{
	char *str;
	char *str2;
	char *str3;
	char *str4;
	char *str5;
	int fd = open("fuc.txt", O_RDONLY);
	str = get_next_line(fd);
	str2 = get_next_line(fd);
	str3 = get_next_line(fd);
	str4 = get_next_line(fd);
	str5 = get_next_line(fd);
	printf("This is your ass: %s$\n", str);
	printf("This is your ass: %s$\n", str2);
	printf("This is your ass: %s$\n", str3);
	printf("This is your ass: %s$\n", str4);
	printf("This is your ass: %s$\n", str5);
	return (0);
} */