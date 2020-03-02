/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:36:01 by hael-bri          #+#    #+#             */
/*   Updated: 2019/10/23 22:52:01 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char*)haystack);
	if (!haystack && len == 0)
		return (NULL);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 1;
		if (haystack[i] == needle[0])
		{
			while (needle[j] && (i + j) < len)
			{
				if (haystack[i + j] != needle[j])
					break ;
				j++;
			}
			if (needle[j] == '\0')
				return ((char*)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
