/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:01:19 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/08/23 22:57:00 by tsekiguc         ###   ########.fr       */
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

static void heap_put(int *array, size_t size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}

static void	make_heap(int *array, size_t size)
{
	size_t	flag;
	size_t	pos;
	size_t	child1;
	size_t	child2;
	size_t	big;

	if (array == NULL || size == 0)
		return ;
	if (size == 1)
		return ;

	flag = ((size - 1) - 1) / 2;
	pos = flag;
	while (1)
	{
		child1 = pos * 2 + 1;
		child2 = child1 + 1;
		if (child2 < size)
		{
			if (array[child1] > array[child2])
				big = child1;
			else
				big = child2;
			if (array[pos] < array[big])
			{
				swap(&array[pos], &array[big]);
				pos = big;
				continue;
			}
		}
		else if (child1 < size)
		{
			if (array[pos] < array[child1])
			{
				swap(&array[pos], &array[child1]);
				pos = child1;
				continue;
			}
		}
		if (flag == 0)
			break ;
		flag -= 1;
		pos = flag;
	}
}

int	heap_sort(int *array, size_t size)
{
	size_t	i;

	if (array == NULL || size == 0)
		return (1);
	if (size == 1)
		return (0);
	make_heap(array, size);
	i = size - 1;
	while (i > 0)
	 {
		swap(&array[0], &array[i]);
		make_heap(array, i);
		i--;
	 }
	 return (0);
}
