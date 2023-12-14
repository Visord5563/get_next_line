/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:20:12 by saharchi          #+#    #+#             */
/*   Updated: 2023/12/14 19:04:01 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	len;
	size_t i;
	size_t j;

	len = ft_strlen(s1, '\0') + ft_strlen(s2, '\0') + 1;
	nstr = (char *)malloc(sizeof(char) * len);
	if(!nstr)
		return(NULL);
	// if (!s1)
	// 	return(ft_strdup(""));
	i = 0;
	j = 0;
	while (s1[j])
		nstr[i++] = s1[j++];
	free ((char *)s1);
	j = 0;
	while (s2[j])
		nstr[i++] = s2[j++];
	nstr[i] = '\0';
	return (nstr);
}

size_t	ft_strlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1, '\0');
	s = (char *)malloc(sizeof(char) * i + 1);
	if (!s)
		return (0);
	j = 0;
	while (j < i)
	{
		s[j] = s1[j];
		j++;
	}
	s[j] = '\0';
	return (s);
}

char *ft_strchr( char *s, int c)
{
    int i;

    i = 0;
	while (s[i])
    {
        if(s[i] == (char)c)
            return (s + i);
        i++;
	}
	return (NULL);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char			*s1;
	size_t			i;
	unsigned char	j;

	i = ft_strlen(s, '\0') - start;
	if (len < i)
		i = len;
	s1 = malloc(sizeof(char) * (i + 1));
	if (!s1)
		return (NULL);
	j = 0;
	while (j < i)
	{
		s1[j] = s[j + start];
		j++;
	}
	s1[j] = '\0';
	return (s1);
}