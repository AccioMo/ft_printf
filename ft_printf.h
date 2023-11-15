/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:25:16 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/14 17:38:07 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_printf_multiverse(char **to_print, va_list args);
int		ft_putchar(char c);
char	*ft_dupchr(int c);
char	*ft_dupstr(char *str);
char	*ft_dupnbr(int nbr);
char	*ft_dupunbr(unsigned int nbr);
char	*ft_dupaddr(unsigned long addr);
char	*ft_duphex(unsigned int nbr, const char *base);
int		ft_putnstr(char *str, int n);
int		ft_putflag(char flag, int width);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_saveflags(char **src);
int		ft_useflags(char *to_print, char *flags, char type);
int		ft_strlcpy(char *dest, char *src, int size);
int		ft_strlen(char *str);
int		ft_isdigit(int c);

#endif
