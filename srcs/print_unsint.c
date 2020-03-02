/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:04:32 by hael-bri          #+#    #+#             */
/*   Updated: 2020/02/28 15:11:21 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_unsint_digit(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int		put_the_uint_number(unsigned int nbr, t_flag *f)
{
	t_var	u;

	u.mem = count_unsint_digit(nbr);
	u.j = f->width - u.mem;
	u.count = (f->width > u.mem) ? f->width : u.mem;
	if (f->flag == '0')
		print_zeros(u.j);
	if (f->flag == '/')
		print_spaces(u.j);
	ft_putunbr(nbr);
	if (f->flag == '-')
		print_spaces(u.j);
	return (u.count);
}

int		put_uint_precision_max(unsigned int nbr, t_flag *f, int signe)
{
	t_var	u;

	u = (t_var){NULL, ft_count_digit(nbr), 0, 0, ft_count_digit(nbr), 0, 0};
	if (f->precision > u.count)
		u.count = f->precision;
	if (signe == -1)
		print_zeros(f->precision - u.mem - 1);
	else if (signe == 1)
		print_zeros(f->precision - u.mem);
	ft_putunbr(nbr);
	return (u.count);
}

int		put_uint_precision_min(unsigned int nbr, t_flag *f)
{
	t_var	u;

	u = (t_var){NULL, ft_count_digit(nbr), 0, 0, ft_count_digit(nbr), 0, 0};
	u.i = (f->precision > u.mem) ? f->precision : u.mem;
	if (f->width > u.mem)
		u.count = f->width;
	if (f->flag != '-')
		print_spaces(f->width - u.i);
	print_zeros(f->precision - u.mem);
	ft_putunbr(nbr);
	if (f->flag == '-')
		print_spaces(f->width - u.i);
	return (u.count);
}

int		print_unsint(t_flag *f, va_list ap)
{
	t_var	u;

	u = (t_var){NULL, 0, 0, 0, 0, 0, va_arg(ap, unsigned int)};
	u.tmp = ft_itoa(u.umem);
	u.i = (u.tmp[0] == '-') ? -1 : 1;
	(f->width < 0) ? f->width = 0 : 1;
	(f->precision < 0) ? f->precision = 0 : 1;
	if (f->point == 1 && f->precision == 0 && u.umem == 0)
	{
		print_spaces(f->width);
		return (f->width);
	}
	if (f->point == IM || f->precision == 0)
		u.count = put_the_uint_number(u.umem, f);
	else if (f->precision > 0)
	{
		if (f->precision >= f->width)
			u.count = put_uint_precision_max(u.umem, f, u.i);
		else if (f->width > f->precision)
			u.count = put_uint_precision_min(u.umem, f);
	}
	return (u.count);
}
