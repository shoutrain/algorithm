/*
 * merge_sort.c
 *
 *  Created on: Jan 8, 2016
 *      Author: rafael
 */

#include "merge_sort.h"

static void _merge(int *unsorted, int l, int m, int r, int *sorted) {
	int i = l;
	int j = m + 1;
	int k = 0;

	while (i < m + 1 && j < r + 1) {
		if (unsorted[i] < unsorted[j]) {
			sorted[k++] = unsorted[i++];
		} else {
			sorted[k++] = unsorted[j++];
		}
	}

	if (i == m + 1) {
		while (j < r + 1) {
			sorted[k++] = unsorted[j++];
		}
	} else if (j == r + 1) {
		while (i < m + 1) {
			sorted[k++] = unsorted[i++];
		}
	}

	for (i = 0; i < k; i++) {
		unsorted[l + i] = sorted[i];
	}
}

static void _sort(int *unsorted, int l, int r, int *sorted) {
	if (l < r) {
		int m = (r + l) / 2;

		_sort(unsorted, l, m, sorted);
		_sort(unsorted, m + 1, r, sorted);
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

	_sort(unsorted, 0, size - 1, sorted);
}

static void _run() {
	int unsorted[] = { 4, 33, 34, 21, 9, 39, 22, 18, 7, -100, 100 };
	int size = sizeof(unsorted) / sizeof(int);
	int *sorted = (int *) malloc(sizeof(unsorted));
	int i = 0;

	for (; i < size; i++) {
		printf("%d ", unsorted[i]);
	}

	printf("\n");
	_mergeSort(unsorted, sorted, size);

	for (i = 0; i < size; i++) {
		printf("%d ", sorted[i]);
	}

	printf("\n");
	free(sorted);
}

void mergeSort() {
	_run();
}
