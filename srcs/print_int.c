/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:43:26 by hael-bri          #+#    #+#             */
/*   Updated: 2020/02/29 21:12:35 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_negative_number(int nbr, t_flag *f)
{
	t_var	n;

	if (nbr == IM)
		n.count = f->width - ft_count_digit(nbr);
	else
		n.count = f->width - ft_count_digit(nbr) - 1;
	if (f->flag == '/')
		print_spaces(n.count);
	ft_putchar('-');
	if (f->flag == '0')
		print_zeros(n.count);
}

int		put_the_int_number(int nbr, t_flag *f)
{
	t_var	n;

	n.umem = (nbr == IM) ? nbr : 0;
	n.umem *= -1;
	n.j = (nbr < 0) ? -1 : 0;
	n.mem = ft_count_digit(nbr);
	nbr *= (n.j == -1) ? -1 : 1;
	n.count = (f->width > n.mem) ? f->width : n.mem;
	(n.j == -1) ? put_negative_number(nbr, f) : 0;
	if (f->flag == '/' && n.j == 0)
		print_spaces(f->width - ft_count_digit(nbr));
	else if (f->flag == '0' && n.j == 0)
		print_zeros(f->width - ft_count_digit(nbr));
	if (n.umem != 0)
		ft_putunbr(n.umem);
	else if (n.umem == 0)
		ft_putnbr(nbr);
	if (f->flag == '-' && n.j == -1)
		print_spaces(f->width - ft_count_digit(nbr) - 1);
	else if (f->flag == '-' && n.j == 0)
		print_spaces(f->width - ft_count_digit(nbr));
	return (n.count);
}

int		put_int_precision_max(int nbr, t_flag *f)
{
	t_var	n;

	n = (t_var){NULL, 0, 0, 0, ft_count_digit(nbr), 0, 0};
	n.count = n.mem;
	if (nbr < 0)
	{
		n.j = -1;
		nbr *= -1;
	}
	if (f->precision > n.mem)
		n.count += f->precision - n.mem;
	if (n.j == -1)
		ft_putchar('-');
	if (n.j == -1 && (f->precision - n.mem + 1) > 0)
	{
		print_zeros(f->precision - n.mem + 1);
		n.count++;
	}
	else
		print_zeros(f->precision - n.mem);
	ft_putnbr(nbr);
	return (n.count);
}

int		put_int_precision_min(int nbr, t_flag *f)
{
	t_var	n;

	n = (t_var){NULL, ft_count_digit(nbr), 0, 0, ft_count_digit(nbr), 0, 0};
	n.j = (nbr < 0) ? -1 : 0;
	nbr *= (nbr < 0) ? -1 : 1;
	n.i = (f->precision > n.mem) ? f->precision : n.mem;
	if (f->precision >= n.mem)
		n.i = (n.j == -1) ? f->precision + 1 : f->precision;
	else
		n.i = n.mem;
	if (f->width > n.mem)
		n.count = f->width;
	if (f->flag != '-')
		print_spaces(f->width - n.i);
	if (n.j == -1)
		ft_putchar('-');
	if (n.j == -1)
		print_zeros(f->precision - n.mem + 1);
	else
		print_zeros(f->precision - n.mem);
	ft_putnbr(nbr);
	if (f->flag == '-')
		print_spaces(f->width - n.i);
	return (n.count);
}

int		print_int(t_flag *f, va_list ap)
{
	t_var	n;

	n.count = 0;
	(f->width < 0) ? f->width = 0 : 1;
	(f->precision < 0) ? f->precision = 0 : 1;
	n.mem = va_arg(ap, int);
	if (f->point == 1 && f->precision == 0 && n.mem == 0)
	{
		print_spaces(f->width);
		return (f->width);
	}
	if (f->point == IM || f->precision == 0)
		n.count = put_the_int_number(n.mem, f);
	else if (f->precision > 0)
	{
		if (f->precision >= f->width)
		{
			n.count = put_int_precision_max(n.mem, f);
		}
		else if (f->width > f->precision)
			n.count = put_int_precision_min(n.mem, f);
	}
	return (n.count);
}
