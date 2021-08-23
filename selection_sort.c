/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:45:47 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/08/23 14:51:54 by tsekiguc         ###   ########.fr       */
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

int	selection_sort(int *array, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	min;

	if (array == NULL || size == 0)
		return (1);
	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[min] > array[j])
				min = j;
			j++;
		}
		swap(&array[i], &array[min]);
		i++;
	}
	return (0);
}
