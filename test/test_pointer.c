/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:55:39 by jmorillo          #+#    #+#             */
/*   Updated: 2022/07/16 18:10:06 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	print_test(char *text, unsigned long arg)
{
	t_arg	varg;

	varg.type = POINTER_TYPE;
	varg.value.p = arg;
	print_line_test(text, varg);
}

void	test_pointer(void)
{
	printf(" %sPuntero%s\n", TITLE_COLOR, RESET_COLOR);
	print_test("%p", 0);
	print_test("%p", 1);
	print_test("%p", 11);
	print_test("%p", 16);
	print_test("%p", 500);
	print_test("%p", 0xFFFFFFFF);
	print_test("%p", 0xFFFFFFFFFFFFFFFF);
	print_test("%7p", 42);
	print_test("%1p", 42);
	print_test("%-7p", 42);
	print_test("%0-7p", 42);
	print_test("%12p", 18229185041105221837lu);
}
