/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmart3 <lucmart3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 07:37:31 by lucmart3          #+#    #+#             */
/*   Updated: 2024/07/17 16:17:17 by lucmart3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(va_list *end, const char *type, int i)
{
	int	total;

	total = 0;
	if (type[i] == 'c')
		total += ft_putcharf((char) va_arg(*end, int));
	if (type[i] == 's')
		total += ft_putstrf(va_arg(*end, char *));
	if (type[i] == 'p')
		total += ft_pointer(va_arg(*end, intptr_t));
	if (type[i] == 'd' || type[i] == 'i')
		total += ft_putnbrf(va_arg(*end, int));
	if (type[i] == 'u')
		total += ft_nosigne(va_arg(*end, unsigned int));
	if (type[i] == 'x' || type[i] == 'X')
		total += ft_numhex(va_arg(*end, unsigned int), type[i]);
	if (type[i] == '%')
		total += ft_putcharf('%');
	return (total);
}

int	ft_printf(char const *str, ...)
{
	int		count;
	int		i;
	va_list	list;

	count = 0;
	i = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_putcharf(str[i]);
		if (str[i] == '%')
		{
			i++;
			count += ft_check(&list, str, i);
		}
		i++;
	}
	va_end(list);
	return (count);
}
