/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:20:06 by saharchi          #+#    #+#             */
/*   Updated: 2023/12/13 21:22:05 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_line(char *s, int j)
{
    char *line;

    line = ft_substr(s, 0, j);
    return(line);
}

char *get_r(char **s, int j)
{
    char *s1;

    s1 = ft_substr(*s, j, ft_strlen(*s) - j);
    free(*s);
    *s = NULL;
    return(s1);
}

// char *awdii(char *s, int fd)
// {
//     int i;
//     char *buff;
//     char *line;

//     buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
//     if(!buff)
//         return(NULL);
//     if (!s)
//         s = (ft_strdup(""));
//     i = read(fd, buff, BUFFER_SIZE);
//     while(i >= 0)
//     {
//         buff[i] = '\0';
//         s = ft_strjoin(s, buff);
//         if( ft_strchr(buff, '\n'))
//         {
//             line = get_line(s);
//             s = get_r(s);
//             return(free(buff), line);
//         }
//         if(i == 0)
//             return(free(buff), s);
//         i = read(fd, buff, BUFFER_SIZE);
//     }
//     free(buff);
//     return(NULL);
// }
char *get_next_line(int fd)
{
    static char *string;
    int i;
    int j;
    char *buff;
    char *line;

    buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if(!buff)
        return(NULL);
    if (!string)
        string = (ft_strdup(""));
    i = read(fd, buff, BUFFER_SIZE);
    while(i >= 0)
    {
        buff[i] = '\0';
        string = ft_strjoin(string, buff);
        j = ft_strchr(string, '\n');
        if(j >= 0)
        {
            line = get_line(string, j);
            string = get_r(&string, j);
            return(free(buff), line);
        }
        if(i == 0)
        {
            puts("wlad l9hab");
            return(free(buff), string);
        }
        i = read(fd, buff, BUFFER_SIZE);
    }
    
    // string = awdii(string, fd);
    return(NULL);
}

int main()
{
       int fd = open("test",   O_RDWR);
    // char *s;
    // while((s = get_next_line(fd)))
    // {
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        // free(s);
    // }
}