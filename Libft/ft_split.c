/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:59:32 by juan-jos          #+#    #+#             */
/*   Updated: 2026/09/29 11:00:50 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int		word_count;
	int		word_true;
	size_t	i;

	word_true = 0;
	word_count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			word_true = 0;
		if (s[i] != c && word_true == 0)
		{
			word_true = 1;
			word_count++;
		}
		i++;
	}
	return (word_count);
}

static int	ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*ft_word_dup(char const *s, char c)
{
	char	*word;
	int		len;

	len = ft_word_len(s, c);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	word[len] = '\0';
	return (word);
}

static char	**ft_free_split(char **s_ptr, int j)
{
	while (j > 0)
	{
		j--;
		free(s_ptr[j]);
	}
	free(s_ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**s_ptr;
	int		counter;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	counter = ft_word_count(s, c);
	s_ptr = malloc(sizeof(char *) * (counter + 1));
	if (!s_ptr)
		return (NULL);
	j = 0;
	i = 0;
	while (j < counter)
	{
		while (s[i] == c)
			i++;
		s_ptr[j] = ft_word_dup(s + i, c);
		if (!s_ptr[j])
			return (ft_free_split(s_ptr, j));
		i += ft_strlen(s_ptr[j]);
		j++;
	}
	s_ptr[counter] = NULL;
	return (s_ptr);
}
