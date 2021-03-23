/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:43:29 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/23 17:55:14 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

size_t		ft_strlen(char *s);
char		*ft_strcpy(char *dst, char *src);
int			ft_strcmp(char *s1, char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t nbyte);
ssize_t		ft_read(int fd, void *buf, size_t nbyte);
char		*ft_strdup(const char *s1);
void		ft_list_push_front(t_list **begin_list, void *data);
int			ft_list_size(t_list *begin_list);
void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
														void (*free_fct)(void*));
void		ft_list_sort(t_list **begin_list,int (*cmp)());
#endif
