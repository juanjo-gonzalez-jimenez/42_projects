/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 11:30:53 by vboxuser          #+#    #+#             */
/*   Updated: 2026/10/13 12:20:44 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif
/*Function Prototypes*/
char	*get_next_line(int fd);
char	*stash_join(char *s1, char *s2);
int		stash_checker(char *stash);
size_t	stash_len(char *s);
char	*free_null(char *ptr);

#endif