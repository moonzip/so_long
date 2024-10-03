/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:19:58 by lucmart3          #+#    #+#             */
/*   Updated: 2024/04/26 18:52:51 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s;
	int		f;
	char	*result;

	s = 0;
	f = ft_strlen(s1);
	while (ft_strchr(set, s1[s]) != NULL && s < f && s1[s] != '\0')
		s++;
	while (f >= s && ft_strchr(set, s1[f]) != NULL)
		f--;
	f++;
	result = (char *)malloc(sizeof(char) * (f - s + 1));
	if (!result)
		return (NULL);
	ft_strlcpy (result, &s1[s], f - s + 1);
	return (result);
}
