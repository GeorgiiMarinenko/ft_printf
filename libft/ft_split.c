/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:16:29 by georgy            #+#    #+#             */
/*   Updated: 2020/11/12 19:16:30 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char space)
{
	size_t	i;
	size_t	cnt;
	size_t	left_border;

	i = 0;
	left_border = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == space && left_border > 0)
		{
			left_border = 0;
			cnt++;
		}
		if (s[i] != space)
			left_border++;
		i++;
	}
	if (left_border > 0)
		cnt++;
	return (cnt);
}

static char		**arr_free(char **arr, size_t index)
{
	size_t	j;

	j = 0;
	if (arr)
	{
		while (j < index)
		{
			free(arr[j]);
			j++;
		}
		free(arr);
	}
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**rez;
	size_t	i;
	size_t	j;
	size_t	left_border;

	if (!s)
		return (NULL);
	if (!(rez = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		left_border = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (!(rez[j++] = ft_substr(s, left_border, i - left_border)))
			return (arr_free(rez, i));
	}
	rez[j] = NULL;
	return (rez);
}
