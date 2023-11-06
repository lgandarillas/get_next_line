/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:54:33 by lgandari          #+#    #+#             */
/*   Updated: 2023/11/05 09:43:52 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

const char *files[] = {
"files/0_One_line.txt",
"files/1Lines_jumps.txt",
"files/2Lines_jumps.txt",
"files/3empty.txt",
"files/4Jumps.txt",
"files/5TheLordOfTheRings.txt",
"files/6el_quijote.txt",
NULL
};
/*
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
*/
//PROBAR INDIVIDUALMENTE
int	main(void)
{
	char	*line;
	int	fd;
	
	fd = open(files[6], O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("%s", line);
	close(fd);
	return (0);
}
