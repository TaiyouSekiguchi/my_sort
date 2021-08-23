/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:22:11 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/08/23 21:38:03 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <limits.h>

int	bubble_sort(int *array, size_t size);
int	insert_sort(int *array, size_t size);
int	selection_sort(int *array, size_t size);
int	heap_sort(int *array, size_t size);

static void array_put(int *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}

static void do_test(int *array, size_t size)
{
	printf("Before :");
	array_put(array, size);
	//bubble_sort(array, size);
	//insert_sort(array, size);
	//selection_sort(array, size);
	heap_sort(array, size);
	printf("After  :");
	array_put(array, size);
	printf("\n");
}

int main(void)
{
	int	test0[] = {33, 42, 1, 6, 873, 4343, INT_MIN, INT_MAX, 477762};
	int	test1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	test2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int test3[] = {1};
	int	test4[] = {};
	int test5[] = {42, 33};
	int test6[] = {2021, 42, 33};

	do_test(test0, (size_t)(sizeof(test0) / sizeof(test0[0])));
	do_test(test1, (size_t)(sizeof(test1) / sizeof(test1[0])));
	do_test(test2, (size_t)(sizeof(test2) / sizeof(test2[0])));
	do_test(test3, (size_t)(sizeof(test3) / sizeof(test3[0])));
	do_test(test4, (size_t)(sizeof(test4) / sizeof(test4[0])));
	do_test(test5, (size_t)(sizeof(test5) / sizeof(test5[0])));
	do_test(test6, (size_t)(sizeof(test6) / sizeof(test6[0])));

	return (0);
}
