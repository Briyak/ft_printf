/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:00:05 by hael-bri          #+#    #+#             */
/*   Updated: 2019/11/03 17:00:06 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		nbr = -n;
	}
	if (nbr <= 9)
		ft_putchar(nbr + 48);
	else
	{
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + 48);
	}
}
