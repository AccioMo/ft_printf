/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:04:17 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/15 00:06:45 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnstr(char *str, int n)
{
	int	len;

	len = 0;
	while (*str && n)
	{
		if (write(1, str, 1) == -1)
			return (-1);
		str++;
		len++;
		n--;
	}
	return (len);
}
