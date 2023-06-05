/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:24:40 by jmorillo          #+#    #+#             */
/*   Updated: 2022/07/10 18:27:19 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	assert_equal_text(char *text, t_arg varg)
{
	if (compare_files(F_OUTPUT_1, F_OUTPUT_2))
		printf("%s", GREEN_CHECK);
	else
	{
		print_expected_string(text, varg);
		printf("%s", RED_CROSS);
	}
}

void	assert_equal_count(int count_lib, int count_ft)
{
	if (count_lib == count_ft)
		printf("%s", GREEN_CHECK);
	else
	{
		printf(" [%s%d%s]", L_RED, count_lib, RESET_COLOR);
		printf("%s", RED_CROSS);
	}
}
