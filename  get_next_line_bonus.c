/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:04:32 by saharchi          #+#    #+#             */
/*   Updated: 2023/12/16 23:54:57 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *get_r(char **s, int j)
{
	char *s1;

	s1 = ft_substr(*s, j, ft_strlen(*s) - j);
	free(*s);
	*s = NULL;
	return (s1);
}

char *get_newline(char **s, int j)
{
	char *line;
	char *s;

	line = ft_substr(*s, 0, ft_strlen(*s) - j);
	*s = get_r(s, j);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*string[OPEN_MAX];
	char		*buff;
	int			i;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc((size_t)BUFFER_SIZE + 1);
	if(!buff)
		return (NULL);
	if (!string[fd])
		string[fd] = ft_strdup("");
	i = read(fd, buff, BUFFER_SIZE);
	while (i >= 0)
	{
		buff[i] = '\0';
		string[fd] = ft_strjoin(string[fd], buff);
		if(string[fd][0] == '\0')
			break ;
		if(ft_strchr(string[fd]) != -1)
			return(free(buff), get_newline(&string[fd], ft_strchr(string[fd])));
		if(i == 0)
			return(free(buff), get_r(&string[fd], 0));
		i = read(fd, buff, BUFFER_SIZE);
	}
	return(free(buff), free(string[fd]), string[fd] = NULL, NULL);
}
