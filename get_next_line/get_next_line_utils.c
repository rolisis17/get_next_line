/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:25:37 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/29 16:59:07 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*nmembp;

	nmembp = (void *) malloc(nmemb * size);
	if (!nmembp)
		return (NULL);
	ft_bzero(nmembp, nmemb * size);
	return (nmembp);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	f;

	f = 0;
	while (f < n)
	{
		((unsigned char *)s)[f] = 0;
		f++;
	}
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

/* char	**ft_split(char *s, char c)
{
	size_t	f;
	size_t	len;
	char	**tot;

	f = -1;
	len = 0;
	if (!s)
		return (NULL);
	tot = ft_calloc (3, sizeof(char *));
	if (!tot)
		return (NULL);
	while ((s[len] != c) && (s[len]))
		len++;
	tot[0] = ft_calloc(len + 2, sizeof(char));
	if (!tot[0])
		return NULL;
	while (s[++f] && s[f] != c)
		tot[0][f] = s[f];
	tot[1] = ft_calloc(ft_strlen(s) - len + 1, sizeof(char));
	while (s[f++])
		tot[1][f] = s[f];
	free (s);
	return (tot);
} */

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	f;
	size_t	u;
	size_t	c;
	char	*s3;

	f = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = (char *)ft_calloc(f, sizeof(char));
	if (!s3)
		return (NULL);
	c = -1;
	if (s1)
		while (s1[++c] && (c < f - 1))
			s3[c] = s1[c];
	else
		c = 0;
	u = -1;
	if (s2)
		while ((s2[++u]) && (u < c - ft_strlen(s3) - 1))
			s3[c + u] = s2[u];
	free (s1);
	return (s3);
}
