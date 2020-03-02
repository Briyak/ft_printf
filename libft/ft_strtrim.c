/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:56:10 by hael-bri          #+#    #+#             */
/*   Updated: 2019/10/23 22:53:10 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_search(char const *set, char c)
{
	int i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (-1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*str;
	int		len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	if (!s1[i])
		return (ft_strcpy(ft_calloc(1, sizeof(char)), "\0"));
	while (ft_search(set, s1[i]) == -1)
		i++;
	len = ft_strlen(s1) - 1;
	while (ft_search(set, s1[len]))
		len--;
	if (len >= i)
		len -= i;
	if (!(str = (char *)malloc(sizeof(char) * len + 2)))
		return (NULL);
	ft_strncpy(str, s1 + i, len + 1);
	str[len + 1] = '\0';
	return (str);
}
