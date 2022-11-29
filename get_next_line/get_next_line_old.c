/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:25:40 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/29 12:21:32 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	**tot;
	int		f;
	int		u;
	int		ffd;
	static char	*keep;
	
	f = -1;
	ffd = 0;
	u = -1;
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (gnl_check(keep) != 1)
	{
		ffd = read(fd, line, BUFFER_SIZE);
		if (ffd < 0)
		{
			free (line);
			return (0);
		}
		if (!keep)
			return (0);
	}
	tot = ft_split(keep, '\n');
	f = -1;
	keep = 0;
	while (tot[1][++f])
		keep[f] = tot[1][f];
	return (line);
}

int	gnl_check(char *line)
{
	int	f;
	
	f = -1;
	while (line[++f])
	{
		if (line[f] == '\n')
			return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		;
	return (i);
}

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
}