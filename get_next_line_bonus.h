/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 10:51:20 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/10 21:22:52 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl {
	int file;
	char *temp;
	struct s_gnl *next;
} t_gnl;

char	*get_next_line(int fd);
char	*ft_update_temp(char *temp, char *buff);
char	*ft_final_str(char *final, char *temp);
char	*ft_remain_in_temp(char *temp, char *final, t_gnl **linked, int fd);
char	*ft_read_to_temp(int fd, char *temp);
char	*ft_strchr(char *temp, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_len(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_gnl	*ft_lstnew_gnl(int fd);
void	ft_addback_gnl(t_gnl **lst, t_gnl *new);
t_gnl	*ft_lstlast(t_gnl *lst);
void 	ft_clear_file(t_gnl **linked, int fd);

#endif
