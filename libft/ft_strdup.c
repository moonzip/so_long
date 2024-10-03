/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:03:41 by lucmart3          #+#    #+#             */
/*   Updated: 2024/04/18 18:42:03 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*p;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	str = malloc (i + 1);
	if (!str)
		return (NULL);
	p = str;
	while (*s1 != '\0')
		*p++ = *s1++;
	*p = '\0';
	return (str);
}
