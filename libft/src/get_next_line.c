/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:12:18 by mshad             #+#    #+#             */
/*   Updated: 2021/12/08 22:12:19 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

static void	ft_strclr(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

static char	*ft_check_last(char **last, char **line)
{
	char	*ptr;

	ptr = NULL;
	if (*last != NULL)
	{
		ptr = ft_strchr(*last, '\n');
		if (ptr)
		{
			*ptr = '\0';
			ptr++;
			*line = ft_strdup(*last);
			if (*ptr)
				ft_strcpy(*last, ptr);
			else
				ft_strclr(&*last);
		}
		else
		{
			*line = ft_strdup(*last);
			ft_strclr(&*last);
		}
	}
	else
		*line = ft_strdup("");
	return (ptr);
}

static int	gnl_init(int fd, char **buf, char **line)
{
	if (!line || fd < 0 || fd > 1024 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (0);
	*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return (0);
	return (1);
}

static int	ft_check_z(char *str)
{
	if (str)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char			*buf;
	char			*ptr;
	int				n;
	static char		*last[1024];

	if (!gnl_init(fd, &buf, &(*line)))
		return (-1);
	ptr = ft_check_last(&last[fd], line);
	n = 1;
	while ((!ptr) && n)
	{
		n = read(fd, buf, BUFFER_SIZE);
		buf[n] = '\0';
		ptr = ft_strchr(buf, '\n');
		if (ptr)
		{
			*ptr++ = '\0';
			last[fd] = ft_strdup(ptr);
		}
		*line = ft_strjoin(*line, buf);
	}
	free(buf);
	return (ft_check_z(ptr));
}
