*This project has been created as part of the 42 curriculum by juan-jos.*

# Libft

## Description

**Libft** is the first project of the 42 common core. The goal is to build
my own C library (`libft.a`) containing a set of functions that will be reused in later projects.

This project is about understanding how the standard C functions actually work,
doing them from scratch, and learning how to use them. The library is meant to be used throughout the cursus, so it is norm-compliant and easy to extend.

The library is split in three parts:

1. **Libc functions**: re-implementations of standard functions, same
   prototype and behavior stated in the manual, prefixed with `ft_`.
2. **Additional functions**: useful utilities that are not in libc, or are
   in it in a different form.
3. **Linked lists**: basic functions to manipulate lists using the `t_list`
   structure.

## Instructions

### Compilation

```bash
make        # builds libft.a
make clean  # removes object files
make fclean # removes object files and libft.a
make re     # fclean + all
```

### Usage

Include the header and you are good to go to use the functions inside the library:

```c
#include "libft.h"
```

### Project structure

```
.
├── Makefile
├── libft.h
├── ft_*.c
└── README.md
```

## Functions

### Part 1: Libc functions

| Category | Functions |
|----------|-----------|
| Character checks | `ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint` |
| Character conversion | `ft_toupper` `ft_tolower` |
| Strings | `ft_strlen` `ft_strlcpy` `ft_strlcat` `ft_strchr` `ft_strrchr` `ft_strncmp` `ft_strnstr` `ft_strdup` |
| Memory | `ft_memset` `ft_bzero` `ft_memcpy` `ft_memmove` `ft_memchr` `ft_memcmp` `ft_calloc` |
| Conversion | `ft_atoi` |

Notes:
- Character classification functions return `1` if true and `0` otherwise.
- `ft_calloc`: if `nmemb` or `size` is `0`, it returns a unique pointer that
  can be successfully passed to `free()`.
- `restrict` must not appear in prototypes and `-std=c99` must not be used.

### Part 2: Additional functions

<!-- TODO: verify against your subject (this section was not in the provided excerpt). -->

| Function | Description |
|----------|-------------|
| `ft_substr` | Returns a substring from a string. |
| `ft_strjoin` | Concatenates two strings into a new one. |
| `ft_strtrim` | Trims a set of characters from both ends of a string. |
| `ft_split` | Splits a string using a character as delimiter. |
| `ft_itoa` | Converts an integer to a string. |
| `ft_strmapi` | Applies a function to each character, returning a new string. |
| `ft_striteri` | Applies a function to each character (by index) in place. |
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

### Part 3: Linked lists

<!-- TODO: verify against your subject (this section was not in the provided excerpt). -->

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Description |
|----------|-------------|
| `ft_lstnew` | Creates a new node. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstsize` | Counts the nodes in the list. |
| `ft_lstlast` | Returns the last node. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstdelone` | Deletes a node using a given `del` function. |
| `ft_lstclear` | Deletes and frees a node and all that follow it. |
| `ft_lstiter` | Applies a function to the content of each node. |
| `ft_lstmap` | Creates a new list by applying a function to each node. |

## Resources

- `man` pages for each reimplemented function (`man 3 strlen`, etc.)
- [The C Programming Language (K&R)](https://en.wikipedia.org/wiki/The_C_Programming_Language)
- [The 42 Norm](https://github.com/42School/norminette)
- <!-- Add any tutorials, articles or videos you used -->

### Use of AI

<!-- Be honest and specific: state which tasks AI was used for (e.g. understanding a concept,
     explaining an error, reviewing edge cases) and for which parts it was NOT used.
     Per the 42 AI guidelines, the code itself should be your own work and you must be able
     to explain every line during peer evaluation. -->

AI was used for: <!-- e.g. clarifying concepts such as memory overlap in memmove -->

AI was not used for: <!-- e.g. writing the function implementations -->
