/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:30:58 by hael-bri          #+#    #+#             */
/*   Updated: 2020/02/29 18:49:59 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flag(char *s, t_flag *f, int j)
{
	if ((s[j] == '-' && s[j - 1] == '%') || (s[j] == '0' && s[j - 1] == '%'))
	{
		if (s[j] == '-')
		{
			f->flag = '-';
			return (1);
		}
		if (s[j] == '0' && f->flag == '/')
		{
			f->flag = '0';
			return (1);
		}
	}
	return (0);
}

int		check_with(char *str, t_flag *f, va_list ap, int j)
{
	if (str[j] == '*')
	{
		f->width = va_arg(ap, int);
		return (1);
	}
	else if (ft_isdigit(str[j]) == 1 && str[j] != '0' && str[j] != '-')
	{
		f->width = ft_atoi(&str[j]);
		return (ft_count_digit(f->width));
	}
	else
		f->width = 0;
	return (0);
}

int		check_precision(char *str, t_flag *f, va_list ap, int j)
{
	t_var	v;

	f->point = 1;
	v.mem = ++j;
	if ((v.j = error_precision(str, f, v.mem)) != -1)
		return (j);
	while (str[j] == '0')
	{
		f->precision = 0;
		j++;
	}
	if (ft_isdigit(str[j]) == 1 && str[j] != '0')
	{
		f->precision = ft_atoi(&str[j]);
		j += ft_count_digit(f->precision);
		return (j);
	}
	if (str[j] == '*')
	{
		f->precision = va_arg(ap, int);
		j++;
	}
	return (j);
}

int		check_specifer(char *str, t_flag *f, int j)
{
	t_var	a;

	a.count = -1;
	a.mem = j;
	while (str[j] == ' ')
		j++;
	while (f->type[++a.count])
	{
		if (str[j] != '\0' && str[j] == f->type[a.count])
		{
			f->specifier = f->type[a.count];
			j++;
			return (j - a.mem);
		}
	}
	if (ft_isprint(str[j]) && f->specifier == '/')
	{
		f->specifier = str[j];
		return (j - a.mem + 1);
	}
	return (-1);
}

int		check_in(char *str, t_flag *f, va_list ap, int j)
{
	t_var	v;

	v.j = j;
	*f = (t_flag){'/', '/', "cspdiuxX%", IM, IM, IM};
	j += check_flag(str, f, j);
	v.mem = j;
	while (str[j] == '0' || str[j] == '-')
	{
		if (str[j] == '-' && f->flag != '-')
			f->flag = '-';
		j++;
	}
	j += check_with(str, f, ap, j);
	j = error_width(str, f, j);
	if (str[j] == '.')
		j = check_precision(str, f, ap, j);
	if ((v.mem = check_specifer(str, f, j)) != -1)
		j += v.mem;
	return (j - v.j);
}
