/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:23:33 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/14 14:51:08 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dupstr(char *s1)
{
	char	*ptr;
	int		len;

	if (s1 == NULL)
		s1 = "(null)";
	len = ft_strlen(s1) + 1;
	ptr = (char *)malloc(len);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len);
	return (ptr);
}
