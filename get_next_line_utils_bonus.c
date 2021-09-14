/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 10:55:15 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/14 16:09:48 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{	
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_len(const char *str)
{
	size_t	l;

	l = 0;
	if (!str)
		return (0);
	while (str[l] != '\0')
		l++;
	return (l);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	e;

	j = ft_len(src);
	i = ft_len(dest);
	if (size > i && size > 0)
	{
		e = i + j;
		size = size - i - 1;
		j = 0;
		while (src[j] && size != 0 )
		{
			dest[i++] = src[j++];
			size--;
		}
		dest[i] = '\0';
	}
	else
		e = size + j;
	return (e);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!src)
		return (0);
	while (src[j] != '\0')
		j++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	num_chars;

	i = 0;
	num_chars = 0;
	if (!s || len <= 0)
		return (NULL);
	if (start < ft_len(s))
		num_chars = ft_len(s) - (size_t)start;
	if (len < num_chars)
		num_chars = len;
	p = (char *)malloc((num_chars + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (num_chars && start < ft_len(s))
	{
		p[i] = ((char *)s)[start + i];
		i++;
		num_chars--;
	}
	p[i] = '\0';
	return (p);
}

t_gnl	*ft_lstnew_gnl(int file)
{
	t_gnl	*new_elem;

	new_elem = malloc(sizeof(t_gnl));
	if (!new_elem)
		return (0);
	new_elem->file = file;
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_addback_gnl(t_gnl **lst, t_gnl *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

t_gnl	*ft_lstlast(t_gnl *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void ft_clear_file(t_gnl **linked, int fd)
{
    t_gnl *ptr_current;
    t_gnl *ptr_previous;

    ptr_previous = *linked;
	if (ptr_previous->file == fd)
	{
		ptr_previous = ptr_previous->next;
		free(*linked);
		(*linked) = ptr_previous;
		return ;
	}
    while (ptr_previous->next && ptr_previous->next->file != fd) 
		ptr_previous = ptr_previous->next;
	ptr_current = ptr_previous->next;
	if (ptr_current->file == fd)
	{
		ptr_previous->next = ptr_current->next;
		free(ptr_current);
		return ;
	}
}
