/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:37:23 by hkubo             #+#    #+#             */
/*   Updated: 2020/11/26 09:16:26 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "libft.h"
#include <ctype.h>


int main()
{
    // ft_strlen
	char const word[10] = "afafaafa";
    printf("strlen: %ld\n", strlen(word));
	printf("ft_strlen: %d\n", ft_strlen(word));

    // ft_strlcpy
    char dst[10];
	char src[10] = "abcde";
	size_t n = 1;
    printf("strlcpy: %lu\n", strlcpy(dst, src, n)); 
	printf("strlcpy: %s\n", dst);
	printf("ft_strlcpy: %zu\n", ft_strlcpy(dst, src, n)); 
	printf("ft_strlcpy: %s\n", dst);
    // printf("strlcpy: %lu\n", strlcpy(NULL, NULL, 10));
	// printf("strlcpy: %s\n", dst);
    // printf("ft_strlcpy: %zu\n", ft_strlcpy(NULL, NULL, 10)); 
	// printf("ft_strlcpy: %s\n", dst);

    // ft_strlcat
    char cat_dst[20] = "aaabbb";
	const char cat_src[10] = "cccddd";
    char ft_dst[20] = "aaabbb";
	const char ft_src[10] = "cccddd";

    size_t dstsize = 11;
    printf("strlcat: %lu\n", strlcat(cat_dst, cat_src, dstsize));
    printf("strlcat: %s\n", cat_dst);
    printf("ft_strlcat: %ld\n", ft_strlcat(ft_dst, ft_src, dstsize));
    printf("ft_strlcat: %s\n", ft_dst);

    // ft_memset
    char a[20] = "0123456789";
    char b[20] = "0123456789";
    memset(a+2, '*', 5);
    ft_memset(b+2, '*', 5);
    printf("memset: %s\n", a);
    printf("ft_memset: %s\n", b);
    
    // ft_bzero
    int i = 0;
    int j = 0;
    char ft_str[5] = "11111";
    char str[5] = "11111";
    bzero(str+1, 2);
    ft_bzero(ft_str+1, 2);
    printf("bzero: ");
    while (j < 5)
    {
        printf("%c, ", str[j]);
        j++;
    }
    printf("\n");
    printf("ft_bzero: ");
    while (i < 5)
    {
        printf("%c, ", ft_str[i]);
        i++;
    }
    printf("\n");
    
    // ft_memcpy
    char ft_mem_dst[20] = {0xff, 0xff, 0xff, 0xff, 0xff};
    char ft_mem_src[20] = {0x12, 0x34, 0x56, 0x78};
    char mem_dst[20] = {0xff, 0xff, 0xff, 0xff, 0xff};
    char mem_src[20] = {0x12, 0x34, 0x56, 0x78};
    size_t n_mem = 3;
    memcpy(mem_dst, mem_src, n_mem);
    ft_memcpy(ft_mem_dst, ft_mem_src, n_mem);
    printf("memcpy: %x %x %x %x %x\n", mem_dst[0], mem_dst[1], mem_dst[2], mem_dst[3], mem_dst[4]);
    printf("ft_memcpy: %x %x %x %x %x\n", ft_mem_dst[0], ft_mem_dst[1], ft_mem_dst[2], ft_mem_dst[3], ft_mem_dst[4]);
    // memcpy(((void *)0), ((void *)0), 3);
    // ft_memcpy(((void *)1), ((void *)0), 3);

    // ft_memccpy
    char ccpy_dst[20] = {1,2,3,4,5};
    char ccpy_src[20] = {6,7,8,9,10};
    char ft_ccpy_dst[20] = {1,2,3,4,5};
    char ft_ccpy_src[20] = {6,7,8,9.10};
    int ccpy = 9;
    size_t n_ccpy = 5;
    printf("memccpy: %p\n", memccpy(ccpy_dst, ccpy_src, ccpy, n_ccpy));
    printf("ft_memccpy: %p\n", ft_memccpy(ft_ccpy_dst, ft_ccpy_src, ccpy, n_ccpy));

    // ft_memmmove
    char s1_1[10] = {'\0'};
    char s1_2[] = "123456789";
    char s1_3[] = "123456789";
    char s1_final[] = "abcdefghijklmnopqrstu";
    char ft_s1_1[10] = {'\0'};
    char ft_s1_2[] = "123456789";
    char ft_s1_3[] = "123456789";
    char ft_s1_final[] = "abcdefghijklmnopqrstu";
    char s2[] = "copy!";
    memmove(s1_1, s2, 5);
    memmove(s1_2, s2, 5);
    memmove(s1_3, s1_3 + 3, 3);
    memmove(s1_final+5, s1_final, 10);
    ft_memmove(ft_s1_1, s2, 5);
    ft_memmove(ft_s1_2, s2, 5);
    ft_memmove(ft_s1_3, ft_s1_3 + 3, 3);
    ft_memmove(ft_s1_final+5, ft_s1_final, 10);
    memmove(NULL, NULL, 0);
    ft_memmove(NULL, NULL, 0);
    printf("memmove_1: %s\n", s1_1);
    printf("memmove_2: %s\n", s1_2);
    printf("memmove_3: %s\n", s1_3);
    printf("memmove_4: %s\n", s1_final);
    printf("ft_memmove_1: %s\n", ft_s1_1);
    printf("ft_memmove_2: %s\n", ft_s1_2);
    printf("ft_memmove_3: %s\n", ft_s1_3);
    printf("ft_memmove_4: %s\n", ft_s1_final);

    // ft_memchr
    char buf[] = "AB\0CD5EFGH";
    char *ch;
    char *ft_ch;
    ch = (char *)memchr(buf, '5', sizeof(buf));
    if (ch != NULL) {
        printf("memchr: %s\n", ch);
    } else {
        printf("検索文字が見つかりませんでした");
    }
    ft_ch = (char *)memchr(buf, '5', sizeof(buf));
    if (ft_ch != NULL) {
        printf("ft_memchr: %s\n", ft_ch);
    } else {
        printf("検索文字が見つかりませんでした");
    }
    
    // ft_memcmp
    char buf1[] = "\0abc\0de";
    char buf2[] = "\0abc\0de";
    char buf3[] = "\0abcdef";
    char buf4[] = "\0abccef";
    printf("memcmp: %d\n", memcmp(buf1, buf2, 7));
    printf("memcmp: %d\n", memcmp(buf1, buf3, 7));
    printf("memcmp: %d\n", memcmp(buf3, buf4, 7));
    printf("ft_memcmp: %d\n", ft_memcmp(buf1, buf2, 7));
    printf("ft_memcmp: %d\n", ft_memcmp(buf1, buf3, 7));
    printf("ft_memcmp: %d\n", ft_memcmp(buf3, buf4, 7));
    
    // ft_strchr
    char chr_str[] = "abcdefg";
    char chr_str2[] = "abc\0efg";
    int c_1 = 'c';
    int c_2 = '\0';
    printf("strchr: %s\n", strchr(chr_str, c_1));
    printf("ft_strchr: %s\n", ft_strchr(chr_str, c_1));
	printf("strchr: %s\n", strchr(chr_str2, c_2));
    printf("ft_strchr: %s\n", ft_strchr(chr_str2, c_2));

    // ft_strrchr
    char rrchr_str[] = "1A12B23C34D4";
    int rrchr = '3';
    int rrchr2 = '\0';
    printf("strrchr: %s\n", strrchr(rrchr_str, rrchr));
    printf("ft_strrchr: %s\n", ft_strrchr(rrchr_str, rrchr));
    printf("strrchr: %s\n", strrchr(rrchr_str, rrchr2));
    printf("ft_strrchr: %s\n", ft_strrchr(rrchr_str, rrchr2));    

    // ft_strncmp
    char ncmp_str[] = "ABC";
    printf("ABC: ABD   = %d\n", strncmp(ncmp_str, "ABD", 2));
    printf("ft ABC: ABD   = %d\n", ft_strncmp(ncmp_str, "ABD", 2));
    printf("ABC: ABC   = %d\n", strncmp(ncmp_str, "ABC", 2));
    printf("ft ABC: ABC   = %d\n", ft_strncmp(ncmp_str, "ABC", 2));
    printf("ABC: AAA   = %d\n", strncmp(ncmp_str, "AAA", 2));
    printf("ft ABC: AAA   = %d\n", ft_strncmp(ncmp_str, "AAA", 2));
    printf("ABC: ABCD  = %d\n", strncmp(ncmp_str, "ABCD", 2));
    printf("ft ABC: ABCD  = %d\n", ft_strncmp(ncmp_str, "ABCD", 2));
    printf("ABC: AB    = %d\n", strncmp(ncmp_str, "AB", 2));
    printf("ft ABC: AB    = %d\n", ft_strncmp(ncmp_str, "AB", 2));
    printf("ABC: B     = %d\n", strncmp(ncmp_str, "B", 2));
    printf("ft ABC: B     = %d\n", ft_strncmp(ncmp_str, "B", 2));
    printf("ABC: A     = %d\n", strncmp(ncmp_str, "A", 2));
    printf("ft ABC: A     = %d\n", ft_strncmp(ncmp_str, "A", 2));
    printf("ft_strncmp: %d\n", ft_strncmp("", "a", 1));

    // ft_strnstr
    const char *big = "Foo Bar Baz";
    const char *little = "Bar";
    printf("strnstr: %s\n", strnstr(big, little, 7));
    printf("ft_strnstr: %s\n", ft_strnstr(big, little, 7));
    
    // ft_atoi
    char atoi_str[] = "99999999999999999999999999";
    printf("atoi: %d\n", atoi(atoi_str));
    printf("ft_atoi: %d\n", ft_atoi(atoi_str));

    // ft_isalpha
    char alpha_str1 = 'w';
    char alpha_str2 = '3';
    printf("isalpha: %d\n", isalpha(alpha_str1));
    printf("ft_isalpha: %d\n", ft_isalpha(alpha_str1));
    printf("is_alpha: %d\n", isalpha(alpha_str2));
    printf("ft_isalpha: %d\n", ft_isalpha(alpha_str2));
    
    // ft_isdigit
    printf("isdigit: %d\n", isdigit('9'));
    printf("ft_isdigit: %d\n", ft_isdigit('9'));
    printf("isdigit: %d\n", isdigit('a'));
    printf("ft_isdigit: %d\n", ft_isdigit('a'));

    // ft_isalnum
    printf("isalnum: %d\n", isalnum('a'));
    printf("ft_isalnum: %d\n", ft_isalnum('a'));
    printf("isalnum: %d\n", isalnum('3'));
    printf("ft_isalnum: %d\n", ft_isalnum('3'));
    printf("isalnum: %d\n", isalnum('%'));
    printf("ft_isalnum: %d\n", ft_isalnum('%'));

    // ft_isascii
    printf("isascii: %d\n", isascii('~'));
    printf("ft_isascii: %d\n", ft_isascii('~'));
    printf("isascii: %d\n", isascii('あ'));
    printf("ft_isascii: %d\n", ft_isascii('あ'));

    // ft_isprint
    printf("isprint: %d\n", isprint('~'));
    printf("ft_isprint: %d\n", ft_isprint('~'));

    // ft_toupper
    printf("toupper: %c\n", toupper('A'));
    printf("ft_toupper: %c\n", ft_toupper('A'));
    printf("toupper: %c\n", toupper('a'));
    printf("ft_toupper: %c\n", ft_toupper('a'));

    // ft_tolower
    printf("tolower: %c\n", tolower('Z'));
    printf("ft_tolower: %c\n", ft_tolower('Z'));
    printf("tolower: %c\n", tolower('z'));
    printf("ft_tolower: %c\n", ft_tolower('z'));

    // ft_calloc
    int *ptr;
    int *ft_ptr;
    int calloc_i;
    // ptr = (int *)calloc(10, sizeof(int));
    // ft_ptr = (int *)ft_calloc(10, sizeof(int));
    ptr = calloc(1, 1);
    ft_ptr = ft_calloc(1, 1);
    if (!ptr) {
        printf("メモリが確保できません\n");
        exit(EXIT_FAILURE);
    }
    if (!ft_ptr) {
        printf("メモリが確保できません\n");
        exit(EXIT_FAILURE);
    }
    for (calloc_i = 0; calloc_i < 10; calloc_i++) {
        printf("calloc:%d ", ptr[calloc_i]);
        printf("ft_calloc:%d\n", ft_ptr[calloc_i]);
        calloc_i++;
    }
    free(ptr);
    free(ft_ptr);

    // ft_strdup
    char dup_str[256] = "this is a normal test";
    char *p;
    char *ft_p;
    
    p = strdup(dup_str);
    ft_p = ft_strdup(dup_str);
    p[0] = '*';
    ft_p[0] = '*';
    printf("コピー前: %s\n", dup_str);
    printf("コピー後: %s\n", p);
    printf("コピー後: %s\n", ft_p);
    free(p);
    free(ft_p);
    
    // ft_substr
    printf("ft_substr: %s\n", ft_substr("i just want this part #############", 5, 10));

    // ft_strjoin
    printf("ft_strjoin: %s\n", ft_strjoin("abc", "def"));
    printf("ft_strjoin: %s\n", ft_strjoin("\0", "\0"));

    // ft_strtrim
    printf("ft_strtrim: %s\n", ft_strtrim("abcdeaba", "ab"));

    // ft_split
    char **ans_ptr1;
    char **ans_ptr2;
    int split_i;
    ans_ptr1 = ft_split("split  ||this|for|me|||||!|", '|');
    ans_ptr2 = ft_split("      split       this for   me  !       ", ' ');
    split_i = 0;
    while (ans_ptr1[split_i] != 0) {
        printf("ft_split1: %s11\n", ans_ptr1[split_i]);
        split_i++;
    }
    split_i = 0;
    while (ans_ptr2[split_i] != 0) {
        printf("ft_split2: %s\n", ans_ptr2[split_i]);
        split_i++;
    }

    // ft_itoa
    int i_a1 = 32;
    int i_a2 = -32;
    int i_a3 = 0;
    int i_a4 = -2147483648;
    printf("ft_itoa1: %s\n", ft_itoa(i_a1));
    printf("ft_itoa2: %s\n", ft_itoa(i_a2));
    printf("ft_itoa3: %s\n", ft_itoa(i_a3));
    printf("ft_itoa4: %s\n", ft_itoa(i_a4));
    
    // ft_strmapi
    // 例が思いつかないので一旦保留

    // ft_putchar_fd
    char fd_chr = 'c';
    int fd_i = 1;
    ft_putchar_fd(fd_chr, fd_i);
    printf(": ft_putchar_fd\n");

    // ft_putstr_fd
    char *s = "abcde";
    int fd_put_i = 1;
    ft_putstr_fd(s, fd_put_i);
    printf(": ft_putstr_fd\n");

    // ft_putendl_fd
    char *s_endl = "abcde";
    int fd_endl_i = 1;
    ft_putendl_fd(s_endl, fd_endl_i);
    printf("ft_putendl_fd\n");

    // ft_putnbr_fd
    int nbr_1 = 0;
    int nbr_2 = -24234;
    int nbr_3 = -2147483648;
    int fd_nbr = 1;
    ft_putnbr_fd(nbr_1, fd_nbr);
    printf(": ft_putnbr_fd1\n");
    ft_putnbr_fd(nbr_2, fd_nbr);
    printf(": ft_putnbr_fd2\n");
    ft_putnbr_fd(nbr_3, fd_nbr);
    printf(": ft_putnbr_fd3\n");
    
    return 0;
}

// gcc test.c -o test -L. -lft -lbsd