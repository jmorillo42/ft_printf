/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:55:39 by jmorillo          #+#    #+#             */
/*   Updated: 2022/07/16 18:24:03 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	print_test(char *text, unsigned int arg)
{
	t_arg	varg;

	varg.type = UNSIGNED_TYPE;
	varg.value.u = arg;
	print_line_test(text, varg);
}

void	test_unsigned(void)
{
	printf(" %sEntero positivo%s\n", TITLE_COLOR, RESET_COLOR);
	print_test("%u", 0);
	print_test("%u", 1);
	print_test("%u", 42);
	print_test("%u", 500);
	print_test("%3u", 0);
	print_test("%01.u", 0);
	print_test("%46.4u", 0);
	print_test("% 5u", 42);
	print_test("%-5u", 42);
	print_test("%+5u", 42);
	print_test("%05u", 42);
	print_test("% 05u", 42);
	print_test("% 05.3u", 42);
	print_test("%05.3u", 42);
}
