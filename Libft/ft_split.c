/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:59:32 by juan-jos          #+#    #+#             */
/*   Updated: 2026/09/25 18:02:34 by juan-jos         ###   ########.fr       */
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

static int  ft_word_len(char const *s, char c)
{
    int i;
    
    i = 0;
    while (s[i] != c && s[i] != '\0')
    {
        i++;
    }
    return (i);
}
char	**ft_split(char const *s, char c)
{
    char *ptr;
    int counter;
    int word_len;
    int i;

    i = 0;
    word_len = 0;
    counter = ft_word_count(s, c);
    while (counter > 0)
    {
        while (s[i] == c)
            i++;
        word_len = ft_word_len(s + i, c);
        ptr = malloc(sizeof(char) * word_len + 1);
    }
}