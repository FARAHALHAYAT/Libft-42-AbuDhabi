int		ft_countsize(long int n);
void	ft_convbase(long int n, char *number, long int i);

char	*ft_itoa(int n)
{
	char		*number;
	long int	len;

	len = ft_countsize(n);
	number = (char *)malloc((len + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[len--] = '\0';
	ft_convbase(n, number, len);
	return (number);
}

// recursively count integer size
int	ft_countsize(long int n)
{
	if (n < 0)
		return (1 + ft_countsize(-n));
	if ((n / 10) == 0)
		return (1);
	else
		return (1 + ft_countsize(n / 10));
}

// recursively convert integer to string
void	ft_convbase(long int n, char *number, long int i)
{
	if (n < 0)
	{
		number[0] = '-';
		n *= -1;
	}
	if (n >= 10)
		ft_convbase((n / 10), number, (i - 1));
	number[i] = (n % 10) + '0';
}/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:19:25 by fasharif          #+#    #+#             */
/*   Updated: 2022/07/26 17:47:29 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countsize(long int n);
void	ft_convbase(long int n, char *number, long int i);

char	*ft_itoa(int n)
{
	char		*number;
	long int	len;

	len = ft_countsize(n);
	number = (char *)malloc((len + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[len--] = '\0';
	ft_convbase(n, number, len);
	return (number);
}

// recursively count integer size
int	ft_countsize(long int n)
{
	if (n < 0)
		return (1 + ft_countsize(-n));
	if ((n / 10) == 0)
		return (1);
	else
		return (1 + ft_countsize(n / 10));
}

// recursively convert integer to string
void	ft_convbase(long int n, char *number, long int i)
{
	if (n < 0)
	{
		number[0] = '-';
		n *= -1;
	}
	if (n >= 10)
		ft_convbase((n / 10), number, (i - 1));
	number[i] = (n % 10) + '0';
}

		NEW
static char	spe_putnbr(int nb)
{
	unsigned int	number;
	number = nb;
	if (number == 0)
		return (0 + '0');
	if (number > 0)
	{
		spe_putnbr(number / 10);
		number %= 10;
	}
	return (number + '0');
}
static int	is_neg(int nb)
{
	if (nb < 0)
		return (1);
	return (0);
}
static size_t	get_len(int n)
{
	size_t			len;
	unsigned int	number;
	len = 0;
	if (is_neg(n))
	{
		number = (unsigned int)-n;
		len++;
	}
	else
		number = (unsigned int)n;
	while (number > 9)
	{
		number /= 10;
		len++;
	}
	len++;
	return (len);
}
char	*ft_itoa(int n)
{
	char			*result;
	size_t			len;
	unsigned int	num;
	int				i;
	len = get_len(n);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	if (is_neg(n))
		num = (unsigned int)-n;
	else
		num = (unsigned int)n;
	while (i++ <= (int)len - 1)
	{
		result[(int)len - i] = spe_putnbr(num);
		num /= 10;
	}
	if (is_neg(n))
		result[0] = '-';
	result[len] = '\0';
	return (result);
}
