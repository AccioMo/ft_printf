/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:22:40 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/15 23:51:46 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	alt_atoi(char *str)
{
	int		nbr;

	if (!str)
		return (0);
	nbr = 0;
	while (*str == ' ')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		(str)++;
	}
	return (nbr);
}

// static int	ft_alldigit(char *str)
// {
// 	while (*str)
// 	{
// 		if (!ft_isdigit(*str))
// 			return (0);
// 		str++;
// 	}
// 	return (1);
// }

// int	ft_minus_zero(char *dup, char *flags, char type)
// {
// 	if (ft_strchr(flags, '-'))
// 	{
// 		len += ft_putnstr(dup, limit);
// 		len += ft_putflag(' ', alt_atoi(ft_strchr(flags, '-') + 1) - limit);
// 	}
// 	else if (ft_strchr(flags, '0'))
// 	{
// 		len += ft_putflag('0', alt_atoi(ft_strchr(flags, '0')) - limit);
// 		len += ft_putnstr(dup, limit);
// 	}
// 	else
// 	{
// 		len += ft_putflag(' ', width - limit);
// 		if (type == 'c')
// 			len += ft_putchar(*dup);
// 		else
// 			len += ft_putnstr(dup, limit);
// 	}
// 	return (len);
// }

void	ft_print_0x(char *flags, char dup0,char type)
{
	if ((ft_strchr(flags, '#') && dup0 != '0') || type == 'p')
	{
		if (type == 'X')
			ft_putnstr("0X", 2);
		else
			ft_putnstr("0x", 2);
	}
}

int	ft_minus(char *dup, char *flags, int len, char type)
{
	int	width;

	width = alt_atoi(flags);
	if (!width)
		width = alt_atoi(ft_strchr(flags, '-') + 1);
	if (type == 'c')
	{
		if (ft_putchar(*dup) == (-1))
			return (-1);
	}
	else
	{
		if (ft_putnstr(dup, len) == -1)
			return (-1);
	}
	len += ft_putflag(' ', width - len);
	return (len);
}

int	ft_zero(char *dup, char *flags, int len, char type)
{
	if (*flags != '0')
		flags = ft_strchr(flags, '.');
	if (*dup == '-')
		dup += ft_putchar('-');
	len += ft_putflag('0', alt_atoi(flags + 1) - len);
	if (type == 'c')
	{
		if (ft_putchar(*dup) == (-1))
			return (-1);
	}
	else
	{
		if (ft_putnstr(dup, -1) == -1)
			return (-1);
	}
	return (len);
}

int	ft_other(char *dup, char *flags, int len, int type)
{
	int	width;

	width = ft_putflag(' ', alt_atoi(flags) - len);
	ft_print_0x(flags, *dup, type);
	if (type == 'c')
	{
		if (ft_putchar(*dup) == (-1))
			return (-1);
	}
	else
	{
		if (ft_putnstr(dup, len) == -1)
			return (-1);
	}
	return (len + width);
}

int	ft_flag_str(char *dup, char *flags)
{
	int	len;

	len = ft_strlen(dup);
	if (ft_strchr(flags, '.'))
	{
		len = alt_atoi(ft_strchr(flags, '.') + 1);
		if (len > ft_strlen(dup))
			len = ft_strlen(dup);
	}
	if (ft_strchr(flags, '-'))
		len = ft_minus(dup, flags, len, 's');
	else if (*flags == '0')
		len = ft_zero(dup, flags, len, 's');
	else
		len = ft_other(dup, flags, len, 's');
	return (len);
}

int	ft_flag_char(char *dup, char *flags)
{
	int	len;

	len = 1;
	if (ft_strchr(flags, '-'))
		len = ft_minus(dup, flags, len, 'c');
	else if (*flags == '0')
		len = ft_zero(dup, flags, len, 'c');
	else
		len = ft_other(dup, flags, len, 'c');
	return (len);
}

int	ft_flag_num(char *dup, char *flags, char tp)
{
	int	len;

	len = ft_strlen(dup);
	if (ft_strchr(flags, '+') && *dup != '-' && tp != 'u')
		len += ft_putchar('+');
	else if (ft_strchr(flags, ' ') && *dup != '-' && tp != 'u')
		len += ft_putchar(' ');
	if (ft_strchr(flags, '-'))
		len = ft_minus(dup, flags, len, 'i');
	else if (*flags == '0')
		len = ft_zero(dup, flags, len, 'i');
	else if (ft_strchr(flags, '.'))
		len = ft_zero(dup, flags, len - (*dup == '-'), 'i') + (*dup == '-');
	else
		len = ft_other(dup, flags, len, 'i');
	return (len);
}

int	ft_flag_hex(char *dup, char *flags, char type)
{
	int	len;

	len = ft_strlen(dup);
	if ((ft_strchr(flags, '#') && *dup != '0') || type == 'p')
		len += 2;
	if (ft_strchr(flags, '-'))
	{
		ft_print_0x(flags, *dup, type);
		len = ft_minus(dup, flags, len, type);
	}
	else if (*flags == '0')
	{
		ft_print_0x(flags, *dup, type);
		len = ft_zero(dup, flags, len, type);
	}
	else if (ft_strchr(flags, '.'))
	{
		ft_print_0x(flags, *dup, type);
		len = ft_zero(dup, flags, len, type);
	}
	else
		len = ft_other(dup, flags, len, type);
	return (len);
}

int	ft_useflags(char *dup, char *flags, char tp)
{
	int		len;

	if (tp == 'c')
		len = ft_flag_char(dup, flags);
	else if (tp == 's')
		len = ft_flag_str(dup, flags);
	else if (tp == 'd' || tp == 'i' || tp == 'u')
		len = ft_flag_num(dup, flags, tp);
	else if (tp == 'x' || tp == 'X' || tp == 'p')
		len = ft_flag_hex(dup, flags, tp);
	else
		len = ft_flag_str(dup, flags);
	free(flags);
	free(dup);
	return (len);
}
