/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:05:30 by lucmart3          #+#    #+#             */
/*   Updated: 2024/07/17 16:17:22 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numhex(unsigned long long nb, char c)
{
	unsigned long long	i;

	i = 0;
	if (nb >= 16)
		i += ft_numhex(nb / 16, c);
	if (c == 'x')
		ft_putcharf("0123456789abcdef"[nb % 16]);
	if (c == 'X')
		ft_putcharf("0123456789ABCDEF"[nb % 16]);
	i++;
	return (i);
}
