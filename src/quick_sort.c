/*
 * quick_sort.c
 *
 *  Created on: Jan 8, 2016
 *      Author: rafael
 */

#include "quick_sort.h"

static void _print(int *nums, int size) {
	int i = 0;

	for (; i < size; i++) {
		printf("%d ", nums[i]);
	}

	printf("\n");
}

static void _quickSort(int *nums, int start, int end) {
	if (start >= end) {
		return;
	}

	int left = start;
	int right = end;
	int key = nums[start];

	while (left < right) {
		while (left < right && key <= nums[right]) {
			right--;
		}

		nums[left] = nums[right];

		while (left < right && key >= nums[left]) {
			left++;
		}

		nums[right] = nums[left];
	}

	nums[left] = key;
	_quickSort(nums, start, left - 1);
	_quickSort(nums, left + 1, end);
}

static void _run() {
	int nums[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	int size = sizeof(nums) / sizeof(int);

	_print(nums, size);
	_quickSort(nums, 0, size - 1);
	_print(nums, size);
}

void quickSort() {
	_run();
}
