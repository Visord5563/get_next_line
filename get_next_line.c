/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:20:06 by saharchi          #+#    #+#             */
/*   Updated: 2023/12/16 23:53:51 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *get_r(char **s, int j)
{
    char *s1;
     
    s1 = ft_substr(*s, j, ft_strlen(*s) - j);
    free(*s);
    *s = NULL;
    return(s1);
}
char *get_newline(char **s, int j)
{
    char *line;
    line = ft_substr(*s, 0, j);
    *s = get_r(s, j);
    return(line);
}

char *get_next_line(int fd) 
{
    static char *string;
    char *buff;
    int i;
    
    if(fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
        return (NULL);
    buff = malloc((size_t)BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    if (!string)
		string = ft_strdup("");
    i = read(fd, buff, BUFFER_SIZE);
    while(i >= 0)
    {
        buff[i] = '\0';
        string = ft_strjoin(string, buff);
        if(string[0] == '\0')
            break;
        if (ft_strchr(string) != -1)
            return(free(buff), get_newline(&string, ft_strchr(string)));
        if(i == 0)
            return(free(buff), get_r(&string, 0));
        i = read(fd, buff, BUFFER_SIZE);
    } 
    return (free(buff),free(string), string = NULL, NULL);
}
// void ff()
// {
//     system("leaks a.out");
// }
int main()
{
     int fd = open("test.txt",   O_RDWR);

    char *s;
    while((s = get_next_line(fd))){
        printf("%s", s);
    }
}

        