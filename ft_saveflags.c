/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saveflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:46:21 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/15 00:15:10 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_saveflags(char **src)
{
	char	*flags;
	int		len;

	len = 0;
	while (ft_strchr("-0.# +", *(*src + len)) || ft_isdigit(*(*src + len)))
		len++;
	flags = ft_substr(*src, 0, len);
	*src = (*src + len);
	return (flags);
}
