/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:45:33 by hael-bri          #+#    #+#             */
/*   Updated: 2019/10/23 22:45:36 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	int len;

	len = ft_strlen(s);
	if (!c)
		return ((char *)s + len);
	i = -1;
	while (s[++i] && i < len)
		if (s[i] == c)
			return ((char *)s + i);
	if (i == len)
		return (NULL);
	return (NULL);
}
