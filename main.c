/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:43:19 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/21 18:41:14 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	test_strlen(char *s)
{
	size_t res1;
	size_t res2;

	res1 = 0;
	res2 = 0;
	res1 = ft_strlen(s);
	res2 = strlen(s);
	if (res1 == res2)
		printf("OK\n");
	else
		printf("KO\n");
}

void	test_strcpy(char *src)
{
	char	dest1[512];
	char	dest2[512];

	bzero(dest1, 512);
	bzero(dest2, 512);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	if (!strcmp(dest1, dest2))
		printf("OK\n");
	else
		printf("KO\n");
}

void	test_strcmp(char *s1, char *s2)
{
	int	ret1;
	int ret2;

	ret1 = 0;
	ret2 = 0;
	ret1 = ft_strcmp(s1, s2);
	ret2 = strcmp(s1, s2);
	if ((ret1 == 0 && ret2 == 0) || (ret1 < 0 && ret2 < 0)
								|| (ret1 > 0 && ret2 > 0))
		printf("OK\n");
	else
		printf("KO\n");
}

void	test_write(char *s, int fd)
{
	char	*buff;
	char	*res1;
	char	*res2;
	int		size;
	int		fd2;
	ssize_t ret1;
	ssize_t ret2;

	res1 = malloc(sizeof(char) * 512);
	res1[511] = 0;
	res2 = malloc(sizeof(char) * 512);
	res2[511] = 0;
	ret1 = 0;
	ret2 = 0;
	buff = strdup(s);
	printf("TEST EXISTING FD:					");
	fd2 = open("text2.txt", O_CREAT | O_RDWR, 0777);
	size = strlen(s);
	ft_write(fd, buff, size);
	write(fd2, buff, size);
	read(fd, res1, 512);
	read(fd2, res2, 512);
	if (strcmp(res1, res2) == 0)
		printf("OK\n");
	else
		printf("KO\n");
	printf("TEST STDOUT:						\n");
	ft_write(STDOUT_FILENO, buff, size);
	write(STDOUT_FILENO, buff, size);
	printf("TEST NOT EXISTING FD:					");
	ret1 = ft_write(-1, buff, size);
	ret2 = write(-1, buff, size);
	if (ret1 == ret2)
		printf("OK\n");
	else
		printf("KO\n");
	printf("TEST RETURN VALUE:					");
	ret1 = ft_write(-1, buff, size);
	ret2 = write(-1, buff, size);
	printf("ft: %zu real: %zu\n", ret1, ret2);
}

void	test_read(int fd)
{
	char b1[512];
	char b2[512];
	ssize_t ret1;
	ssize_t ret2;
	int fd2;

	ret1 = 0;
	ret2 = 0;
	bzero(b1, 512);
	bzero(b2, 512);
	ft_read(fd, b1, 512);
	close(fd);
	fd2 = open("text.txt", O_RDONLY);
	read(fd2, b2, 512);
	printf("TEST EXISTING FD:					");
	if (strcmp(b1, b2) == 0)
		printf("OK\n");
	else
		printf("KO\n");
	bzero(b1, 512);
	bzero(b2, 512);
	printf("TEST STDIN:					\n");
	ft_read(0, b1, 512);
	read(0, b2, 512);
	if (strcmp(b1, b2) == 0)
		printf("OK\n");
	else
		printf("KO\n");
	printf("TEST NOT EXISTING FD:					");
	ret1 = ft_read(-1, b1, 512);
	ret2 = read(-1, b2, 512);
	if (ret1 == ret2)
		printf("OK\n");
	else
		printf("KO\n");
	printf("TEST RETURN VALUE:					");
	ret1 = ft_read(-1, b1, 512);
	ret2 = read(-1, b2, 512);
	printf("ft: %zu real: %zu\n", ret1, ret2);
}

void	test_strdup()
{
	char *s1;
	char *s2;

	printf("TEST LONG STRING:					");
	s1 = ft_strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	s2 = strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	if (strcmp(s1, s2) == 0)
		printf("OK\n");
	else
		printf("KO\n");
	printf("TEST EMPTY STRINGS:					");
	s1 = ft_strdup("");
	s2 = strdup("");
	if (strcmp(s1, s2) == 0)
		printf("OK\n");
	else
		printf("KO\n");
}

int		main(void)
{
	printf("\e[0;95m..........................................................................................................................................................................................................\n\033[0m");
	printf("\e[0;95m...............................................................***.........****..********....******...........**********...****........****...............................................................\n\033[0m");
	printf("\e[0;95m...............................................................***.........****..*********...*******..........**********...******.....*****...............................................................\n\033[0m");
	printf("\e[0;95m...............................................................***.........****..***....***..***..***.........***..........*******...******...............................................................\n\033[0m");
	printf("\e[0;95m...............................................................***.........****..***....***..***...***........***..........***..***.***.***...............................................................\n\033[0m");
	printf("\e[0;95m...............................................................***.........****..*********...***....***.......**********...***...*****..***...............................................................\n\033[0m");
	printf("\e[0;95m...............................................................***.........****..*********...***********......**********...***....***...***...............................................................\n\033[0m");
	printf("\e[0;95m...............................................................***.........****..***....***..************............***...***..........***...............................................................\n\033[0m");
	printf("\e[0;95m...............................................................***.........****..***....***..***.......***...........***...***..........***...............................................................\n\033[0m");
	printf("\e[0;95m...............................................................**********..****..**********..***........***...**********...***..........***...............................................................\n\033[0m");
	printf("\e[0;95m...............................................................**********..****..**********..***.........***..**********...***..........***...............................................................\n\033[0m");
	printf("\e[0;95m........................................................................................................................................................................................................AD\n\033[0m");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[1;96m------------------------------------------------------------------------------------------------FT_STRLEN------------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
	printf("TEST LONG STRING:					");
	test_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	printf("TEST EMPTY STRING:					");
	test_strlen("");
	printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[1;96m------------------------------------------------------------------------------------------------FT_STRCPY------------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
	printf("TEST NORMAL STRING:					");
	test_strcpy("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	printf("TEST EMPTY SRC:						");
	test_strcpy("");
	printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[1;96m------------------------------------------------------------------------------------------------FT_STRCMP------------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
	printf("TEST EMPTY STRINGS:					");
	test_strcmp("", "");
	printf("TEST EMPTY STRING 1:					");
	test_strcmp("", "test per la prima stringa vuota");
	printf("TEST EMPTY STRING 2:					");
	test_strcmp("test per la seconda stringa vuota", "");
	printf("TEST LONG STRING:					");
	test_strcmp("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	printf("TEST POS STRING:					");
	test_strcmp("stringcompare", "stringcmp");
	printf("TEST NEG STRING:					");
	test_strcmp("stringcmp", "stringcompare");
	printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[1;96m------------------------------------------------------------------------------------------------FT_WRITE ------------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
	int fd1;
	fd1 = open("text.txt", O_CREAT | O_RDWR, 0777);
	test_write("scrivi questo in text\n", fd1);
	close(fd1);
	printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[1;96m-------------------------------------------------------------------------------------------------FT_READ-------------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
	int fd2;
	fd2 = open("text2.txt", O_RDONLY);
	test_read(fd2);
	close(fd2);
	printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[1;96m------------------------------------------------------------------------------------------------FT_STRDUP------------------------------------------------------------------------------------------------\n\033[0m");
	printf("\e[1;96m---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
	test_strdup();

}
