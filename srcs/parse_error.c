/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:16:31 by hael-bri          #+#    #+#             */
/*   Updated: 2020/02/24 14:34:24 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		error_width(char *s, t_flag *f, int j)
{
	if (f->width < 0)
	{
		f->flag = '-';
		f->width *= -1;
	}
	while (f->width == 0 && s[j] == '0')
		j++;
	return (j);
}

int		error_precision(char *str, t_flag *f, int j)
{
	t_var	e;

	e.count = -1;
	e.mem = j;
	e.tmp = "cspdiuxX";
	while (str[j] == ' ')
		j++;
	while (e.tmp[++e.count])
		if (str[j] == e.tmp[e.count])
		{
			f->specifier = e.tmp[e.count];
			j++;
			return (j - e.mem);
		}
	return (-1);
}

void	print_flags(t_flag *f)
{
	ft_putstr("flag = |");
	ft_putchar(f->flag);
	ft_putstr("|\nwidth = |");
	ft_putnbr(f->width);
	ft_putstr("|\npoint = |");
	ft_putnbr(f->point);
	ft_putstr("|\nprecision = |");
	ft_putnbr(f->precision);
	ft_putstr("|\nspecifier = |");
	ft_putchar(f->specifier);
	ft_putstr("|\n-----------------\n");
}
