/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:20:06 by saharchi          #+#    #+#             */
/*   Updated: 2023/12/15 22:39:02 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int check_nl1(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '\0')
            return (1);
        i++;
    }
    return (0);
}
char *get_r(char **s, int j)
{
    char *s1;
     
    s1 = ft_substr(*s, j, ft_strlen(*s) - j);
    free(*s);
    *s = NULL;
    return(s1);
}
char *get_line(char **s, int j)
{
    char *line;
    line = ft_substr(*s, 0, j);
    *s = get_r(s, j);
    return(line);
}

#include <limits.h>
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
    i = 1;
    while(i != 0)
    {
        i = read(fd, buff, BUFFER_SIZE);
        buff[i] = '\0';
        string = ft_strjoin(string, buff);
        if(string[0] == '\0')
            break;
        if (ft_strchr(string) != -1)
            return(free(buff), get_line(&string, ft_strchr(string)));
        if(i == 0)
            return(free(buff), get_r(&string, check_nl1(string)));
    } 
    return (free(buff),free(string), string = NULL,NULL);
}
// void ff()
// {
//     system("leaks a.out");
// }
// int main()
// {
//      int fd = open("test.txt",   O_RDWR);
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
// }

        