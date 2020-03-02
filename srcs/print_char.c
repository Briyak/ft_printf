/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 12:38:36 by hael-bri          #+#    #+#             */
/*   Updated: 2020/02/29 20:51:06 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_undefined(char *str, int j)
{
	ft_putchar(str[j]);
	return (1);
}

void	print_spaces(int j)
{
	while (j > 0)
	{
		ft_putchar(' ');
		j--;
	}
}

void	print_zeros(int j)
{
	while (j > 0)
	{
		ft_putchar('0');
		j--;
	}
}

int		print_char(t_flag *f, va_list ap)
{
	char	c;
	int		count;

	count = 1;
	c = f->specifier;
	(f->width == IM) ? f->width = 1 : 0;
	(c == 'c') ? c = va_arg(ap, int) : '%';
	if (f->width > 1 && f->flag == '-')
	{
		ft_putchar(c);
		print_spaces(f->width - 1);
		return (f->width);
	}
	if (f->width > 1 && f->flag != '-')
	{
		if (f->specifier == '%' && f->flag == '0')
			print_zeros(f->width - 1);
		else
			print_spaces(f->width - 1);
	}
	ft_putchar(c);
	(f->width > count) ? count = f->width : 1;
	return (count);
}
