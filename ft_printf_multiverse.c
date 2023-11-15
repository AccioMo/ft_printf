/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_multiverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:32:32 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/15 00:23:48 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_multiverse(char **to_print, va_list args)
{
	char	*flags;
	char	*dup;

	flags = ft_saveflags(to_print);
	if (!flags)
		return (-1);
	if (**to_print == 'c')
		dup = ft_dupchr(va_arg(args, int));
	else if (**to_print == 's')
		dup = ft_dupstr(va_arg(args, char *));
	else if (**to_print == 'd' || **to_print == 'i')
		dup = ft_dupnbr(va_arg(args, int));
	else if (**to_print == 'u')
		dup = ft_dupunbr(va_arg(args, unsigned int));
	else if (**to_print == 'p')
		dup = ft_dupaddr(va_arg(args, unsigned long));
	else if (**to_print == 'x')
		dup = ft_duphex(va_arg(args, unsigned int), LOWER_HEX);
	else if (**to_print == 'X')
		dup = ft_duphex(va_arg(args, unsigned int), UPPER_HEX);
	else
		dup = ft_dupchr(**to_print);
	if (!dup)
	{
		free(flags);
		return (-1);
	}
	return (ft_useflags(dup, flags, **to_print));
}
