/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bandrade <bandrade@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/15 14:28:35 by bandrade      #+#    #+#                 */
/*   Updated: 2026/05/20 12:26:37 by bandrade      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	// Test 1: Reading from a file line by line
	// ----------------------------------------
	// This test checks the normal behavior of get_next_line().
	// It opens a file ("test.txt"), reads each line one at a time,
	// prints the line, frees the allocated memory, and continues
	// until get_next_line() returns NULL (end of file).
	//
	// Useful for testing:
	// - Correct line-by-line reading
	// - Memory allocation/freeing
	// - EOF handling
	// - Multiple consecutive calls
	// - Behavior with BUFFER_SIZE
	//
	// sleep(1) is only used to slow down execution so you can
	// observe the output more clearly.

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

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;

	// Test 2: Invalid file descriptor
	// -------------------------------
	// This test checks how get_next_line() behaves when receiving
	// an invalid file descriptor (-1).
	//
	// Expected behavior:
	// - The function should return NULL immediately.
	// - It should NOT crash or cause undefined behavior.
	//
	// Useful for testing:
	// - Error handling
	// - Protection against invalid input
	// - Defensive programming

	line = get_next_line(-1);
	if (!line)
		printf("NULL returned correctly\n");
	else
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;

	// Test 3: Reading from standard input (stdin)
	// --------------------------------------------
	// This test reads user input directly from the terminal using
	// file descriptor 0 (stdin).
	//
	// The program waits for the user to type something and press ENTER.
	// Each line is read with get_next_line() and printed back.
	//
	// Useful for testing:
	// - Reading from stdin
	// - Interactive input
	// - Dynamic input handling
	// - Behavior without files
	//
	// To stop the program:
	// - Press Ctrl+D (EOF) on Linux/macOS
	// - Press Ctrl+Z then ENTER on Windows

	printf("Type something:\n");

	line = get_next_line(0);
	while (line)
	{
		printf("You typed: [%s]\n", line);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}
