/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lganda <lgandari@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:08:25 by lgandari          #+#    #+#             */
/*   Updated: 2023/11/04 17:33:55 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_content(int fd, char **stash)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*old;
	int		rd;

	buffer[BUFFER_SIZE] = 0;
	rd = 1;
	while (rd > 0 && ft_strchr(buffer, '\n') == NULL)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == 0)
			return (0);
		else if (rd < 0)
			return (-1);
		else
		{
			buffer[rd] = 0;
			old = *stash;
			*stash = ft_strjoin((*stash), buffer);
			free(old);
			if (*stash == NULL)
				return (-1);
		}
	}
	return (0);
}

static char	*get_line(char **stash)
{
	char	*result;
	char	*old;
	int		len;
	int		i;

	if (**stash == 0)
		return (NULL);
	len = 0;
	while ((*stash)[len] != '\0' && (*stash)[len] != '\n')
		len++;
	if ((*stash)[len] == '\n')
		len++;
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while ((*stash)[++i] != '\0' && i < len)
		result[i] = (*stash)[i];
	old = *stash;
	*stash = ft_strdup((*stash) + len);
	if (*stash == NULL)
		return (free_dptr(&result), free_dptr(&old), NULL);
	return (free_dptr(&old), result);
}

void	*free_dptr(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*result;
	int			rd;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rd = 0;
	if (!stash || (*stash != '\0' && !ft_strchr(stash, '\n')))
		rd = read_content(fd, &stash);
	if (rd < 0)
	{
		free_dptr(&stash);
		return (stash);
	}
	result = NULL;
	if (stash && *stash)
		result = get_line(&stash);
	if (!result)
	{
		free_dptr(&stash);
		return (NULL);
	}
	if (stash && !(*stash))
		free_dptr(&stash);
	return (result);
}
