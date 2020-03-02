/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:43:23 by hael-bri          #+#    #+#             */
/*   Updated: 2019/10/28 16:43:24 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -2147483648)
		str = ft_strcpy(str, "-2147483648");
	else if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-n));
	}
	else if (n < 10 && n >= 0)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	else if (n >= 10)
		str = ft_strjoin((ft_itoa(n / 10)), ft_itoa(n % 10));
	return (str);
}
