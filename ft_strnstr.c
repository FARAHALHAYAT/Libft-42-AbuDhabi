/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:34:17 by fasharif          #+#    #+#             */
/*   Updated: 2022/07/26 17:11:06 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *heystack, const char *needle, size_t len)
{
	size_t	l;

	if (*needle == '\0')
		return ((char *)heystack);
	l = ft_strlen(needle);
	while (*heystack && len-- >= l)
	{
		if (*heystack == *needle && ft_strncmp(heystack, needle, l) == 0)
			return ((char *)heystack);
		heystack++;
	}
	return (0);
}
