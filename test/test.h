/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:54:07 by jmorillo          #+#    #+#             */
/*   Updated: 2022/07/10 21:27:33 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "ft_printf.h"
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# define RED "\e[31m"
# define GREEN "\e[32m"
# define BLUE "\e[34m"
# define YELLOW "\e[33m"
# define CYAN "\e[36m"
# define MAGENTA "\e[35m"

# define L_RED "\e[1;31m"
# define L_GREEN "\e[1;32m"
# define L_BLUE "\e[1;34m"
# define L_YELLOW "\e[1;33m"
# define L_CYAN "\e[1;36m"
# define L_MAGENTA "\e[1;35m"

# define TITLE_COLOR "\e[1;33;44m"
# define FUNCTION_COLOR "\e[33m"
# define RESET_COLOR "\e[0m"

# define BLUE_NULL "\e[1;34mNULL\e[0m"
# define TEST_ITEM "\e[36m>\e[0m"
# define ARROW "\e[36m-->\e[0m"
# define LEFT_DQUOTE "\e[1;30m‟\e[0m"
# define RIGHT_DQUOTE "\e[1;30m”\e[0m"
# define LEFT_SQUOTE "\e[1;30m‛\e[0m"
# define RIGHT_SQUOTE "\e[1;30m’\e[0m"
# define LEFT_BRACKET "\e[36m[\e[0m"
# define RIGHT_BRACKET "\e[36m]\e[0m"
# define EQUAL "\e[36m=\e[0m"
# define ELEMENT "\e[36m+\e[0m"
# define GREEN_CHECK "\e[1;32m ✓ \e[0m"
# define RED_CROSS "\e[1;31m ✖ \e[0m"

# define F_OUTPUT_1 "printf.output"
# define F_OUTPUT_2 "ft_printf.output"

typedef union u_arg
{
	char			c;
	char			*s;
	int				i;
	unsigned int	u;
	unsigned long	p;
}	t_u_arg;

typedef struct s_arg
{
	char	type;
	t_u_arg	value;
}	t_arg;

void	print_char_quoted(char c);
void	print_str_quoted(char *text);
void	print_expected_string(char *text, t_arg arg);
void	print_input_arguments(char *text, t_arg arg);
int		ft_printf_varg(char *text, t_arg varg);
int		printf_varg(char *text, t_arg varg);
void	print_line_test(char *text, t_arg varg);

int		stdout_to_file(char *file, int *fd_stdout);
int		restore_stdout(int *fd_stdout);
int		compare_files(char *file1, char *file2);
int		printf_to_file(char *text, t_arg varg);
int		ft_printf_to_file(char *text, t_arg varg);

void	assert_equal_text(char *text, t_arg varg);
void	assert_equal_count(int count_lib, int count_ft);

void	test_ftext(void);
void	test_char(void);
void	test_percent(void);
void	test_str(void);
void	test_int(void);
void	test_unsigned(void);
void	test_hex(void);
void	test_pointer(void);

#endif
