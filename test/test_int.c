/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:55:39 by jmorillo          #+#    #+#             */
/*   Updated: 2022/07/16 18:11:15 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	print_test(char *text, int arg)
{
	t_arg	varg;

	varg.type = INT_TYPE;
	varg.value.i = arg;
	print_line_test(text, varg);
}

void	test_int(void)
{
	printf(" %sEntero%s\n", TITLE_COLOR, RESET_COLOR);
	print_test("%d", 0);
	print_test("%i", -0);
	print_test("%d", 1);
	print_test("%i", -1);
	print_test("%d", 500);
	print_test("%i", -500);
	print_test("%5d", -11);
	print_test("%-5i", -11);
	print_test("%0+5i", -11);
	print_test("% -+5i", -11);
	print_test("%0-+5i", -11);
	print_test("%+5d", 11);
	print_test("%+2d", 11);
	print_test("% 02i", 11);
	print_test("%+02i", 11);
	print_test("%+01i", 0);
	print_test("% 01d", 0);
	print_test("%5.2d", 1);
	print_test("%5.2d", -1);
	print_test("%.d", 0);
	print_test("%.d", 5);
	print_test("%.d", 5);
	print_test("%1.0d", 0);
	print_test("%-8.5d", -42);
	print_test("%8.5d", -42);
	print_test("%08.5d", -42);
	print_test("% 5i", 42);
	print_test("% 05i", 42);
	print_test("%013.i", -1488496170);
}
