/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:48:50 by fasharif          #+#    #+#             */
/*   Updated: 2022/08/04 14:44:15 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	c;
	int	s;
	int	res;

	c = 0;
	s = 1;
	res = 0;
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' ')
		c++;
	while (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			s *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		if (res > 20 && s == 1)
			return (0);
		if (res > 20 && s == -1)
			return (-1);
		res = (str[c] - '0') + (res * 10);
		c++;
	}
	return (res * s);
}

#include <limits.h>

int	check_overflow(unsigned long long num, int minus)
{
	if (num > LLONG_MAX - 1 && minus == -1)
		return (0);
	if (num > LLONG_MAX && minus == 1)
		return (-1);
	return (num * minus);
}

int	ft_atoi(const char *str)
{
	int					minus;
	int					i;
	unsigned long long	data;

	i = 0;
	minus = 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	data = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{	
		data *= 10;
		data += str[i] - '0';
		i++;
	}
	return ((int)check_overflow(data, minus));
}



#include "libft.h"

int ft_atoi(const char *str)
{
    int     minus;
    long    res;

		minus = 1;
    res = 0;
    while ((9 <= *str && *str <= 13) || *str == ' ')
			++str;
    if (*str == '+' || *str == '-')
			if (*str++ == '-')
				minus *= -1;
    while ('0' <= *str && *str <= '9')
    {
			res = res * 10 + (*str++ - '0');
			if (res < 0)
				return ((minus + 1) / -2);
    }
    return (res * minus);
}



#include"libft.h"

const char	*skip_whitespace(const char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

int	ft_atoi(const char	*str)
{
	long	n;
	long	sign;

	n = 0;
	sign = 1;
	str = skip_whitespace(str);
	if (*str == '-')
		sign = -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while ((*str != '\0') && ('0' <= *str) && (*str <= '9'))
	{
		n = (n * 10) + (*str - '0');
		if (n > 2147483647 && sign == 1)
			return (-1);
		if (n > 2147483648 && sign == -1)
			return (0);
		str++;
	}
	return (n * sign);
}
