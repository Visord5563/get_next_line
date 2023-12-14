/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:20:06 by saharchi          #+#    #+#             */
/*   Updated: 2023/12/14 22:51:27 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_line(char *s, int j)
{
    char *line;

    if (!s || !s[0])
        return (NULL);
    line = ft_substr(s, 0, j);
    return(line);
}

char *get_r(char *s, int j)
{
    char *s1;

    s1 = ft_substr(s, j, ft_strlen(s) - j);
    free(s);
    s = NULL;
    return(s1);
}

char *get_next_line(int fd) {
    static char *string;
    char *buff;
    int i;
    char *line;

    buff = (char *)malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    if(fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
        return (NULL);
    i = 1;
    while (i != 0 && !ft_strchr(string, '\n')) {
        i = read(fd, buff, BUFFER_SIZE);
        buff[i] = '\0';
        if(i == -1)
            return(NULL);
        string = ft_strjoin(string, buff);
    }
    free(buff);
    line = get_line(string, ft_strchr(string, '\n'));
    string = get_r(string, ft_strchr(string, '\n'));
    return (line);
}
// void ff()
// {
//     system("leaks a.out");
// }

int main()
{
    int fd = open("get_next_line_utils.c",   O_RDWR);
    char *s;
        int i = 0;
        while ((s = get_next_line(fd)))
        {
            // s = get_next_line(fd);
            printf("%s", s);
            free(s);
            // i++;
        }
   // atexit(ff);
}