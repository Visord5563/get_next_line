/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:20:06 by saharchi          #+#    #+#             */
/*   Updated: 2023/12/15 00:30:54 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_line(char *s, int j)
{
    char *line;

    if (!s || !s[0])
        return (NULL);
    line = ft_substr(s, 0, j);
    char *s1 = line;
    return(free(line), s1);
}

char *get_r(char **s, int j)
{
    char *s1;

    s1 = ft_substr(*s, j, ft_strlen(*s, '\0') - j);
    free(*s);
    *s = NULL;
    return(s1);
}
#include <limits.h>
char *get_next_line(int fd) {
    static char *string;
    char *buff;
    int i;
    char *line;
    if(fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
        return (NULL);
    buff = (char *)malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);

    i = 1;
    while (i != 0 && !ft_strchr(string, '\n')) 
    {
        i = read(fd, buff, BUFFER_SIZE);
        // if(buff[0] == '\0')
        //     return(NULL);
        if(i == 0)
        {
            // printf("buff===%d", i);
            return(NULL);
        }
        buff[i] = '\0';
        string = ft_strjoin(string, buff);
    }
    free(buff);
    printf("string ==== %s\n", string);
    line = get_line(string, ft_strlen(string, '\n')+ 1);
    string = get_r(&string, ft_strlen(string, '\n') + 1);
    return (line);
}
void ff()
{
    system("leaks a.out");
}
int main()
{
      int fd = open("test.txt",   O_RDWR);
    char *s = get_next_line(fd);
    printf("kk%s", s);
    printf("kk%s", s);
    
        
}


