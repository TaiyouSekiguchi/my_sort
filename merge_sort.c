/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:37:11 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/08/24 10:27:32 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void merge(int *new1, int n1_size, int *new2, int n2_size, int *array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n1_size || j < n2_size)
	{
		if (j >= n2_size || (i < n1_size && new1[i] < new2[j]))
		{
			array[i + j] = new1[i];
			i++;
		}
		else
		{
			array[i + j] = new2[j];
			j++;
		}
	}
}

int	merge_sort(int *array, size_t size)
{
	int	*new1;
	int	*new2;
	int	right;
	int	left;
	int	i;

	if (array == NULL || size == 0)
		return (0);
	if (size == 1)
		return (1);

	if (size > 1)
	{
		right = size / 2;
		left = size - right;

		new1 = (int *)malloc(sizeof(int) * right);
		if (new1 == NULL)
			return (1);
		new2 = (int *)malloc(sizeof(int) * left);
		if (new2 == NULL)
			return (1);

		i = 0;
		while (i < right)
		{
			new1[i] = array[i];
			i++;
		}
		i = 0;
		while (i < left)
		{
			new2[i] = array[right + i];
			i++;
		}
		merge_sort(new1, right);
		merge_sort(new2, left);
		merge(new1, right, new2, left, array);
	}
	free(new1);
	free(new2);
	return (0);
}
