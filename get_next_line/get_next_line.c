/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmezzavilla <jmezzavilla@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:49:38 by jmezzavilla       #+#    #+#             */
/*   Updated: 2023/05/12 23:36:28 by jmezzavilla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin(0, buffer);
	if (ft_check_newline(buffer))
		return (line);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0)
	{
		free(line);
		return (NULL);
	}
	while (bytes)
	{
		line = ft_strjoin(line, buffer);
		if (ft_check_newline(buffer))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
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