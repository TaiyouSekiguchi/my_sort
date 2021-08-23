/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:43:51 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/08/23 14:36:04 by tsekiguc         ###   ########.fr       */
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

int	bubble_sort(int *array, size_t size)
{
	size_t	flag;
	size_t	i;

	if (array == NULL || size == 0)
		return (1);
	if (size == 1)
		return (0);
	flag = size - 1;
	while (flag > 0)
	{
		i = 0;
		while (i < flag)
		{
			if (array[i] > array[i + 1])
				swap(&array[i], &array[i + 1]);
			i++;
		}
		flag--;
	}
	return (0);
}
