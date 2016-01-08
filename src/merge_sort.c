/*
 * merge_sort.c
 *
 *  Created on: Jan 8, 2016
 *      Author: rafael
 */

#include "merge_sort.h"

static void _merge(int *unsorted, int l, int m, int r, int *sorted) {
	int i = l;
	int j = m;
	int k = 0;

	while (i < m && j < r) {
		if (unsorted[i] < unsorted[j]) {
			sorted[k++] = unsorted[i++];
		} else {
			sorted[k++] = unsorted[j++];
		}
	}

	if (i == m) {
		while (j < r) {
			sorted[k++] = unsorted[j++];
		}
	} else if (j == r) {
		while (i < m) {
			sorted[k++] = unsorted[i++];
		}
	}

	for (i = 0; i < k; i++) {
		unsorted[l + i] = sorted[i];
	}
}

static void _sort(int *unsorted, int l, int r, int *sorted) {
	if (l + 1 < r) {
		int m = (r + l) / 2;

		_sort(unsorted, l, m, sorted);
		_sort(unsorted, m, r, sorted);
		_merge(unsorted, l, m, r, sorted);
	}
}

static void _mergeSort(int *unsorted, int *sorted, int size) {
	if (NULL == unsorted) {
		return;
	}

	if (1 == size) {
		sorted[0] = unsorted[0];
	}

	_sort(unsorted, 0, size, sorted);
}

#define SIZE 11

static void _run() {
	int unsorted[] = { 4, 33, 34, 21, 9, 39, 22, 18, 7, -100, 100 };
	int *sorted = (int *) malloc(SIZE * sizeof(int));
	int i = 0;

	for (; i < SIZE; i++) {
		printf("%d ", unsorted[i]);
	}

	printf("\n");
	_mergeSort(unsorted, sorted, SIZE);

	for (i = 0; i < SIZE; i++) {
		printf("%d ", sorted[i]);
	}

	printf("\n");
	free(sorted);
}

void mergeSort() {
	_run();
}
