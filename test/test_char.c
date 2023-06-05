/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:22:48 by jmorillo          #+#    #+#             */
/*   Updated: 2022/07/16 18:06:39 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	print_test(char *text, char arg)
{
	t_arg	varg;

	varg.type = CHAR_TYPE;
	varg.value.c = arg;
	print_line_test(text, varg);
}

void	test_char(void)
{
	printf(" %sCarácter%s\n", TITLE_COLOR, RESET_COLOR);
	print_test("foo%cbar", '_');
	print_test("foo%5cbar", '_');
	print_test("foo%05cbar", '_');
	print_test("foo%#5cbar", '_');
	print_test("foo% 5.3cbar", '_');
	print_test("foo%cbar", 0);
	print_test("foo%5cbar", 0);
	print_test("foo%17cbar", 7);
	print_test("foo%-1cbar", 120);
}
