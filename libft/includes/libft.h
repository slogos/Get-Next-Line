/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 11:31:44 by slogos            #+#    #+#             */
/*   Updated: 2016/11/09 01:22:14 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_strnjoin(char const *s1, char const *s2, size_t len);
char				*ft_strndup(const char *s, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strnew(size_t size);

#endif
