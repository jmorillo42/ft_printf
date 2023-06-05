/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:55:39 by jmorillo          #+#    #+#             */
/*   Updated: 2022/07/10 19:00:48 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	print_test(char *text, char *arg)
{
	t_arg	varg;

	varg.type = STRING_TYPE;
	varg.value.s = arg;
	print_line_test(text, varg);
}

void	test_str(void)
{
	printf(" %sTexto%s\n", TITLE_COLOR, RESET_COLOR);
	print_test("foobar", NULL);
	print_test("foo", "bar");
	print_test("", "bar");
	print_test("%s", NULL);
	print_test("foo%s", "bar");
	print_test("foo%5s", "bar");
	print_test("foo%05s", "bar");
	print_test("foo%-5s", "bar");
	print_test("foo%-5s", "bar");
	print_test("foo%-1s", "");
	print_test("foo%1s", "");
	print_test(" %-2s ", " - ");
	print_test(" %-3s ", "");
	print_test(" %-4s ", "4");
	print_test(" %-5s ", "");
	print_test(" %.s ", "-");
	print_test(" %.1s ", "foo");
	print_test(" %.3s ", "");
}
