/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:19:38 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/08/24 15:13:48 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	search_pivot(int *array, int first, int last)
{
	int	pivot;

	pivot = first + 1;
	while (pivot <= last && array[first] == array[pivot])
		pivot++;
	if (pivot > last)
		return (-1);
	if (array[first] >= array[pivot])
		return (first);
	return (pivot);
}

static int search_partition(int *array, int first, int last, int pivot)
{
	int	left;
	int	right;
	int	tmp;

	left = first;
	right = last;
	while (left <= right)
	{
		while (left <= last && array[left] < pivot)
			left++;
		while (right >= first && array[right] >= pivot)
			right--;
		if (left > right)
			break;
		tmp = array[left];
		array[left] = array[right];
		array[right] = tmp;
		left++;
		right--;
	}
	return (left);
}

static void	do_sort(int *array, size_t size, int first, int last)
{
	int	pivot;
	int	partition;

	if (first == last)
		return ;

	pivot = search_pivot(array, first, last);
	if (pivot == -1)
		return ;

	partition = search_partition(array, first, last, array[pivot]);
	do_sort(array, size, first, partition - 1);
	do_sort(array, size, partition, last);
}

int	quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (0);
	if (size == 1)
		return (1);

	do_sort(array, size, 0, size - 1);
	return (1);
}
