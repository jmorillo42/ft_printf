/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:31:54 by jmorillo          #+#    #+#             */
/*   Updated: 2022/07/09 16:26:45 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_int_len(int number)
{
	size_t	count;

	count = 0;
	if (number <= 0)
		count++;
	while (number)
	{
		number = number / 10;
		count++;
	}
	return (count);
}
