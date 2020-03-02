/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-bri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:00:43 by hael-bri          #+#    #+#             */
/*   Updated: 2019/10/28 16:00:47 by hael-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cntwrd(char const *s, char c)
{
	unsigned int	i;
	int				cntr;

	i = 0;
	cntr = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cntr++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (cntr);
}

static char		*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

static void		freetab(char **tab, int line)
{
	while (line >= 0)
	{
		free(tab[line]);
		line--;
	}
	free(tab);
}

static char		**te3mira(char const *s, char c, char **tab)
{
	int				i;
	int				k;
	int				mem;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		mem = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > mem)
		{
			tab[k] = ft_strndup(s + mem, i - mem);
			if (tab[k++] == NULL)
				freetab(tab, ft_cntwrd(s, c));
		}
	}
	tab[k] = NULL;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char			**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * ft_cntwrd(s, c) + 1)))
		return (NULL);
	if (!s)
	{
		tab[0] = NULL;
		return (tab);
	}
	tab = te3mira(s, c, tab);
	return (tab);
}
