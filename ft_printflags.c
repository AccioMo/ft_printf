/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:21:14 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/14 11:36:04 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*ft_addflag(char txt, int width)
{
	t_flag	*flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	if (!flag)
		return (NULL);
	flag->txt = txt;
	flag->width = width;
	return (flag);
}

int	ft_printflags(t_flag *flag)
{
	int	len;

	len = 0;
	while (flag->width)
	{
		write(1, &flag->txt, 1);
		flag->width--;
	}
	return (len);
}
