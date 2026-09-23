/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 14:27:28 by juan-jos          #+#    #+#             */
/*   Updated: 2026/09/23 15:53:14 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	atoi(const char *nptr)
{
	int	i;
	int	mincount;
	int	c;

	i = 0;
	mincount = 1;
	c = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
	{
		i++;
	}
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
		{
			mincount = -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		c = (c * 10) + (nptr[i] - '0');
		i++;
	}
	return (c * mincount);
}
