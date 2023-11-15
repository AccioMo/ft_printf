/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:15:59 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/14 16:35:01 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	get_mag(unsigned int n)
{
	int	digits;

	digits = 1;
	while (n / 10)
	{
		n /= 10;
		digits += 1;
	}
	return (digits);
}

char	*ft_dupunbr(unsigned int nbr)
{
	unsigned int	digits;
	char			*nstr;

	digits = get_mag(nbr);
	nstr = (char *)malloc((digits + 1) * sizeof(char));
	if (!nstr)
		return (NULL);
	*nstr = '0';
	nstr += digits;
	*nstr = '\0';
	while (nbr)
	{
		nstr--;
		*nstr = (nbr % 10) + 48;
		nbr /= 10;
		digits--;
	}
	return (nstr - digits);
}
