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

char	**ft_split(char const *s, char c)
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
	
