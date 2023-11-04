/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:54:33 by lgandari          #+#    #+#             */
/*   Updated: 2023/11/04 23:54:14 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

const char *files[] = {
"files/1_One_line.txt",
"files/2Lines with jumps.txt",
"files/3Lines with jumps too.txt",
"files/4empty.txt",
"files/5Jumps.txt",
"files/TheLordOfTheRings.txt",
"files/el_quijote.txt",
NULL
};

int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	line = NULL;
	i = 0;
	while (files[i] != NULL)
	{
		fd = open(files[i], O_RDONLY);
		while ((line = get_next_line(fd)))
		{
			printf("%s\n", line);
			i++;
		}
		close(fd);
	}
	return (0);
}

/*
int	main(void)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = NULL;
	while (files[j] != NULL)
	{
		fd = open(files[j], O_RDONLY);
		while ((line = get_next_line(fd)))
		{
			printf("%s\n", line);
			i++;
		}
		j++;
	}
	close(fd);
	system("leaks a.out");
	return (0);
}
*/
