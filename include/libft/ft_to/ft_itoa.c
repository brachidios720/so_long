/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:35:43 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/11/09 19:36:25 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_len(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	long int		len;
	char			*alpha;

	len = ft_len(n);
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	alpha = malloc(sizeof(char) * len + 1);
	if (!alpha)
		return (NULL);
	if (n == 0)
		alpha[0] = '0';
	alpha[len] = '\0';
	len--;
	while (nbr)
	{
		alpha[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		alpha[0] = '-';
	return (alpha);
}
