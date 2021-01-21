/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:57:31 by kiborroq          #+#    #+#             */
/*   Updated: 2021/01/21 11:55:27 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

#define OK "\033[1;32mOK\033[0m"
#define KO "\033[1;31mKO\033[0m"

#define STR_1 ""
#define STR_2 "123456789"
#define STR_3 "abcdefghjklmnopqrstuvw\0xyz"
#define STR_4 "Enjoyed give itself doubtful ham all spot girl elinor wishing for weather large apartments offence afford dependent.\nMay luckily securing. Age cannot material poor conveying held produce true bachelor off temper instrument find plan. Summer belonging travelling paid post. Name season denote occasional entreaties extensive smiling garden existence margaret favourite manners humoured get oh. Apartments account collected stuff picture drew opinion greatly fancy indeed enjoyment.\nGrave friend position. Extent ham side drew spoil extent friends felicity at. Distrusts expect limits so share keeps then upon body before additions talked married easy perceived performed. Addition affection chiefly horrible estate tried lovers first wife matter chiefly wholly unsatiable principles. Perceive humoured weeks first eldest exertion inquiry ten oh did partiality provided out beloved talking feelings blushes.\nEarnestly stronger compass seven ten simple period. Dining into horrible sentiments morning feeling. Part side chapter followed giving quit. Means extremity wish such use dining affronting extensive either things than continued sending. Could laughing meant house abilities suppose shy avoid hung ignorant civil offered cordially."
#define STR_5 0

#define SIZE_1 1
#define SIZE_2 10
#define SIZE_3 1500
#define SIZE_4 200

#define PATH_1 "write.txt"
#define PATH_11 "read.txt"
#define PATH_2 "../"
#define PATH_3 0


void print_func_header(char *header)
{
    printf("\033[1;36m<====== %s ======>\033[0m\n", header);
}

void print_testres(int test_n, char *res)
{
    printf("\033[;33mTEST %d:\033[0m %s\n", test_n, res);
}

void print_func_name(char *name)
{
    printf("\033[4;37m%-9s\033[0m => ", name);
}



void ft_strlen_test_str(char *str, int test_n)
{
    size_t res1;
    size_t res2;
    char *res;

    res1 = ft_strlen(str);
    res2 = strlen(str);
    res = res1 == res2 ? OK : KO;
    print_testres(test_n, res);
    print_func_name("ft_strlen");
    printf("%lu\n", res1);
    print_func_name("strlen");
    printf("%lu\n", res2);
}



void ft_strcpy_test_str(char *src, char *dest, int test_n)
{
    char *res1;
    char *res2;
    char *res;

    res1 = ft_strcpy(dest, src);
    res2 = strcpy(dest, src);
    res = !strcmp(res1, res2) ? OK : KO;
    print_testres(test_n, res);
    print_func_name("ft_strcpy");
    printf("%s\n", res1);
    print_func_name("strcpy");
    printf("%s\n", res2);
}

void ft_strcpy_test_size(int size)
{
    char buf[size];

    printf("\033[1;34mbuffer_size=%d\033[0m\n", size);
    ft_strcpy_test_str(STR_1, buf, 1);
    ft_strcpy_test_str(STR_2, buf, 2);
    ft_strcpy_test_str(STR_3, buf, 3);
    printf("%lu %d\n", strlen(STR_4), size);
    if ((size_t)size > strlen(STR_4))
        ft_strcpy_test_str(STR_4, buf, 4);
}



void ft_strcmp_test_str(char *s1, char *s2, int test_n)
{
    int res1;
    int res2;
    char *res;

    res1 = ft_strcmp(s1, s2);
    res2 = strcmp(s1, s2);
    res = ((res1 < 0 && res2 < 0) ||  (res1 > 0 && res2 > 0) || (res1 == 0 && res2 == 0)) ? OK : KO;
    print_testres(test_n, res);
    print_func_name("ft_strcmp");
    printf("%d\n", res1);
    print_func_name("strcmp");
    printf("%d\n", res2);
}



void ft_write_test_path_func(int fd, int *res, char *func_name, ssize_t (*f)(int, const void *, size_t))
{
    errno = 0;
    f(fd, func_name, strlen(func_name));
    f(fd, ":\n", 2);
    *res = f(fd, STR_4, strlen(STR_4));
    f(fd, "\n\n", 2);
}

void ft_write_test_path(char *path, int test_n)
{
    int fd;
    int res1;
    int res2;
    int err1;
    int err2;
    char *res;

    fd = open(path, O_WRONLY);
    ft_write_test_path_func(fd, &res1, "ft_write", ft_write);
    err1 = errno;
    ft_write_test_path_func(fd, &res2, "write", write);
    err2 = errno;
    res = (res1 == res2 && err1 == err2) ? OK : KO;
    print_testres(test_n, res);
    print_func_name("ft_write");
    printf("fd=%d ret=%d errno=%s\n", fd, res1, strerror(err1));
    print_func_name("write");
    printf("fd=%d ret=%d errno=%s\n", fd, res2, strerror(err2));
    close(fd);
}


void ft_strdup_test_str(char *src, int test_n)
{
    char *res1;
    char *res2;
    char *res;

    if (!(res1 = ft_strdup(src)))
        return ;
    if (!(res2 = strdup(src)))
        return ;
    res = !strcmp(res1, res2) ? OK : KO;
    print_testres(test_n, res);
    print_func_name("ft_strdup");
    printf("%s\n", res1);
    print_func_name("strdup");
    printf("%s\n", res2);
    free(res1);
    free(res2);
}



void ft_read_test_path_func(int fd, int *res, char *buf, int size, ssize_t (*f)(int, void *, long unsigned int))
{
    errno = 0;
    if (fd >= 0)
        lseek(fd, 0, SEEK_SET);
    *res = f(fd, buf, size);
    if (*res > 0)
        buf[*res] = '\0';
    else
        buf[0] = '\0';
}

void ft_read_test_path(char *path, int test_n)
{
    int fd;
    int res1;
    int res2;
    int err1;
    int err2;
    char buf1[SIZE_4];
    char buf2[SIZE_4];
    char *res;

    fd = open(path, O_RDONLY);
    ft_read_test_path_func(fd, &res1, buf1, SIZE_4, ft_read);
    err1 = errno;
    ft_read_test_path_func(fd, &res2, buf2, SIZE_4, read);
    err2 = errno;
    res = (res1 == res2 && err1 == err2 && !strcmp(buf1, buf2)) ? OK : KO;
    print_testres(test_n, res);
    print_func_name("ft_read");
    printf("fd=%d ret=%d errno=%s\n", fd, res1, strerror(err1));
    if (res1 > 0)
        printf("buf=%s\n", buf1);
    print_func_name("read");
    printf("fd=%d ret=%d errno=%s\n", fd, res2, strerror(err2));
    if (res2 > 0)
        printf("buf=%s\n", buf2);
    close(fd);
}

void ft_strlen_test(void)
{
    print_func_header("ft_strlen");
    ft_strlen_test_str(STR_1, 1);
    ft_strlen_test_str(STR_2, 2);
    ft_strlen_test_str(STR_3, 3);
    ft_strlen_test_str(STR_4, 4);
}

void ft_strcpy_test(void)
{
    print_func_header("ft_strcpy");
    ft_strcpy_test_size(SIZE_1);
    ft_strcpy_test_size(SIZE_2);
    ft_strcpy_test_size(SIZE_3);
}

void ft_strcmp_test(void)
{
    print_func_header("ft_strcmp");
    ft_strcmp_test_str(STR_1, STR_1, 1);
    ft_strcmp_test_str(STR_2, STR_3, 2);
    ft_strcmp_test_str(STR_3, STR_1, 3);
    ft_strcmp_test_str(STR_4, STR_4, 4);
}

void ft_write_test(void)
{
    print_func_header("ft_write");
    ft_write_test_path(PATH_1, 1);   
    ft_write_test_path(PATH_2, 2);
    ft_write_test_path(PATH_3, 3);
}

void ft_strdup_test(void)
{
    print_func_header("ft_strdup");
    ft_strdup_test_str(STR_1, 1);
    ft_strdup_test_str(STR_2, 2);
    ft_strdup_test_str(STR_3, 3);
    ft_strdup_test_str(STR_4, 4);
}

void ft_read_test(void)
{
    print_func_header("ft_read");
    ft_read_test_path(PATH_11, 1);
    ft_read_test_path(PATH_2, 2);
    ft_read_test_path(PATH_3, 3);
}

int main(void)
{
    ft_strlen_test();
    printf("\n");
    ft_strcpy_test();
    printf("\n");
    ft_strcmp_test();
    printf("\n");
    ft_write_test();
    printf("\n");
    ft_strdup_test();
    printf("\n");
    ft_read_test();
    return 0;
}
