/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:43:19 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/21 13:00:03 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(void)
{
	size_t res1;
	size_t res2;

	res1 = 0;
	res2 = 0;
	res1 = ft_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	res2 = strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	printf("TEST LONG STRING:					");
	if (res1 == res2)
		printf("OK\n");
	else
		printf("KO\n");
	res1 = ft_strlen("");
	res2 = strlen("");
	printf("TEST EMPTY STRING:					");
	if (res1 == res2)
		printf("OK\n");
	else
		printf("KO\n");
	res1 = ft_strlen("");
	res2 = strlen("");
	printf("TEST NULL STRING:					");
	if (res1 == res2)
		printf("OK\n");
	else
		printf("KO\n");

	char	dest1[512];
	char	dest2[512];

	bzero(dest1, 512);
	bzero(dest2, 512);
	ft_strcpy(dest1, "bella storia");
	strcpy(dest2, "bella storia");
	printf("TEST NORMAL STRING:					");
	if (!strcmp(dest1, dest2))
		printf("OK\n");
	else
		printf("KO\n");
	ft_strcpy(dest1, "");
	strcpy(dest2, "");
	printf("TEST EMPTY SRC:						");
	if (!strcmp(dest1, dest2))
		printf("OK\n");
	else
		printf("KO\n");

	int	ret1;
	int ret2;

	ret1 = ft_strcmp("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	ret2 = strcmp("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	printf("TEST LONG STRING:					");
	if (ret1 == 0 && ret2 == 0)
		printf("OK\n");
	else
		printf("KO\n");
	printf("TEST POS STRING:					");
	ret1 = ft_strcmp("strcmp", "strcm");
	ret2 = strcmp("strcmp", "strcm");
	if (ret1 > 0 && ret2 > 0)
		printf("OK\n");
	else
		printf("KO\n");
	printf("TEST NEG STRING:					");
	ret1 = ft_strcmp("strcm", "strcmppp");
	ret2 = strcmp("strcm", "strcmppp");
	if (ret1 < 0 && ret2 < 0)
		printf("OK\n");
	else
		printf("KO\n");
}
