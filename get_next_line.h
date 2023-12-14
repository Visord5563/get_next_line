/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:20:01 by saharchi          #+#    #+#             */
/*   Updated: 2023/12/15 00:18:50 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define   GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 145
#endif
char    *get_next_line(int fd);
char    *ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strlcat(char *dst, const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char *ft_strchr( char *s, int c);
char	*ft_substr(char *s,int start, size_t len);

#endif