/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 10:50:21 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/14 16:09:44 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h> 
#include <stdio.h> 
#include "get_next_line_bonus.h"

char	*ft_remain_in_temp(char *temp, char *final, t_gnl **linked, int fd)
{
	char	*new_temp;
	int		len;
	int		start;

	len = ft_len(temp) - ft_len(final);
	start = ft_len(final);
	new_temp = ft_substr(temp, start, len);
	if (!ft_strchr(temp, '\n'))
	{
		free(temp);
		ft_clear_file(linked, fd);	
		return (NULL);
	}
	else
		free(temp);
	return (new_temp);
}

char	*ft_final_str(char *final, char *temp)
{
	size_t	len;

	len = 0;
	if (!temp)
		return (NULL);
	if (ft_strchr(temp, '\n'))
		final = ft_substr(temp, 0, ft_len(temp)
				- ft_len(ft_strchr(temp, '\n')) + 1);
	else
		final = ft_substr(temp, 0, ft_len(temp));
	return (final);
}

char	*ft_update_temp(char *temp, char *buff)
{
	char	*p;

	if (!temp)
	{
		temp = malloc (1);
		temp[0] = '\0';
	}
	p = (char *)malloc((ft_len(temp) + ft_len(buff) + 1) * sizeof(char));
	if (!p)
	{
		return (NULL);
	}
	ft_strlcpy(p, temp, ft_len(temp) + 1);
	ft_strlcat(&p[ft_len(temp)], buff, ft_len(buff) + 1);
	free(temp);
	return (p);
}

char	*ft_read_to_temp(int fd, char *temp)
{
	char	*buff;
	int		nbytes;

	nbytes = 1;
	while (!ft_strchr(temp, '\n') && nbytes > 0)
	{
		buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!buff)
			return (0);
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nbytes] = '\0';
		temp = ft_update_temp(temp, buff);
		free(buff);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*final;
	static struct s_gnl		*linked;
	t_gnl		*ptr_linked;
	int	i;

	i = 0;
	final = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	/////   BUCLE BONUS PARA ASIGNAR FD A LINKED     ////////
	ptr_linked = linked;
	while (ptr_linked && ptr_linked->file != fd)
		ptr_linked = ptr_linked->next;
	if (!ptr_linked)
	{
		ptr_linked = ft_lstnew_gnl(fd);
		//printf("ADDR: %p\n", ptr_linked);
		ft_addback_gnl(&linked, ptr_linked);
		ptr_linked->temp = NULL;
	}
	////////////////////////////////////////////////////
	if (!ft_strchr(ptr_linked->temp, 10))
		ptr_linked->temp = ft_read_to_temp(fd, ptr_linked->temp);
	final = ft_final_str(final, ptr_linked->temp);
	if (ft_len(final))
		ptr_linked->temp = ft_remain_in_temp(ptr_linked->temp, final, &linked, fd);
	else
	{
		free(ptr_linked->temp);
		ft_clear_file(&linked, fd);
	}
	return (final);
}
