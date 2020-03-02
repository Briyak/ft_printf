/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:31:39 by hael-bri          #+#    #+#             */
/*   Updated: 2020/02/24 18:24:40 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_hexadecimal(unsigned int nbr, t_flag *f)
{
	t_var	h;

	h.mem = count_hex_digit(nbr);
	h.j = f->width - h.mem;
	h.count = (f->width > h.mem) ? f->width : h.mem;
	if (f->flag == '0')
		print_zeros(h.j);
	if (f->flag == '/')
		print_spaces(h.j);
	put_the_hex(nbr, f);
	if (f->flag == '-')
		print_spaces(h.j);
	return (h.count);
}

int		put_hex_precision_max(unsigned int nbr, t_flag *f)
{
	t_var	h;

	h = (t_var){NULL, count_hex_digit(nbr), 0, 0, count_hex_digit(nbr), 0, 0};
	if (f->precision > h.count)
		h.count = f->precision;
	print_zeros(f->precision - h.mem);
	put_the_hex(nbr, f);
	return (h.count);
}

int		put_hex_precision_min(unsigned int nbr, t_flag *f)
{
	t_var	h;

	h = (t_var){NULL, count_hex_digit(nbr), 0, 0, count_hex_digit(nbr), 0, 0};
	h.i = (f->precision > h.mem) ? f->precision : h.mem;
	if (f->width > h.mem)
		h.count = f->width;
	if (f->flag != '-')
		print_spaces(f->width - h.i);
	print_zeros(f->precision - h.mem);
	put_the_hex(nbr, f);
	if (f->flag == '-')
		print_spaces(f->width - h.i);
	return (h.count);
}

int		print_hex(t_flag *f, va_list ap)
{
	t_var	h;

	h = (t_var){NULL, 0, 0, 0, 0, 0, va_arg(ap, unsigned int)};
	if (f->point == 1 && f->precision == IM)
		f->precision = 0;
	(f->precision < 0) ? f->precision = 1 : 0;
	if (f->point == 1 && f->precision == 0 && h.umem == 0)
		return (put_spaces(f->width));
	if (f->precision == 0 && h.umem == 0)
		return (put_spaces(f->width));
	if (f->point == IM)
		h.count = print_hexadecimal(h.umem, f);
	else if (f->precision >= 0)
	{
		if (f->precision >= f->width)
			h.count = put_hex_precision_max(h.umem, f);
		else if (f->width > f->precision)
			h.count = put_hex_precision_min(h.umem, f);
	}
	return (h.count);
}
