/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:30:50 by hael-bri          #+#    #+#             */
/*   Updated: 2020/02/23 10:45:41 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hex_mini(unsigned int n)
{
	if (n >= 16)
		put_hex_mini(n / 16);
	n = n % 16;
	n += n < 10 ? '0' : 'a' - 10;
	write(1, &n, 1);
}

void	put_hex_maj(unsigned int n)
{
	if (n >= 16)
		put_hex_maj(n / 16);
	n = n % 16;
	n += n < 10 ? '0' : 'A' - 10;
	write(1, &n, 1);
}

int		count_hex_digit(unsigned int n)
{
	t_var	h;

	h.count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		h.count++;
	}
	return (h.count);
}

int		put_the_hex(unsigned int nbr, t_flag *f)
{
	t_var	h;

	h.count = count_hex_digit(nbr);
	if (f->specifier == 'x')
		put_hex_mini(nbr);
	else if (f->specifier == 'X')
		put_hex_maj(nbr);
	return (h.count);
}
