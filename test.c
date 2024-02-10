/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:54:33 by lgandari          #+#    #+#             */
/*   Updated: 2024/02/10 17:08:27 by lgandari         ###   ########.fr       */
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

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	if (*nptr == '+' || *nptr == '-')
		return (0);
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res * sign);
}

// Prueba con un fd
void	test1(int test)
{
	char	*line;
	int	fd;

	fd = open(files[test], O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("%s", line);
}

// Prueba por stdin
void	test2(void)
{
	char	*line;
	int	fd;

	fd = 0;
	while ((line = get_next_line(fd)))
		printf("%s", line);
}

// Programa principal
int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else if (argc == 1)
		test2();
	else
		test1(ft_atoi(argv[1]));
	return (0);
}
