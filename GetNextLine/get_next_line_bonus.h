/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 11:30:53 by vboxuser          #+#    #+#             */
/*   Updated: 2026/10/14 16:15:49 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef FD_ARRAY
#  define FD_ARRAY 1024
# endif
/*Function Prototypes*/
char	*get_next_line(int fd);
char	*reader(int fd, char *stash);
char	*stash_join(char *s1, char *s2);
char	*extract_line(char *stash);
char	*new_stash(char *stash);
int		stash_checker(char *stash);
size_t	stash_len(char *s);
char	*free_null(char *ptr);

#endif