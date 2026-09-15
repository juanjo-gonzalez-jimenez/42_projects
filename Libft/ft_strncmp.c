/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:45:48 by juan-jos          #+#    #+#             */
/*   Updated: 2026/07/06 12:03:43 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				result;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (s1[i] == s2[i]) && (s1[i] != '\0')
		&& (s2[i] != '\0'))
	{
		i++;
	}
	result = s1[i] - s2[i];
	return (result);
}

/*int main(void)
{
	char string1[] = "hola";
	char string2[] = "hole";

	printf ("%d\n", ft_strncmp(string1, string2, 2));
	return (0);
}*/
