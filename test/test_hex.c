/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:55:39 by jmorillo          #+#    #+#             */
/*   Updated: 2022/07/16 18:07:55 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	to_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}
}

static void	print_test(char *text, unsigned int arg)
{
	t_arg	varg;
	char	*text_up;

	varg.type = HEX_LOW_TYPE;
	varg.value.u = arg;
	print_line_test(text, varg);
	varg.type = HEX_UP_TYPE;
	text_up = strdup(text);
	to_upper(text_up);
	print_line_test(text_up, varg);
	free(text_up);
}

void	test_hex(void)
{
	printf(" %sHexadecimal%s\n", TITLE_COLOR, RESET_COLOR);
	print_test("%x", 0);
	print_test("%x", 1);
	print_test("%x", 42);
	print_test("%x", 500);
	print_test("%#x", 0);
	print_test("%#.x", 0);
	print_test("%#7.5x", 0);
	print_test("%7.x", 0);
	print_test("%#x", 42);
	print_test("%#x", 0xFFFFFFFF);
	print_test("%7x", 42);
	print_test("%-7x", 42);
	print_test("%#-7x", 42);
	print_test("% 7x", 42);
	print_test("%#7x", 42);
	print_test("%07x", 42);
	print_test("%#07x", 42);
	print_test("%7.5x", 42);
	print_test("%#7.5x", 42);
	print_test("%--14.36x", 703835510u);
}
