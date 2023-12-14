/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:20:06 by saharchi          #+#    #+#             */
/*   Updated: 2023/12/14 19:24:37 by saharchi         ###   ########.fr       */
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

    // printf("s=    %s/", s);
    s1 = ft_substr(s, j, ft_strlen(s, '\0') - j);
    free(s);
    s = NULL;
    // printf("s1=    %s/", s1);
    return(s1);
}

char *get_next_line(int fd) {
    static char *string;
    char *buff;
    int i;
    char *line;

    buff = (char *)malloc(BUFFER_SIZE + 1);
    if (!string)
        string = ft_strdup("");

    i = 1;
    while (i != 0 && !ft_strchr(string, '\n')) {
        i = read(fd, buff, BUFFER_SIZE);
        buff[i] = '\0';
        if(i == -1)
            return(NULL);
        string = ft_strjoin(string, buff);
    }
    free(buff);
    line = get_line(string, ft_strlen(string, '\0'));
    string = get_r(string, ft_strlen(string, '\0'));
    return (line);
}

int main()
{
    int fd = open("test.txt",   O_RDWR);
    char *s;
        int i = 0;
        while (i <10)
        {
            s = get_next_line(fd);
            printf("%s", s);
            free(s);
            i++;
        }
}