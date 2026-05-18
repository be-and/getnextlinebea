*This project has been created as part of the 42 curriculum by bandrade.*

## DESCRIPTION

Get Next Line consists of implementing a function capable of reading and returning
one line at a time from a file descriptor.

The goal of this project is to understand how file reading works internally in C,
with a focus on static variables, memory management, dynamic allocation, and buffered input using `read`.

The function must:
- read from a file descriptor progressively
- return one line per function call
- preserve unread content between calls
- handle different `BUFFER_SIZE` values correctly
- work both with files and standard input

This implementation is designed to be efficient, modular, and reusable in future C projects.

## INSTRUCTIONS

### Compilation

Compile the project with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c
```

You can replace `42` with any buffer size:

```bash
-D BUFFER_SIZE=1
-D BUFFER_SIZE=9999
```

The project is compiled using the following flags:

```bash
-Wall -Wextra -Werror
```

## TESTING

A separate `main.c` file can be used for testing purposes.

It allows testing:
- regular files
- empty files
- files without a final newline
- standard input
- different `BUFFER_SIZE` values

Example:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c && ./a.out
```

Memory leaks can be checked with:

```bash
valgrind --leak-check=full ./a.out
```

## OVERVIEW

The project is divided into several parts:

- reading and buffering
- line extraction
- remaining content storage
- utility functions

## Reading & Buffering

### `read_and_save`

Reads from the file descriptor into a temporary buffer and appends the content to the static variable (`stash`) until a newline or EOF is found.

This prevents unnecessary reads and keeps unread data available for the next function call.

## Line Extraction

### `extract_line`

Extracts the current line from `stash`.

If a newline exists, the returned line includes the `\n` character.
If EOF is reached without a newline, the remaining content is returned as the final line.

## Remaining Content Handling

### `save_rest`

After extracting the current line, the remaining unread content is saved back into `stash`.

This allows the function to continue reading correctly on the next call.

## Utility Functions

The project includes custom utility functions:

- `ft_strlen`
- `ft_strdup`
- `ft_strchr`
- `ft_strjoin`
- `ft_substr`

These functions are used for:
- string length calculation
- memory allocation
- newline detection
- string concatenation
- line extraction

## Algorithm & Design

The implementation follows a progressive reading strategy:

1. Allocate a temporary buffer
2. Read from the file descriptor
3. Append the read content to `stash`
4. Stop reading when a newline or EOF is found
5. Extract the current line
6. Save the remaining content
7. Return the extracted line

### Static Variable

A static variable is used to preserve unread data between function calls.

This is essential because the function only returns one line at a time while keeping track of the remaining content internally.

### Memory Management

Special attention was given to:
- avoiding memory leaks
- handling allocation failures
- freeing unused memory
- preventing invalid accesses and crashes

## Edge Cases

The implementation handles:

- empty files
- invalid file descriptors
- files without a final newline
- very small or very large `BUFFER_SIZE` values
- standard input reading

## RESOURCES

Support came from:
- GeeksforGeeks
- Stack Overflow
- Articles related to static variables and file descriptors

### AI Usage

AI was used as a support tool to:
- better understand the use of static variables
- review memory management
- write the README structure