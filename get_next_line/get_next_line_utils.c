/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmezzavilla <jmezzavilla@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:58:39 by jmezzavilla       #+#    #+#             */
/*   Updated: 2023/05/12 23:36:22 by jmezzavilla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	return (++i);
}

void	ft_strcpy(char *dest, char *src)
{
	size_t	count;

	count = 0;
	while (src && src[count])
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
}

void	ft_strcat(char *dest, char *src)
{
	size_t	dest_count;
	size_t	src_count;

	dest_count = ft_strlen(dest) - 1;
	src_count = 0;
	while (src && src[src_count] != '\n' && src[src_count])
		dest[dest_count++] = src[src_count++];
	if (src[src_count] == '\n')
		dest[dest_count++] = '\n';
	dest[dest_count] = '\0';
}

char	*ft_strjoin(char *dest, char *src)
{
	char	*str;

	if (!src[0])
		return (0);
	str = (char *)malloc((ft_strlen(dest) + ft_strlen(src) + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, dest);
	ft_strcat(str, src);
	free(dest);
	return (str);
}

int	ft_check_newline(char *s)
{
	size_t	i;
	size_t	j;
	int		isnl;

	i = 0;
	j = 0;
	isnl = 0;
	while (s[i])
	{
		if (isnl)
			s[j++] = s[i];
		if (s[i] == '\n')
			isnl = 1;
		s[i++] = '\0';
	}
	return (isnl);
}
