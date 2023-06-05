/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:23:42 by jmorillo          #+#    #+#             */
/*   Updated: 2022/07/10 17:36:28 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	stdout_to_file(char *file, int *fd_stdout)
{
	int	fd1;

	fflush(stdout);
	fd1 = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd1 < 0)
	{
		fprintf(stderr, "Failed to open %s for writing\n", file);
		return (-1);
	}
	*fd_stdout = dup(STDOUT_FILENO);
	if (*fd_stdout < 0)
	{
		fprintf(stderr, "Failed to duplicate standard output\n");
		return (-1);
	}
	if (dup2(fd1, STDOUT_FILENO) < 0)
	{
		fprintf(stderr, "Failed to duplicate %s to standard output\n", file);
		return (-1);
	}
	close(fd1);
	return (0);
}

int	restore_stdout(int *fd_stdout)
{
	fflush(stdout);
	if (dup2(*fd_stdout, STDOUT_FILENO) < 0)
	{
		fprintf(stderr, "Failed to reinstate standard output\n");
		return (-1);
	}
	close(*fd_stdout);
	return (0);
}

int	compare_files(char *file1, char *file2)
{
	FILE	*fp1;
	FILE	*fp2;
	char	ch1;
	char	ch2;

	fp1 = fopen(file1, "r");
	fp2 = fopen(file2, "r");
	if (!fp1 || !fp2)
	{
		fprintf(stderr, "Failed to open files.\n");
		return (-1);
	}
	ch1 = 0;
	ch2 = 0;
	while (ch1 != EOF && ch2 != EOF)
	{
		ch1 = fgetc(fp1);
		ch2 = fgetc(fp2);
		if (ch1 != ch2)
			return (0);
	}
	fclose(fp1);
	fclose(fp2);
	return (ch1 == EOF && ch2 == EOF);
}

int	ft_printf_to_file(char *text, t_arg varg)
{
	int	count;
	int	stdout_backup;

	stdout_to_file(F_OUTPUT_1, &stdout_backup);
	count = ft_printf_varg(text, varg);
	restore_stdout(&stdout_backup);
	return (count);
}

int	printf_to_file(char *text, t_arg varg)
{
	int	count;
	int	stdout_backup;

	stdout_to_file(F_OUTPUT_2, &stdout_backup);
	count = printf_varg(text, varg);
	restore_stdout(&stdout_backup);
	return (count);
}
