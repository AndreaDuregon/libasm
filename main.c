/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:43:19 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/22 19:07:57 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "main.h"

// void	test_strlen(char *s)
// {
// 	size_t res1;
// 	size_t res2;

// 	res1 = 0;
// 	res2 = 0;
// 	res1 = ft_strlen(s);
// 	res2 = strlen(s);
// 	if (res1 == res2)
// 		printf("OK\n");
// 	else
// 		printf("KO\n");
// }

// void	test_strcpy(char *src)
// {
// 	char	dest1[512];
// 	char	dest2[512];

// 	bzero(dest1, 512);
// 	bzero(dest2, 512);
// 	ft_strcpy(dest1, src);
// 	strcpy(dest2, src);
// 	if (!strcmp(dest1, dest2))
// 		printf("OK\n");
// 	else
// 		printf("KO\n");
// }

// void	test_strcmp(char *s1, char *s2)
// {
// 	int	ret1;
// 	int ret2;

// 	ret1 = 0;
// 	ret2 = 0;
// 	ret1 = ft_strcmp(s1, s2);
// 	ret2 = strcmp(s1, s2);
// 	if ((ret1 == 0 && ret2 == 0) || (ret1 < 0 && ret2 < 0)
// 								|| (ret1 > 0 && ret2 > 0))
// 		printf("OK\n");
// 	else
// 		printf("KO\n");
// }

// void	test_write(char *s, int fd)
// {
// 	char	*buff;
// 	char	*res1;
// 	char	*res2;
// 	int		size;
// 	int		fd2;
// 	ssize_t ret1;
// 	ssize_t ret2;

// 	res1 = malloc(sizeof(char) * 512);
// 	res1[511] = 0;
// 	res2 = malloc(sizeof(char) * 512);
// 	res2[511] = 0;
// 	ret1 = 0;
// 	ret2 = 0;
// 	buff = strdup(s);
// 	printf("TEST EXISTING FD:					");
// 	fd2 = open("text2.txt", O_CREAT | O_RDWR, 0777);
// 	size = strlen(s);
// 	ft_write(fd, buff, size);
// 	write(fd2, buff, size);
// 	read(fd, res1, 512);
// 	read(fd2, res2, 512);
// 	if (strcmp(res1, res2) == 0)
// 		printf("OK\n");
// 	else
// 		printf("KO\n");
// 	printf("TEST STDOUT:						\n");
// 	ft_write(STDOUT_FILENO, buff, size);
// 	write(STDOUT_FILENO, buff, size);
// 	printf("TEST NOT EXISTING FD:					");
// 	ret1 = ft_write(-1, buff, size);
// 	ret2 = write(-1, buff, size);
// 	if (ret1 == ret2)
// 		printf("OK\n");
// 	else
// 		printf("KO\n");
// 	printf("TEST RETURN VALUE:					");
// 	ret1 = ft_write(-1, buff, size);
// 	ret2 = write(-1, buff, size);
// 	printf("ft: %zu real: %zu\n", ret1, ret2);
// }

// void	test_read(int fd)
// {
// 	char b1[512];
// 	char b2[512];
// 	ssize_t ret1;
// 	ssize_t ret2;
// 	int fd2;

// 	ret1 = 0;
// 	ret2 = 0;
// 	bzero(b1, 512);
// 	bzero(b2, 512);
// 	ft_read(fd, b1, 512);
// 	close(fd);
// 	fd2 = open("text.txt", O_RDONLY);
// 	read(fd2, b2, 512);
// 	printf("TEST EXISTING FD:					");
// 	if (strcmp(b1, b2) == 0)
// 		printf("OK\n");
// 	else
// 		printf("KO\n");
// 	bzero(b1, 512);
// 	bzero(b2, 512);
// 	printf("TEST STDIN:					\n");
// 	ft_read(0, b1, 512);
// 	read(0, b2, 512);
// 	if (strcmp(b1, b2) == 0)
// 		printf("OK\n");
// 	else
// 		printf("KO\n");
// 	printf("TEST NOT EXISTING FD:					");
// 	ret1 = ft_read(-1, b1, 512);
// 	ret2 = read(-1, b2, 512);
// 	if (ret1 == ret2)
// 		printf("OK\n");
// 	else
// 		printf("KO\n");
// 	printf("TEST RETURN VALUE:					");
// 	ret1 = ft_read(-1, b1, 512);
// 	ret2 = read(-1, b2, 512);
// 	printf("ft: %zu real: %zu\n", ret1, ret2);
// }

// void	test_strdup()
// {
// 	char *s1;
// 	char *s2;

// 	printf("TEST LONG STRING:					");
// 	s1 = ft_strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
// 	s2 = strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
// 	if (strcmp(s1, s2) == 0)
// 		printf("OK\n");
// 	else
// 		printf("KO\n");
// 	printf("TEST EMPTY STRINGS:					");
// 	s1 = ft_strdup("");
// 	s2 = strdup("");
// 	if (strcmp(s1, s2) == 0)
// 		printf("OK\n");
// 	else
// 		printf("KO\n");
// }

// typedef struct	s_list
// {
// 	void			*data;
// 	struct s_list	*next;
// }				t_list;

// void
// 	printf_list(t_list *list)
// {
// 	while (list)
// 	{
// 		printf("; %s\n", list->data);
// 		list = list->next;
// 	}
// }

// int		main(void)
// {
// 	// printf("\e[0;95m..........................................................................................................................................................................................................\n\033[0m");
// 	// printf("\e[0;95m...............................................................***.........****..********....******...........**********...****........****...............................................................\n\033[0m");
// 	// printf("\e[0;95m...............................................................***.........****..*********...*******..........**********...******.....*****...............................................................\n\033[0m");
// 	// printf("\e[0;95m...............................................................***.........****..***....***..***..***.........***..........*******...******...............................................................\n\033[0m");
// 	// printf("\e[0;95m...............................................................***.........****..***....***..***...***........***..........***..***.***.***...............................................................\n\033[0m");
// 	// printf("\e[0;95m...............................................................***.........****..*********...***....***.......**********...***...*****..***...............................................................\n\033[0m");
// 	// printf("\e[0;95m...............................................................***.........****..*********...***********......**********...***....***...***...............................................................\n\033[0m");
// 	// printf("\e[0;95m...............................................................***.........****..***....***..************............***...***..........***...............................................................\n\033[0m");
// 	// printf("\e[0;95m...............................................................***.........****..***....***..***.......***...........***...***..........***...............................................................\n\033[0m");
// 	// printf("\e[0;95m...............................................................**********..****..**********..***........***...**********...***..........***...............................................................\n\033[0m");
// 	// printf("\e[0;95m...............................................................**********..****..**********..***.........***..**********...***..........***...............................................................\n\033[0m");
// 	// printf("\e[0;95m........................................................................................................................................................................................................AD\n\033[0m");
// 	// printf("\n");
// 	// printf("\n");
// 	// printf("\n");
// 	// printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("\e[1;96m------------------------------------------------------------------------------------------------FT_STRLEN------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("TEST LONG STRING:					");
// 	// test_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
// 	// printf("TEST EMPTY STRING:					");
// 	// test_strlen("");
// 	// printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("\e[1;96m------------------------------------------------------------------------------------------------FT_STRCPY------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("TEST NORMAL STRING:					");
// 	// test_strcpy("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
// 	// printf("TEST EMPTY SRC:						");
// 	// test_strcpy("");
// 	// printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("\e[1;96m------------------------------------------------------------------------------------------------FT_STRCMP------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("TEST EMPTY STRINGS:					");
// 	// test_strcmp("", "");
// 	// printf("TEST EMPTY STRING 1:					");
// 	// test_strcmp("", "test per la prima stringa vuota");
// 	// printf("TEST EMPTY STRING 2:					");
// 	// test_strcmp("test per la seconda stringa vuota", "");
// 	// printf("TEST LONG STRING:					");
// 	// test_strcmp("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
// 	// printf("TEST POS STRING:					");
// 	// test_strcmp("stringcompare", "stringcmp");
// 	// printf("TEST NEG STRING:					");
// 	// test_strcmp("stringcmp", "stringcompare");
// 	// printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("\e[1;96m------------------------------------------------------------------------------------------------FT_WRITE ------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
// 	// int fd1;
// 	// fd1 = open("text.txt", O_CREAT | O_RDWR, 0777);
// 	// test_write("scrivi questo in text\n", fd1);
// 	// close(fd1);
// 	// printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("\e[1;96m-------------------------------------------------------------------------------------------------FT_READ-------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
// 	// int fd2;
// 	// fd2 = open("text2.txt", O_RDONLY);
// 	// test_read(fd2);
// 	// close(fd2);
// 	// printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("\e[1;96m------------------------------------------------------------------------------------------------FT_STRDUP------------------------------------------------------------------------------------------------\n\033[0m");
// 	// printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
// 	// test_strdup();

// }

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/*
** Useful macro
*/
# define ATOI_BASE(s, b)	i = ft_atoi_base(s, b); printf("`%s`[%s] = %d\n", s, b, i);

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

/*
** print a list elements one by line
*/
void
	printf_list(t_list *list)
{
	while (list)
	{
		printf("; %s\n", list->data);
		list = list->next;
	}
}

/*
** free a whole list and it's data field
*/
void
	ft_lstclear(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = tmp;
	}
}

/*
** Function prototypes
*/
int		ft_atoi_base(char const *str, char const *base);

void	ft_list_push_front(t_list **begin_list, void *data);

int		ft_list_size(t_list *begin_list);

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
			void (*free_fct)(void*));

void	ft_list_sort(t_list **begin_list,int (*cmp)());

/*
** Start !
*/
int		main(void)
{
	int	i = 0;
	printf("\n--ft_atoi_base\n");
	ATOI_BASE("42", "0123456789")
	ATOI_BASE("0", "0123456789")
	ATOI_BASE("1", "0123456789")
	ATOI_BASE("1215415478", "0123456789")
	ATOI_BASE("-0", "0123456789")
	ATOI_BASE("-1", "0123456789")
	ATOI_BASE("-42", "0123456789")
	ATOI_BASE("--42", "0123456789")
	ATOI_BASE("-+-42", "0123456789")
	ATOI_BASE("-+-+-+42", "0123456789")
	ATOI_BASE("-+-+-+-42", "0123456789")
	ATOI_BASE("-1215415478", "0123456789")
	ATOI_BASE("2147483647", "0123456789")
	ATOI_BASE("2147483648", "0123456789")
	ATOI_BASE("-2147483648", "0123456789")
	ATOI_BASE("-2147483649", "0123456789")
	ATOI_BASE("2a", "0123456789abcdef")
	ATOI_BASE("ff", "0123456789abcdef")
	ATOI_BASE("poney", "poney")
	ATOI_BASE("dommage", "invalid")
	ATOI_BASE("dommage", "aussi invalide")
	ATOI_BASE("dommage", "+toujours")
	ATOI_BASE("dommage", "-stop")
	ATOI_BASE("dommage", "  \t\nca suffit")
	ATOI_BASE("    +42", "0123456789")
	ATOI_BASE("    -42", "0123456789")
	ATOI_BASE("    42", "0123456789")
	ATOI_BASE("  \t\n\r\v\f  42", "0123456789")
	ATOI_BASE("  \t\n\r\v\f  -42", "0123456789")
	ATOI_BASE("42FINIS !", "0123456789")
	ATOI_BASE("-42FINIS !", "0123456789")
	ATOI_BASE("C'est dommage42", "0123456789")
	printf("-done\n");

	t_list	list;
	t_list	list_next;
	t_list	list_last;
	list.data = strdup("toto");
	list.next = &list_next;
	list_next.data = strdup("bar");
	list_next.next = &list_last;
	list_last.data = strdup("monkaS");
	list_last.next = NULL;
	printf("\n--ft_list_size\n");
	printf("list content:\n");
	printf_list(&list);
	printf("%d (from first %d)\n", ft_list_size(&list), 3);
	printf("%d (from second %d)\n", ft_list_size(&list_next), 2);
	printf("%d (NULL %d)\n", ft_list_size(NULL), 0);
	printf("%d (from last %d)\n", ft_list_size(&list_last), 1);
	printf("-done\n");
	free(list_next.data);
	free(list_last.data);

	printf("\n--ft_list_push_front\n");
	t_list	*push_test = &list;
	ft_list_push_front(&push_test, strdup("toto"));
	printf("added: `%s` (next: %p)\n", push_test->data, push_test->next);
	printf("new list size: %d (%d)\n", ft_list_size(push_test), 4);
	free(list.data);
	free(push_test->data);
	free(push_test);
	push_test = NULL;
	ft_list_push_front(&push_test, strdup("barbar"));
	printf("added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	ft_list_push_front(&push_test, NULL);
	printf("added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	free(push_test->next);
	push_test->next = NULL;
	ft_list_push_front(&push_test, strdup("toto_r"));
	printf("added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	ft_lstclear(&push_test);
	printf("-done\n");

	printf("\n--ft_list_sort\n");
	ft_list_push_front(&push_test, strdup("F"));
	ft_list_push_front(&push_test, strdup("G"));
	ft_list_push_front(&push_test, strdup("E"));
	ft_list_push_front(&push_test, strdup("R"));
	ft_list_push_front(&push_test, strdup("O"));
	ft_list_push_front(&push_test, strdup("P"));
	ft_list_push_front(&push_test, strdup("L"));
	ft_list_push_front(&push_test, strdup("Q"));
	ft_list_push_front(&push_test, strdup("W"));
	ft_list_push_front(&push_test, strdup("A"));
	ft_list_push_front(&push_test, strdup("Z"));
	printf("before:\n");
	printf_list(push_test);
	ft_list_sort(&push_test, &strcmp);
	printf("after:\n");
	printf_list(push_test);
	ft_lstclear(&push_test);
	printf("sort NULL:\n");
	ft_list_sort(NULL, &strcmp);
	printf("NULL\n");
	printf("-done\n");

	printf("\n--ft_list_remove_if\n");
	ft_list_push_front(&push_test, strdup("toto"));
	ft_list_push_front(&push_test, strdup("barbar"));
	ft_list_push_front(&push_test, strdup("tortor"));
	ft_list_push_front(&push_test, NULL);
	printf("before:\n");
	printf_list(push_test);
	ft_list_remove_if(&push_test, "", &strcmp, &free);
	printf("nothing removed:\n");
	printf_list(push_test);
	ft_list_remove_if(&push_test, "toto", &strcmp, &free);
	ft_list_remove_if(&push_test, "tortor", &strcmp, &free);
	ft_list_remove_if(&push_test, "barbar", &strcmp, &free);
	ft_list_remove_if(&push_test, "", &strcmp, &free);
	//ft_list_remove_if(&push_test, NULL, &strcmp, &free);
	// printf("after:\n");
	// printf_list(push_test);
	// ft_lstclear(&push_test);
	// printf("-done\n");

	return (0);
}