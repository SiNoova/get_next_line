/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:52:29 by akoutate          #+#    #+#             */
/*   Updated: 2023/12/30 08:02:41 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_str(char *line, char **str)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp1;

	i = ft_strlen(line, '\n');
	j = ft_strlen(line, '\0');
	tmp = line;
	line = ft_substr(line, 0, i + 1);
	tmp1 = *str;
	*str = ft_substr(tmp, i + 1, j - i - 1);
	if (!*str[0])
	{
		free(*str);
		*str = NULL;
	}
	free (tmp);
	free (tmp1);
	return (line);
}

char	*fill_line(int fd, char *buffer, char *line, char **str)
{
	int		x;
	char	*tmp;

	while (1)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (!x)
		{
			if (line)
				return (tmp = line, line = NULL, tmp);
			return (NULL);
		}
		buffer[x] = '\0';
		tmp = line;
		line = ft_strjoin(line, buffer);
		free (tmp);
		if (ft_strrchr(line, '\n'))
		{
			line = fill_str(line, str);
			break ;
		}
	}
	return (line);
}

char	*str_free(int fd, char **str, char *buffer)
{
	char	*line;

	line = ft_strjoin (*str, "");
	if (ft_strrchr(line, '\n'))
		return (fill_str(line, str));
	free (*str);
	*str = NULL;
	return (fill_line(fd, buffer, line, str));
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			x;

	line = NULL;
	x = read(fd, buffer, 0);
	if (x == -1)
	{
		free (str);
		str = NULL;
		return (NULL);
	}
	if (fd >= 0)
	{
		if (str)
			line = str_free(fd, &str, buffer);
		else
			line = fill_line(fd, buffer, line, &str);
	}
	return (line);
}
