/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:52:33 by akoutate          #+#    #+#             */
/*   Updated: 2023/12/30 07:59:43 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s, int a)
{
	size_t	i;

	i = 0;
	while (s[i] != a)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		return (ft_strjoin (s2, ""));
	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1, '\0') + ft_strlen(s2, '\0') + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	char			x;

	i = ft_strlen(s, '\0');
	x = (char)c;
	while (i > 0)
	{
		if (s[i] == x)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == x)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s, '\0');
	i = 0;
	if (len > s_len - start)
		len = s_len - start;
	tmp = (char *)malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while ((i < len) && s[start + i])
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
