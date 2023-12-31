/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:34:59 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/11/09 19:36:33 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *str, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*a;

	i = 0;
	a = (char *)str;
	n_len = 0;
	while (ndl[n_len])
		n_len++;
	if (n_len == 0 || str == ndl)
		return (a);
	while (a[i] != '\0' && i < len)
	{
		j = 0;
		while (a[i + j] != '\0' && ndl[j] != '\0' && a[i + j] == ndl[j] && i
			+ j < len)
			j++;
		if (j == n_len)
			return (a + i);
		i++;
	}
	return (0);
}
