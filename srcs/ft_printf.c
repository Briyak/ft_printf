/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:08:11 by hael-bri          #+#    #+#             */
/*   Updated: 2020/03/02 15:39:47 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		poste_error(t_flag *f)
{
	t_var	v;

	v.count = -1;
	if (f->specifier == '/')
		return (0);
	while (f->type[++v.count])
	{
		if (f->specifier == f->type[v.count])
		{
			f->specifier = f->type[v.count];
			return (v.count);
		}
	}
	return (-1);
}

int		la_poste(t_flag *f, va_list ap)
{
	t_var	v;

	v.count = 0;
	if (f->specifier == '%' || f->specifier == 'c')
		v.count = print_char(f, ap);
	if (f->specifier == 's')
		v.count = print_string(f, ap);
	if (f->specifier == 'd' || f->specifier == 'i')
		v.count = print_int(f, ap);
	if (f->specifier == 'u')
		v.count = print_unsint(f, ap);
	if (f->specifier == 'x' || f->specifier == 'X')
		v.count = print_hex(f, ap);
	if (f->specifier == 'p')
		v.count = print_pointer(f, ap);
	else if (v.count == 0 && ((v.i = poste_error(f)) == -1) && f->specifier != '/')
		v.count = print_char(f, ap);
	return (v.count);
}

int		ft_printf(const char *format, ...)
{
	t_var	v;
	t_flag	flag;
	va_list	ap;

	v.i = -1;
	v.total = 0;
	va_start(ap, format);
	while (format[++v.i])
	{
		if (format[v.i] == '%')
		{
			v.i += check_in((char *)format, &flag, ap, v.i + 1);
			v.count = la_poste(&flag, ap);
			if (v.count > 0)
				v.total += v.count;
		}
		else if (v.i < ft_strlen((char *)format))
		{
			v.total += print_undefined((char *)format, v.i);
		}
	}
	va_end(ap);
	return (v.total);
}
