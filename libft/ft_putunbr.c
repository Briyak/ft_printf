/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:57:22 by hael-bri          #+#    #+#             */
/*   Updated: 2020/02/21 12:57:29 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr(unsigned int n)
{
	if (n <= 9)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
}
