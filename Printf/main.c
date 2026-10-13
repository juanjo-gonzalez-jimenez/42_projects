/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:30:42 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/13 16:05:30 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

//compile with this if used the makefile: cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test_printf
//compile with this: gcc -Wall -Wextra -Werror main.c ft_printf.c ft_printf_utils.c -o test_printf

int main(void)
{
    int ret1;
    int ret2;
    int a = 42;
    char *null_str = NULL;
    void *null_ptr = NULL;

    // 1. Characters (%c)
    printf("--- 1. Characters (%%c) ---\n");
    ret1 = printf("Original: [%c] [%c]\n", 'A', 'z');
    ret2 = ft_printf("Custom:   [%c] [%c]\n", 'A', 'z');
    printf("Return -> Original: %d | Custom: %d\n\n", ret1, ret2);
    
    // 2.5 Strings (%z)
    printf("--- 2. Strings (%%z) ---\n");
    ret2 = ft_printf("Custom:   [%z]\n");
    printf("Return -> Custom: %d\n\n", ret2);

    // 2. Strings (%s)
    printf("--- 2. Strings (%%s) ---\n");
    ret1 = printf("Original: [%s] [NULL: %s]\n", "Hello, 42!", null_str);
    ret2 = ft_printf("Custom:   [%s] [NULL: %s]\n", "Hello, 42!", null_ptr);
    printf("Return -> Original: %d | Custom: %d\n\n", ret1, ret2);

    // 3. Decimals and Integers (%d, %i)
    printf("--- 3. Decimals & Integers (%%d, %%i) ---\n");
    ret1 = printf("Original: [%d] [%i] [%d] [%d] [%d]\n", 42, -42, 0, INT_MAX, INT_MIN);
    ret2 = ft_printf("Custom:   [%d] [%i] [%d] [%d] [%d]\n", 42, -42, 0, INT_MAX, INT_MIN);
    printf("Return -> Original: %d | Custom: %d\n\n", ret1, ret2);

    // 4. Unsigned Integers (%u)
    printf("--- 4. Unsigned Integers (%%u) ---\n");
    ret1 = printf("Original: [%u] [%u] [%u]\n", 0, 42, UINT_MAX);
    ret2 = ft_printf("Custom:   [%u] [%u] [%u]\n", 0, 42, UINT_MAX);
    printf("Return -> Original: %d | Custom: %d\n\n", ret1, ret2);

    // 5. Hexadecimal Lowercase (%x)
    printf("--- 5. Hexadecimal Lowercase (%%x) ---\n");
    ret1 = printf("Original: [%x] [%x] [%x]\n", 0, 42, 424242);
    ret2 = ft_printf("Custom:   [%x] [%x] [%x]\n", 0, 42, 424242);
    printf("Return -> Original: %d | Custom: %d\n\n", ret1, ret2);

    // 6. Hexadecimal Uppercase (%X)
    printf("--- 6. Hexadecimal Uppercase (%%X) ---\n");
    ret1 = printf("Original: [%X] [%X] [%X]\n", 0, 42, 424242);
    ret2 = ft_printf("Custom:   [%X] [%X] [%X]\n", 0, 42, 424242);
    printf("Return -> Original: %d | Custom: %d\n\n", ret1, ret2);

    // 7. Pointers (%p)
    printf("--- 7. Pointers (%%p) ---\n");
    ret1 = printf("Original: [%p] [NULL: %p]\n", (void *)&a, (void *)NULL);
    ret2 = ft_printf("Custom:   [%p] [NULL: %p]\n", (void *)&a, (void *)NULL);
    printf("Return -> Original: %d | Custom: %d\n\n", ret1, ret2);

    // 8. Percent Sign (%%)
    printf("--- 8. Percent Sign (%%%%) ---\n");
    ret1 = printf("Original: [%%] [100%%]\n");
    ret2 = ft_printf("Custom:   [%%] [100%%]\n");
    printf("Return -> Original: %d | Custom: %d\n\n", ret1, ret2);

    // 9. Mixed Complex String
    printf("--- 9. Mixed String Test ---\n");
    ret1 = printf("Original: Char: %c, Str: %s, Dec: %d, Hex: %x, Ptr: %p, Percent: %%\n", 'X', "test", -123, 255, (void *)&a);
    ret2 = ft_printf("Custom:   Char: %c, Str: %s, Dec: %d, Hex: %x, Ptr: %p, Percent: %%\n", 'X', "test", -123, 255, (void *)&a);
    printf("Return -> Original: %d | Custom: %d\n\n", ret1, ret2);

    return (0);
}