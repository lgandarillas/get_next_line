# get_next_line
- [get_next_line | 42 School] A utility for reading and processing input from a file or stream, one line at a time.
- [Rank 01] 42 Common Core
## Description
Function that returns the line read from a file descriptor.
- Repeatedly calling **get_next_line** allows reading the content of the file pointed to by the file descriptor line by line until the end.
- The function should return the line just read. If there's nothing more to read or an error occurs, it should return NULL.
- Can read from both a file and from stdin.
- The returned line should end with the newline character ('\n'), except when the end of the file is reached, and it does not end with a newline character.
## Functions
### ```char	*get_next_line(int fd);```
- The **get_next_line** function is designed to read a line from a file descriptor (fd) and return it as a dynamically allocated string. It uses a static variable **stash** to keep track of the remaining data from previous reads, allowing it to handle cases where a line is not fully contained within a single read operation.
- If there is no content in the stash or no newline character is found in the stash, it calls **read_content** to read more content from the file.
- Calls **get_line** to extract a line from the stash.
- Frees memory if an error occurs or the end of the file is reached.
- Returns the extracted line on success or NULL if an error occurs.
### ```static int	read_content(int fd, char **stash);```
- Reads content from the file descriptor (fd) into a buffer.
- Continues reading until a newline character is encountered or the end of the file is reached.
- Dynamically allocates memory to append the buffer content to the existing stash (the accumulated content from previous reads).
- Returns 0 on success, -1 on read error, and 0 if the end of the file is reached.
### ```static char	*get_line(char **stash);```
- Extracts a line from the stash by finding the length of the line.
- Allocates memory for the line and copies it into the new buffer.
- Updates the stash to exclude the extracted line.
- Returns the extracted line.
### ```void	*free_dptr(char **str);```
- Frees the memory pointed to by the input double pointer (str) and sets it to NULL.
### Note
This implementation uses various utility functions like **ft_strchr**, **ft_strjoin**, **ft_strdup**, and **ft_calloc**.
