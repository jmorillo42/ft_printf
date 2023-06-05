/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ftext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:15:38 by jmorillo          #+#    #+#             */
/*   Updated: 2022/07/09 18:56:46 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	print_arg(t_fmt_text *ftext)
{
	printf("   %s argument. %s ", ELEMENT, EQUAL);
	if (ftext->type == CHAR_TYPE)
		printf("%c", va_arg(ftext->arguments, int));
	else if (ftext->type == STRING_TYPE)
		printf("%s", va_arg(ftext->arguments, char *));
	else if (ftext->type == UNSIGNED_TYPE)
		printf("%u", va_arg(ftext->arguments, unsigned int));
	else if (ftext->type == HEX_LOW_TYPE)
		printf("%x", va_arg(ftext->arguments, unsigned int));
	else if (ftext->type == HEX_UP_TYPE)
		printf("%X", va_arg(ftext->arguments, unsigned int));
	else if (ftext->type == POINTER_TYPE)
		printf("%lu", va_arg(ftext->arguments, long unsigned));
	printf("\n");
}

static void	print_ftext(t_fmt_text *ftext)
{
	printf("   %s text..... %s %s\n", ELEMENT, EQUAL, ftext->text);
	print_arg(ftext);
	printf("   %s position. %s %zu\n", ELEMENT, EQUAL, ftext->position);
	printf("   %s count.... %s %d\n", ELEMENT, EQUAL, ftext->count);
	printf("   %s type..... %s %c\n", ELEMENT, EQUAL, ftext->type);
	printf("   %s width.... %s %zu\n", ELEMENT, EQUAL, ftext->width);
	printf("   %s precision %s %zu\n", ELEMENT, EQUAL, ftext->precision);
	printf("   %s ......dot %s %u\n", ELEMENT, EQUAL, ftext->dot_flag);
	printf("   %s ....minus %s %u\n", ELEMENT, EQUAL, ftext->minus_flag);
	printf("   %s .....plus %s %u\n", ELEMENT, EQUAL, ftext->plus_flag);
	printf("   %s ....sharp %s %u\n", ELEMENT, EQUAL, ftext->sharp_flag);
	printf("   %s ....space %s %u\n", ELEMENT, EQUAL, ftext->space_flag);
	printf("   %s .....zero %s %u\n", ELEMENT, EQUAL, ftext->zero_flag);
}

static void	print_test(char *text, ...)
{
	t_fmt_text	*ftext;

	printf(" %s %sfmt_text%s(", TEST_ITEM, FUNCTION_COLOR, RESET_COLOR);
	print_str_quoted(text);
	printf(")\n");
	init_fmt_text(&ftext, text);
	if (!ftext)
		return ;
	va_start(ftext->arguments, text);
	parse_argument(ftext);
	print_ftext(ftext);
	end_fmt_text(&ftext);
}

void	test_ftext(void)
{
	printf(" %sEstructura t_fmt_text%s\n", TITLE_COLOR, RESET_COLOR);
	print_test("%.1x", 42);
}
