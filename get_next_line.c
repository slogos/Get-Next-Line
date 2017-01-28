/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 14:46:58 by slogos            #+#    #+#             */
/*   Updated: 2016/10/31 14:46:59 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static void			link_cut(t_list *list, int len)
{
	char			*str;

	str = list->content;
	list->content = ft_strdup(list->content + len);
	free(str);
}

static void			link_join(t_list *list, char *buf, int len)
{
	char			*str;

	str = list->content;
	list->content = ft_strnjoin(list->content, buf, len);
	free(str);
}

static int			line_linked(char *str, char **line)
{
	int				i;

	i = 0;
	if (ft_strchr(str, '\n'))
	{
		while (str[i] && str[i] != '\n')
			i++;
	}
	else
		i = ft_strlen(str);
	*line = ft_strndup(str, i);
	if (str[i] == '\n')
		return (++i);
	return (i);
}

static t_list		*fd_list(t_list **list, int fd)
{
	t_list			*tmp;

	tmp = *list;
	while (tmp)
	{
		if (fd == (int)tmp->content_size)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	tmp->next = *list;
	*list = tmp;
	return (tmp);
}

int					get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*list = NULL;
	t_list			*tmp;
	int				ret;
	int				len;

	if (fd < 0 || line == NULL || read(fd, buf, 0) || BUFF_SIZE <= 0)
		return (-1);
	tmp = list;
	list = fd_list(&tmp, fd);
	while (!ft_strchr(list->content, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
		link_join(list, buf, ret);
	len = line_linked((char*)list->content, line);
	link_cut(list, len);
	list = tmp;
	if (len > 0)
		return (1);
	else
		return (0);
}
