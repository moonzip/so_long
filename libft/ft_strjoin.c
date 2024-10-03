/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:24:14 by lucmart3          #+#    #+#             */
/*   Updated: 2024/04/22 12:34:25 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*a;

	i = 0;
	j = 0;
	k = 0;
	a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!a)
		return (NULL);
	while (s1[i] != '\0')
	{
		a[k] = s1[i];
		i++;
		k++;
	}
	while (s2[j] != '\0')
	{
		a[k] = s2[j];
		j++;
		k++;
	}
	a[k] = '\0';
	return (a);
}
