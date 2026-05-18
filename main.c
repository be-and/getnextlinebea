/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/15 14:28:35 by bandrade      #+#    #+#                 */
/*   Updated: 2026/05/18 12:45:42 by bandrade      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		sleep(1);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

// #include <stdio.h>
// #include "get_next_line.h"

// int	main(void)
// {
// 	char	*line;

// 	line = get_next_line(-1);
// 	if (!line)
// 		printf("NULL returned correctly\n");
// 	else
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	return (0);
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include "get_next_line.h"

// int	main(void)
// {
// 	char	*line;

// 	printf("Type something:\n");

// 	line = get_next_line(0);
// 	while (line)
// 	{
// 		printf("You typed: [%s]\n", line);
// 		free(line);
// 		line = get_next_line(0);
// 	}
// 	return (0);
// }