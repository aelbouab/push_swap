/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:11:48 by aelbouab          #+#    #+#             */
/*   Updated: 2024/02/13 11:40:20 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_len(const char *str, int j)
{
	int	i;

	i = 0;
	if (j == 1)
	{
		while (str[i])
			i++;
		return (i);
	}
	else
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i++;
		return (i);
	}
}

static char	*cleanbuf(char *rst)
{
	int		i;
	int		j;
	char	*buf;

	if (!rst)
		return (NULL);
	j = 0;
	i = 0;
	buf = ft_strdup(rst);
	free (rst);
	rst = NULL;
	i = ft_len(buf, 0);
	rst = ft_substr(buf, i, ft_len(buf, 1));
	free(buf);
	if (*rst == '\0')
		return (free(rst), rst = NULL, NULL);
	return (rst);
}

static char	*redbuf(char *rst, int fd)
{
	char	*buf;
	int		i;

	i = 1;
	while (i > 0)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (free (buf), free(rst), NULL);
		buf[i] = '\0';
		rst = ft_strjoin(rst, buf);
		free (buf);
		buf = NULL;
		if (ft_serch(rst, '\n'))
			break ;
	}
	return (rst);
}

static char	*freeline(char *line, char *rst)
{
	char	*tmp;

	if (!line && rst)
		line = ft_join(line, rst);
	else if (line)
	{
		tmp = ft_strdup(line);
		free (line);
		line = ft_join(tmp, rst);
		free (tmp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rst;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (rst)
	{
		line = ft_join(rst, line);
		if (!line)
			return (free (rst), rst = NULL, NULL);
	}
	if (!ft_serch(rst, '\n'))
	{
		free (rst);
		rst = NULL;
		rst = redbuf(rst, fd);
		if (!rst)
			return (free(line), NULL);
		line = freeline(line, rst);
	}
	rst = cleanbuf(rst);
	if (!line || *line == '\0')
		return (free (line), free(rst), NULL);
	return (line);
}
