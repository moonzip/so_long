/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:41:20 by lucmart3          #+#    #+#             */
/*   Updated: 2024/04/23 16:07:32 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;

	if (start > ft_strlen(s))
		return (ft_strdup (""));
	if (len > ft_strlen (s + start))
		len = ft_strlen(s + start);
	a = ft_calloc(len + 1, sizeof(char));
	if (!a)
		return (NULL);
	i = 0;
	while (i < len)
	{
		a[i] = s[start + i];
		i++;
	}
	return (a);
}
