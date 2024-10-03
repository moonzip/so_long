/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nosigne.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:47:37 by lucmart3          #+#    #+#             */
/*   Updated: 2024/07/17 16:17:25 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nosigne(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_nosigne(n / 10);
	count += ft_putcharf(n % 10 + '0');
	return (count);
}
