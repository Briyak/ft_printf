/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:03:39 by hael-bri          #+#    #+#             */
/*   Updated: 2020/02/28 15:12:36 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"
# define ULI		unsigned long int
# define IM			-2147483648

typedef struct		s_var
{
	char			*tmp;
	int				count;
	int				i;
	int				j;
	int				mem;
	int				total;
	unsigned int	umem;
}					t_var;

typedef struct		s_flag
{
	char			flag;
	char			specifier;
	char			*type;
	int				point;
	int				precision;
	int				width;
}					t_flag;

int					ft_printf(const char *format, ...);
int					la_poste(t_flag *f, va_list ap);
int					check_in(char *str, t_flag *f, va_list ap, int j);
int					check_flag(char *s, t_flag *f, int j);
int					check_with(char *str, t_flag *f, va_list ap, int j);
int					check_precision(char *str, t_flag *f, va_list ap, int j);
int					check_specifer(char *str, t_flag *f, int j);
int					error_width(char *str, t_flag *f, int j);
int					error_precision(char *str, t_flag *f, int j);
int					print_undefined(char *str, int j);
void				print_spaces(int j);
void				print_zeros(int j);
int					print_char(t_flag *f, va_list ap);
int					print_string(t_flag *f, va_list ap);
int					get_string_precision(char *str, t_flag *f);
int					put_the_str(char *str, t_flag *f);
int					print_int(t_flag *f, va_list ap);
int					put_the_int_number(int nbr, t_flag *f);
int					put_int_precision_max(int nbr, t_flag *f);
int					put_int_precision_min(int nbr, t_flag *f);
int					print_unsint(t_flag *f, va_list ap);
int					put_the_uint_number(unsigned int nbr, t_flag *f);
int					put_uint_precision_max(unsigned int nbr, t_flag *f, int s);
int					put_uint_precision_min(unsigned int nbr, t_flag *f);
int					print_hex(t_flag *f, va_list ap);
int					put_the_hex(unsigned int p, t_flag *f);
void				put_hex_maj(unsigned int n);
void				put_hex_mini(unsigned int n);
int					print_pointer(t_flag *f, va_list ap);
int					put_the_pointer(unsigned long int addr, t_flag *f);
int					count_hex_digit(unsigned int n);
void				print_flags(t_flag *f);
int					put_spaces(int n);
int					put_zeros(int n);

#endif
