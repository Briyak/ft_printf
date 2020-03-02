/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:32:54 by hael-bri          #+#    #+#             */
/*   Updated: 2019/10/23 22:32:55 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			l;

	str = (unsigned char*)s;
	l = 0;
	while (l < n)
	{
		if (str[l] == (unsigned char)c)
			return ((void*)&str[l]);
		l++;
	}
	return (0);
}
