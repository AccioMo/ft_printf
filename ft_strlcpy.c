/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 01:31:51 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/14 14:39:46 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	len;

	len = ft_strlen(src);
	while (size > 1 && *src)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	if (size)
		*dest = '\0';
	return (len);
}
