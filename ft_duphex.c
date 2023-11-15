/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duphex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:33:18 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/15 22:22:40 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long	get_hexdigits(unsigned long n)
{
	unsigned long	digits;

	digits = 1;
	while (n / 16)
	{
		digits += 1;
		n /= 16;
	}
	return (digits);
}

char	*ft_duphex(unsigned int nbr, const char *base)
{
	unsigned int	digits;
	char			*dup;

	digits = get_hexdigits(nbr);
	dup = (char *)malloc((digits + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	*dup = '0';
	dup += digits;
	*dup = '\0';
	while (nbr)
	{
		dup--;
		*dup = base[nbr % 16];
		nbr /= 16;
		digits--;
	}
	return (dup - digits);
}

char	*ft_dupaddr(unsigned long addr)
{
	unsigned long	digits;
	char			*dup;

	digits = get_hexdigits(addr);
	dup = (char *)malloc((digits + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	*dup = '0';
	dup += digits;
	*dup = '\0';
	while (addr)
	{
		dup--;
		*dup = LOWER_HEX[addr % 16];
		addr /= 16;
		digits--;
	}
	return (dup - digits);
}
