/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:26:41 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/14 16:51:54 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dupchr(int c)
{
	char	*dup;

	dup = (char *)malloc(2 * sizeof(char));
	if (!dup)
		return (NULL);
	dup[0] = (char)c;
	dup[1] = '\0';
	return (dup);
}
