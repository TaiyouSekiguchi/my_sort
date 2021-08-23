/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:29:07 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/08/23 14:38:04 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static void swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	insert_sort(int *array, size_t size)
{
	size_t	flag;
	size_t	i;

	if (array == NULL || size == 0)
		return (1);
	i = 1;
	while (i < size)
	{
		flag = i;
		while ((flag > 0) && (array[flag - 1] > array[flag]))
		{
			swap(&array[flag - 1], &array[flag]);
			flag--;
		}
		i++;
	}
	return (0);
}
