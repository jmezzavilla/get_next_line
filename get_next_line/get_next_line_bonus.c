/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmezzavilla <jmezzavilla@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:29:33 by jmezzavilla       #+#    #+#             */
/*   Updated: 2023/05/12 23:35:56 by jmezzavilla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	line = ft_strjoin(0, buffer[fd]);
	if (ft_check_newline(buffer[fd]))
		return (line);
	bytes = read(fd, buffer[fd], BUFFER_SIZE);
	if (bytes < 0)
	{
		free(line);
		return (NULL);
	}
	while (bytes)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (ft_check_newline(buffer[fd]))
			break ;
		bytes = read(fd, buffer[fd], BUFFER_SIZE);
	}
	return (line);
}

/*int	main(void)
{
	int fd;
	char		*line;
	fd = open("teste.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
}*/