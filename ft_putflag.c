/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:26:49 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/14 14:43:44 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putflag(char flag, int width)
{
	int	len;

	len = 0;
	while (len < width)
		len += write(1, &flag, 1);
	return (len);
}
