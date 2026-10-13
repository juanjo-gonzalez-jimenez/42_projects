*This project has been created as part of the 42 curriculum by juan-jos.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf()`. The goal of the project is to build a static library, `libftprintf.a`, that exposes a function with the following prototype:

```c
int ft_printf(char const *, ...);
```

Like the original, it writes a formatted string to the standard output and returns the number of characters printed. The project is a practical introduction to **variadic functions** (`<stdarg.h>`), to **parsing a format string**.

### Supported conversions

| Specifier | Description |
|---|---|
| `%c` | A single character |
| `%s` | A string (prints `(null)` if the pointer is `NULL`) |
| `%p` | A `void *` pointer in hexadecimal, prefixed with `0x` (prints `(nil)` if `NULL`, as on Linux) |
| `%d` | A signed decimal integer |
| `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned integer in lowercase hexadecimal |
| `%X` | An unsigned integer in uppercase hexadecimal |
| `%%` | A percent sign |

### Project constraints

- Only these functions are used: `write`, `va_start`, `va_arg`, `va_end`. (`malloc`, `free` and `va_copy` are authorized but were not needed.)
- The original `printf()` buffer management is **not** reimplemented: output is written as it is processed.
- The library is built with `ar`; `libtool` is not used.
- libft is not used.

### Project structure

```
.
├── Makefile
├── ft_printf.h         Prototypes and includes
├── ft_printf.c         ft_printf() and the conversion dispatcher
└── ft_printf_utils.c   Printers: char, string, signed number, base, pointer
```

| Function | Role |
|---|---|
| `ft_printf` | Walks through the format string, prints plain text and delegates every `%` to the dispatcher. Returns the total number of characters written. |
| `ft_handle_format` | Receives the letter after the `%`, fetches the matching argument with `va_arg` using the correct type, and calls the right printer. |
| `ft_print_char` | Writes one character. |
| `ft_print_str` | Writes a string, handling `NULL`. |
| `ft_print_nmbr` | Writes a signed `int` (`%d`, `%i`). |
| `ft_print_base` | Writes an unsigned number in any base, using a digit string (`%u`, `%x`, `%X`, and the digits of `%p`). |
| `ft_print_p` | Writes a pointer: `0x` prefix plus its address in hexadecimal. |

## Instructions

### Compilation

The library is compiled with `cc` and the flags `-Wall -Wextra -Werror`.

```bash
make        # builds libftprintf.a at the root of the repository
make clean  # removes the object files
make fclean # removes the object files and libftprintf.a
make re     # rebuilds everything from scratch
```

Running `make` a second time without changing any file does not relink.

### Usage in your own program

Include the header and link against the library:

```c
#include "printf.h"

int main(void)
{
	int	len;

	len = ft_printf("Hello %s, you are %d years old!\n", "world", 42);
	ft_printf("%d characters were printed\n", len);
	return (0);
}
```

```bash
make
cc main.c -L. -lftprintf -o demo
./demo
```
### Behavior notes

- A lone `%` at the end of the format string (for example `"100%"`) returns `-1`. The original behavior is undefined in this case, and this mirrors what glibc typically reports.
- `%p` with a `NULL` pointer prints `(nil)`, which is the behavior of the original `printf()` on Linux. On macOS it would print `0x0`.
- Unknown conversion letters print nothing and consume no argument.

## Resources

### References

- `man 3 printf`: description of the original function and its conversions
- `man 3 stdarg`: `va_start`, `va_arg`, `va_end`, `va_copy`
- The 42 Norm, checked with `norminette`
- [Stack Overflow](https://stackoverflow.com/questions)

### Use of AI

It was used for:

- **Understanding the subject:** explaining what the requirements mean, how variadic functions work, why `va_arg` must request the type the caller passed, and why `va_list` is passed by pointer.
- **Planning:** discussing the file organization, the split into a dispatcher and printers, and the choice of a generic base converter.
- **Code review:** reviewing code written by me and pointing out possible bugs.
