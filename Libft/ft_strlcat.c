/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:41:13 by juan-jos          #+#    #+#             */
/*   Updated: 2026/07/06 11:52:25 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	i = 0;
	while (src[i] != '\0' && size > (dest_len + i + 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*int	main(void)
{
	char src[] = "Malaga";
	char dest[5] = "Hola ";
	unsigned int result;

	result = ft_strlcat (dest, src, 11);
	printf ("%s\n", dest);
	//printf ("%u\n", result);

}*/
