/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:37:11 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/09/02 09:34:54 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void merge(int *src1, int s1_size, int *src2, int s2_size, int *dst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < s1_size || j < s2_size)
	{
		if (j >= s2_size || (i < s1_size && src1[i] < src2[j]))
		{
			dst[i + j] = src1[i];
			i++;
		}
		else
		{
			dst[i + j] = src2[j];
			j++;
		}
	}
}

int	merge_sort(int *array, size_t size)
{
	int	*new1;
	int	*new2;
	int	left;
	int	right;
	int	i;

	if (array == NULL || size == 0)
		return (0);
	if (size == 1)
		return (1);

	if (size > 1)
	{
		left = size / 2;
		right = size - left;

		new1 = (int *)malloc(sizeof(int) * left);
		if (new1 == NULL)
			return (0);
		new2 = (int *)malloc(sizeof(int) * right);
		if (new2 == NULL)
			return (0);

		i = 0;
		while (i < left)
		{
			new1[i] = array[i];
			i++;
		}
		i = 0;
		while (i < right)
		{
			new2[i] = array[left + i];
			i++;
		}
		merge_sort(new1, left);
		merge_sort(new2, right);
		merge(new1, left, new2, right, array);
	}
	free(new1);
	free(new2);
	return (1);
}
