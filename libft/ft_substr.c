/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:53:21 by hael-bri          #+#    #+#             */
/*   Updated: 2020/02/16 17:55:02 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	if (s != NULL)
	{
		while (s[start] && i < len && start < (unsigned int)ft_strlen(s))
			dest[i++] = s[start++];
		dest[i] = '\0';
	}
	return (dest);
}
