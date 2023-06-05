/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:55:39 by jmorillo          #+#    #+#             */
/*   Updated: 2022/07/16 12:36:45 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	print_test(char *text)
{
	printf("  %s %sft_printf(%s", TEST_ITEM, FUNCTION_COLOR, RESET_COLOR);
	print_str_quoted(text);
	printf("%s) %s %s", FUNCTION_COLOR, ARROW, LEFT_DQUOTE);
	fflush(stdout);
	printf("%s  %s%d%s\n", RIGHT_DQUOTE, LEFT_BRACKET,
		ft_printf(text), RIGHT_BRACKET);
	printf("  %s %s   printf(%s", TEST_ITEM, FUNCTION_COLOR, RESET_COLOR);
	print_str_quoted(text);
	printf("%s) %s %s", FUNCTION_COLOR, ARROW, LEFT_DQUOTE);
	fflush(stdout);
	printf("%s  %s%d%s\n", RIGHT_DQUOTE, LEFT_BRACKET,
		printf("%s", text), RIGHT_BRACKET);
}

void	test_percent(void)
{
	printf(" %sPorcentaje%s\n", TITLE_COLOR, RESET_COLOR);
	print_test("%%");
	print_test("%10%");
	print_test("%010%");
	print_test("%-10%");
	print_test("%-010%");
	print_test("% 10%");
	print_test("% 010%");
}
