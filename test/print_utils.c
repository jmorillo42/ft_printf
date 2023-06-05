/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:25:35 by jmorillo          #+#    #+#             */
/*   Updated: 2022/07/16 12:00:06 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_char_quoted(char c)
{
	printf("%s", LEFT_SQUOTE);
	if (c >= 0 && c < 32)
		printf("%s\\%02X%s", L_BLUE, c, RESET_COLOR);
	else
		printf("%c", c);
	printf("%s", RIGHT_SQUOTE);
}

void	print_str_quoted(char *text)
{
	size_t	i;
	size_t	length;

	if (!text)
		printf("%s", BLUE_NULL);
	else
	{
		printf("%s", LEFT_DQUOTE);
		i = 0;
		length = strlen(text);
		while (i < length)
		{
			if (text[i] > 0 && text[i] < 32)
				printf("%s\\%02X%s", L_BLUE, text[i], RESET_COLOR);
			else
				printf("%c", text[i]);
			i++;
		}
		printf("%s", RIGHT_DQUOTE);
	}
}

int	ft_printf_varg(char *text, t_arg varg)
{
	int	count;

	count = -1;
	if (varg.type == CHAR_TYPE)
		count = ft_printf(text, varg.value.c);
	else if (varg.type == STRING_TYPE)
		count = ft_printf(text, varg.value.s);
	else if (varg.type == INT_TYPE)
		count = ft_printf(text, varg.value.i);
	else if (varg.type == UNSIGNED_TYPE
		|| varg.type == HEX_LOW_TYPE
		|| varg.type == HEX_UP_TYPE)
		count = ft_printf(text, varg.value.u);
	else if (varg.type == POINTER_TYPE)
		count = ft_printf(text, varg.value.p);
	return (count);
}

int	printf_varg(char *text, t_arg varg)
{
	int	count;

	count = -1;
	if (varg.type == CHAR_TYPE)
		count = printf(text, varg.value.c);
	else if (varg.type == STRING_TYPE)
		count = printf(text, varg.value.s);
	else if (varg.type == INT_TYPE)
		count = printf(text, varg.value.i);
	else if (varg.type == UNSIGNED_TYPE
		|| varg.type == HEX_LOW_TYPE
		|| varg.type == HEX_UP_TYPE)
		count = printf(text, varg.value.u);
	else if (varg.type == POINTER_TYPE)
		count = printf(text, varg.value.p);
	return (count);
}

void	print_expected_string(char *text, t_arg varg)
{
	printf("%s%s", LEFT_DQUOTE, L_RED);
	printf_varg(text, varg);
	printf("%s", RIGHT_DQUOTE);
}

void	print_input_arguments(char *text, t_arg arg)
{
	printf("  %s %s(%s", TEST_ITEM, FUNCTION_COLOR, RESET_COLOR);
	print_str_quoted(text);
	printf("%s,%s ", YELLOW, RESET_COLOR);
	if (arg.type == CHAR_TYPE)
		print_char_quoted(arg.value.c);
	else if (arg.type == STRING_TYPE)
		print_str_quoted(arg.value.s);
	else if (arg.type == UNSIGNED_TYPE)
		printf("%u", arg.value.u);
	else if (arg.type == INT_TYPE)
		printf("%i", arg.value.i);
	else if (arg.type == HEX_LOW_TYPE)
		printf("%x", arg.value.u);
	else if (arg.type == HEX_UP_TYPE)
		printf("%X", arg.value.u);
	else if (arg.type == POINTER_TYPE)
		printf("%lu", arg.value.p);
	printf("%s)%s %s ", FUNCTION_COLOR, RESET_COLOR, ARROW);
	printf("%s", LEFT_DQUOTE);
	fflush(stdout);
}

void	print_line_test(char *text, t_arg varg)
{
	int		count_lib;
	int		count_ft;

	print_input_arguments(text, varg);
	count_ft = ft_printf_varg(text, varg);
	printf("%s ", RIGHT_DQUOTE);
	count_lib = printf_to_file(text, varg);
	count_ft = ft_printf_to_file(text, varg);
	assert_equal_text(text, varg);
	printf(" %s%d%s", LEFT_BRACKET, count_ft, RIGHT_BRACKET);
	assert_equal_count(count_lib, count_ft);
	printf("\n");
}
