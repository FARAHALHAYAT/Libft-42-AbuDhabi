/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <farahoflife@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:57:44 by fasharif          #+#    #+#             */
/*   Updated: 2022/07/23 16:58:53 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_start(char const *s1, char const *set)
{
	int		s;
	int		t;
	int		cnt;

	s = 0;
	while (s1[s] != '\0')
	{
		t = 0;
		cnt = 0;
		while (set[t] != '\0')
		{
			if (s1[s] != set[t])
				cnt++;
			t++;
		}
		if (cnt == t)
			return (s);
		s++;
	}
	return (-1);
}

static int	ft_check_end(char const *s1, char const *set)
{
	int		t;
	int		e;
	int		cnt;

	e = (int)ft_strlen(s1) - 1;
	while (e >= 0)
	{
		t = 0;
		cnt = 0;
		while (set[t] != '\0')
		{
			if (s1[e] != set[t])
				cnt++;
			t++;
		}
		if (cnt == t)
			return (e);
		e--;
	}
	return (-1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		s;
	int		e;
	int		t;
	char	*ret;

	t = 0;
	s = ft_check_start(s1, set);
	e = ft_check_end(s1, set);
	if (s == -1)
	{
		ret = (char*)malloc(sizeof(char));
		ret[0] = 0;
		return (ret);
	}
	ret = (char *)malloc(sizeof(char) * (e - s + 2));
	if (ret == 0)
		return (NULL);
	while (t <= e - s)
	{
		ret[t] = s1[s + t];
		t++;
	}
	ret[t] = '\0';
	return (ret);
}
			NEW
			
			
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	char		*tab;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	tab = ft_substr((char *)s1, 0, len + 1);
	return (tab);
}
