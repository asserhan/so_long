/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:58:05 by hasserao          #+#    #+#             */
/*   Updated: 2022/11/12 15:29:17 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_print_str(va_list ap, char str, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr_address(unsigned long long n, int *len);
void	ft_print_address(unsigned long long n, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putnbr_u(unsigned int n, int *len);
void	ft_putnbr_base(unsigned int n, char *base, int *len);
#endif
