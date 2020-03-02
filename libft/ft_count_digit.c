/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:53:46 by hael-bri          #+#    #+#             */
/*   Updated: 2020/02/23 14:09:07 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digit(unsigned int n)
{
	int		i;
	char	*str;

	str = ft_itoa(n);
	i = 0;
	if (n == 0)
		return (1);
	else
		return (ft_strlen(str));
}
