/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:05:18 by hael-bri          #+#    #+#             */
/*   Updated: 2020/02/29 20:52:13 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_the_str(char *str, t_flag *f)
{
	t_var	s;

	s.mem = ft_strlen(str);
	s.count = (f->width > s.mem) ? f->width : s.mem;
	if (f->width > s.mem)
		s.count = f->width;
	if (f->flag == '/')
		print_spaces(f->width - s.mem);
	if (f->flag == '0')
		print_zeros(f->width - s.mem);
	ft_putstr(str);
	if (f->flag == '-')
		print_spaces(f->width - s.mem);
	return (s.count);
}

int		put_string_precision(char *str, t_flag *f)
{
	t_var	s;

	s.count = 0;
	s.j = -1;
	s.mem = ft_strlen(str);
	s.mem = (f->precision > s.mem) ? s.mem : f->precision;
	if ((f->flag == '/' || f->flag == '0') && f->width > s.mem)
	{
		s.count = f->width - s.mem;
		if (f->flag == '0')
			print_zeros(s.count);
		else
			print_spaces(f->width - s.mem);
	}
	while (++s.j < s.mem)
		ft_putchar(str[s.j]);
	s.count += s.j;
	if (f->flag == '-' && f->width > s.mem)
	{
		print_spaces(f->width - s.mem);
		s.count += f->width - s.mem;
	}
	return (s.count);
}

int		put_spaces(int n)
{
	print_spaces(n);
	return (n);
}

int		put_zeros(int n)
{
	print_zeros(n);
	return (n);
}

int		print_string(t_flag *f, va_list ap)
{
	t_var	s;

	s = (t_var){va_arg(ap, char *), 0, 0, 0, 0, 0, 0};
	if (f->point == 1 && f->precision == IM)
		f->precision = 0;
	(s.tmp == NULL) ? s.tmp = "(null)" : "1";
	if (f->point == 1 && f->precision == IM)
		return (put_spaces(f->width));
	if (f->precision < 0)
		s.count = put_the_str(s.tmp, f);
	else if (f->point == IM)
		s.count = put_the_str(s.tmp, f);
	if (f->precision == 0)
	{
		if (f->width >= 1 && s.count == 0)
		{
			if (f->flag == '0')
				print_zeros(f->width);
			else
				return (put_spaces(f->width));
		}
	}
	else if (f->precision > 0 && s.count == 0)
		s.count = put_string_precision(s.tmp, f);
	return (s.count);
}
