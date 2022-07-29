/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:28:06 by fasharif          #+#    #+#             */
/*   Updated: 2022/07/23 18:55:58 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	
		if (!s || !f)
			return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, s + i);
		i++;
	}
}
