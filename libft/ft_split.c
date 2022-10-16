/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <gf.black.tv@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:14:04 by muganiev          #+#    #+#             */
/*   Updated: 2022/05/31 17:58:36 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	if (c < 0)
		return (0);
	if (s[0] != c)
		words++;
	while (s[i] != '\0' && s[i + 1] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			words++;
		i++;
	}
	return (words);
}

static int	word_len(const char *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start + i] != c && s[start + i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			ptr[start] = ft_substr(s, i, word_len(s, c, i));
			i = i + word_len(s, c, i);
			start++;
		}
		else
			i++;
	}
	ptr[start] = NULL;
	return (ptr);
}
