/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:17:37 by fasharif          #+#    #+#             */
/*   Updated: 2022/08/03 14:20:45 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_words(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
		{
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
			n++;
		}
	}
	return (n);
}

int	word_len(char *str, int i)
{
	int	c;
	
	c = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	{
		i++;
		c++;
	}
	return (c);
}

char	**ft_split(char const *str)
{
	char	**sp;
	int	i;
	int	j;
	int	k;
	
	sp = (char **)malloc((num_words(str) + 1) * sizeof(char *));
	if (!sp)
		return(NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		k = 0;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
		{
			sp[j] = (char *)malloc((word_len(str, i) + 1) * sizeof(char));
			if (!sp[j])
				return (NULL);
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			{
				sp[j][k] = str[i];
				i++;
				k++;
			}
			sp[j][k] = '\0';
			j++;
		}
	}
	sp[j] = '\0';
	return (sp);
}

int	main()
{
	char	**sp;
	int	i;
	
	sp = ft_split("     Farah   Is   the     best   ???        ");
	i = 0;
	while (i < 5)
	{
		printf ("sp[%d] = %s\n", i, sp[i]);
		i++;
	}
	return (0);
}
	

				NEW;

/*
** LIBRARY: N/A
** SYNOPSIS: split string, with specified character as delimiter, into an array
**			of strings
**
** DESCRIPTION:
** 		Allocates (with malloc(3)) and returns an array of strings obtained by
**	splitting ’s’ using the character ’c’ as a delimiter. The array must be
**	ended by a NULL pointer.
*/

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int i;
	int trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}
