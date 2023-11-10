/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:27:40 by lgandari          #+#    #+#             */
/*   Updated: 2023/11/10 15:54:42 by lgandari         ###   ########.fr       */
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

int	main(void)
{
	char	*line;
	int	fd[7];
	int	i;

	i = 0;
	while (i < 7)
	{
		fd[i] = open(files[i], O_RDONLY);
		i++;
	}
	i = 0;
	while (i < 7)
	{
		while((line = get_next_line(fd[i])))
			printf("%s", line);
		i++;
	}
	return (0);
}
