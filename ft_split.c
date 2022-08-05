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

static int			ft_cntwrd(char const *s, char c)
{
	unsigned int	i;
	int				cntr;

	i = 0;
	cntr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cntr++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (cntr);
}

static char			*ft_strndup(const char *s, size_t n)
{
	char			*str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

char	**ft_strsplit(char const *s, char c)
{
	int				i;
	int				j;
	int				k;
	char			**tab;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_cntwrd(s, c)) + 1);
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tab[k] = ft_strndup(s + j, i - j);
			k++;
		}
		
	}
	tab[k] = NULL;
	return (tab);
}

				NEW should works
#include "libft.h"

static char	**ft_malloc_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_nb_words(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;

	if (!s[0])
		return (0);
	i = 0;
	nb_words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_words++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_words++;
	return (nb_words);
}

static void	ft_get_next_word(char **next_word, size_t *next_word_len, char c)
{
	size_t	i;

	*next_word += *next_word_len;
	*next_word_len = 0;
	i = 0;
	while (**next_word && **next_word == c)
		(*next_word)++;
	while ((*next_word)[i])
	{
		if ((*next_word)[i] == c)
			return ;
		(*next_word_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*next_word;
	size_t	next_word_len;
	size_t	i;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_nb_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	next_word = (char *)s;
	next_word_len = 0;
	while (i < ft_nb_words(s, c))
	{
		ft_get_next_word(&next_word, &next_word_len, c);
		tab[i] = (char *)malloc(sizeof(char) * (next_word_len + 1));
		if (!tab[i])
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i], next_word, next_word_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

			a onther one;
static int	ft_countword(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			cnt++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (cnt);
}

static char	*ft_makewrds(char *word, char const *s, int x, int leng_wd)
{
	int		i;

	i = 0;
	while (leng_wd > 0)
		word[i++] = s[x - leng_wd--];
	word[i] = '\0';
	return (word);
}

static char	**ft_wrdsplit(char **result, char const *s, char c, int wordcnt)
{
	int		i;
	int		x;
	int		leng_wd;

	i = 0;
	x = 0;
	leng_wd = 0;
	while (s[x] != '\0' && i < wordcnt)
	{
		while (s[x] != '\0' && s[x] == c)
			x++;
		while (s[x] && s[x] != c)
		{
			x++;
			leng_wd++;
		}
		result[i] = (char *)malloc(sizeof(char) * (leng_wd + 1));
		if (!result[i])
			return (NULL);
		ft_makewrds(result[i], s, x, leng_wd);
		leng_wd = 0;
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		wordcnt;
	char	**result;

	if (s == 0)
		return (NULL);
	wordcnt = ft_countword(s, c);
	result = (char **)malloc(sizeof(char *) * (wordcnt + 1));
	if (!result)
		return (NULL);
	ft_wrdsplit(result, s, c, wordcnt);
	return (result);
}
