/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:21:52 by fasharif          #+#    #+#             */
/*   Updated: 2022/08/04 18:29:13 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if(!s)
		return (NULL);
	while (*s != '\0' && (unsigned cha r)c != *s)
		s++;
	if ((unsigned char)c == *s)
		return ((char *)s);
	return (NULL);
}
