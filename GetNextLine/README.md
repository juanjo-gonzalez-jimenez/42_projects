*This project has been created as part of the 42 curriculum by juan-jos.*

# get_next_line

## Description

`get_next_line` is a C function that reads a file descriptor **one line at a time**. Each call returns the next line, including its trailing `\n` (except for the last line of a file that does not end with one), and returns `NULL` when there is nothing left to read or when an error occurs.

The goal of the project is to learn how file descriptors and the `read` system call work, how to manage dynamically allocated memory without leaks, and how to keep state between calls with a `static` variable.

```c
char *get_next_line(int fd);
```

**Allowed functions:** `read`, `malloc`, `free`.
**Forbidden:** `libft`, `lseek`, global variables.

### Bonus

The bonus version:

- uses **a single static variable**
- Manage **several file descriptors at the same time**. You can alternate calls between fd 3, 4 and 5 and each one keeps its own reading state, without returning a line that belongs to another descriptor.

## Instructions

### Compilation

The reading buffer size is set at compile time with `-D BUFFER_SIZE=n`. If the flag is not given, a default value (42) is defined in the header.

Mandatory part:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

Bonus part:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c
```

`main.c` and `main_bonus.c` are personal test programs that are not part of the submission: the project has no `main` of its own. Include the matching header (`get_next_line.h` or `get_next_line_bonus.h`) in the test program.

### Usage

```c
int     fd = open("file.txt", O_RDONLY);
char    *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

The caller is responsible for freeing every returned line. The function can also read from standard input (`fd` 0).

## Algorithm

### Idea

`read` returns raw chunks of at most `BUFFER_SIZE` bytes, not lines. A chunk can contain no newline, exactly one line, or a line plus the beginning of the next one. Bytes already read from a file descriptor cannot be "put back" (and `lseek` is forbidden), so the extra characters read past the newline have to be saved for the next call. That is why the function keeps a **static `stash`**: a heap-allocated string that survives between calls and holds the text that has been read but not yet returned.

### Steps of each call

1. **Validate** the input: `fd < 0` or `BUFFER_SIZE <= 0` returns `NULL` immediately (bonus: also `fd >= 1024`), before anything is allocated.
2. **Read** (`reader`): while the stash does not contain a `\n` and `read` has not reported EOF, read up to `BUFFER_SIZE` bytes into a temporary heap buffer, terminate it with `'\0'` at the position returned by `read`, and append it to the stash. If the stash already contains a `\n` from a previous call, no `read` is made at all.
3. **Check** that there is something to return: a `NULL` or empty stash frees everything and returns `NULL`.
4. **Extract the line** (`extract_line`): copy everything from the start of the stash up to and including the first `\n`, or the whole stash if there is none (last line of a file without a trailing newline).
5. **Update the stash** (`new_stash`): build a new string with what comes after the newline and free the old one. If nothing is left, the stash becomes `NULL`.
6. **Return** the line. The caller owns it.

### Functions

| Function        | Role                                                                                       |
|-----------------|--------------------------------------------------------------------------------------------|
| `get_next_line` | Validates, calls the helpers in order, and keeps the static stash up to date.              |
| `reader`        | Owns the temporary buffer; reads and appends chunks until a `\n` appears or EOF is reached. |
| `extract_line`  | Builds the line to return.                                                                  |
| `new_stash`     | Builds the leftover text for the next call and frees the old stash.                         |
| `stash_checker` | Tells whether the stash contains a `\n`.                                                    |
| `stash_len`     | Length of a string, returning 0 for `NULL`.                                                 |
| `stash_join`    | Joins stash and buffer into a new string, accepts a `NULL` stash, and frees the old one.    |
| `free_null`     | Frees a pointer and returns `NULL`, so failure branches stay short.                         |

### Why this design

- **Reading as little as possible.** The read loop stops as soon as the stash contains a `\n`, as the subject requires. The file is never loaded entirely.
- **Heap buffer instead of a local array.** With a huge `BUFFER_SIZE` (for example 10000000) a local `char buf[BUFFER_SIZE]` could overflow the stack, so the buffer is allocated with `malloc`.
- **`read`'s return value drives everything.** `-1` means error (free the buffer and the stash, return `NULL`), `0` means EOF (keep the stash, since it may still hold a last line), and a positive value `n` means `n` bytes arrived. The `'\0'` is written at position `n`, never at `BUFFER_SIZE`, because `read` can return fewer bytes than requested.
- **Freeing.** Every helper that replaces the stash frees the old one after copying, and returns `NULL` on failure after freeing what it owned. `get_next_line` always assigns the helper's return value back to the static stash, so the stash is never left pointing at freed memory.

### Bonus: several file descriptors

The single static variable becomes a **static array of 1024 `char *`**, one slot per file descriptor. Every use of `stash` in `get_next_line` becomes `stash[fd]`, so each call only touches its own slot and the leftover text of one fd can never mix with another's. The helpers are identical to the mandatory ones.

## Resources

### References

- `man 2 read`, `man 2 open`, `man 2 close`, `man 3 stdin`: behavior of `read` and file descriptors.
- `valgrind` documentation and the AddressSanitizer documentation (`-fsanitize=address`) for leak and memory error detection.
- The 42 norm and `norminette`.
- Stackoverflow.

### Use of AI

AI was used for:

- **Understanding the subject:** explaining what the requirements mean and how to approach different functions.
- **Planning:** discussing the file organization, the split into a reader and other helper functions.
- **Code review:** reviewing code written by me and pointing out possible bugs.