/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:27:19 by fasharif          #+#    #+#             */
/*   Updated: 2022/07/29 17:55:34 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
	}
	else if (dp > sp)
	{
		while (len--)
		{
			dp[len] = sp[len];
		}
	}
	return (dst);
}
