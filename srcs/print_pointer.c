/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 20:08:38 by hael-bri          #+#    #+#             */
/*   Updated: 2020/03/01 17:52:33 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_pointer_addr(ULI n)
{
	if (n >= 16)
		put_pointer_addr(n / 16);
	n = n % 16;
	n += n < 10 ? '0' : 'a' - 10;
	write(1, &n, 1);
}

int		count_pointer_digit(ULI addr)
{
	t_var	p;

	p.count = 0;
	if (addr == 0)
		return (3);
	while (addr)
	{
		addr /= 16;
		p.count++;
	}
	return (p.count + 2);
}

int		put_the_pointer(ULI addr, t_flag *f)
{
	t_var	p;

	p.mem = count_pointer_digit(addr);
	p.count = (f->width > p.mem) ? f->width : p.mem;
	p.i = (f->point == 1) ? f->width - p.mem + 1 : f->width - p.mem;
	if ((f->point == 1 && f->precision == IM) && (addr == 0 && f->width == 0))
		p.count--;
	if (f->flag == '/' && f->width > p.mem)
		print_spaces(p.i);
	ft_putstr("0x");
	if (f->point == IM || ((f->point == 1 && f->precision == IM) && addr != 0))
		put_pointer_addr(addr);
	if (f->flag == '0' && f->width > p.mem)
		print_zeros(f->width - p.mem);
	if (f->flag == '-' && f->width > p.mem)
		print_spaces(p.i);
	return (p.count);
}

int		print_pointer(t_flag *f, va_list ap)
{
	t_var	p;
	ULI		x;

	p = (t_var){NULL, 0, 0, 0, 0, 0, 0};
	x = va_arg(ap, ULI);
	if ((f->point == 1 && f->precision == IM) || f->point == IM)
		p.count = put_the_pointer(x, f);
	else if (f->precision == 0)
		p.count = put_the_pointer(x, f);
	else if (f->precision > 0)
	{
		ft_putstr("0x");
		put_pointer_addr(x);
		p.count = count_pointer_digit(x);
	}
	return (p.count);
}
