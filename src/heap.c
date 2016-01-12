/*
 * heap.c
 *
 *  Created on: Jan 12, 2016
 *      Author: rafael
 */

#include "heap.h"

#define HEAP_MAX_SIZE 65535

static int _heap[HEAP_MAX_SIZE];

static void _insert(int index) {
	if (1 == index) {
		return;
	}

	int pIndex = 0;

	if (0 == index % 2) { // left
		pIndex = index / 2;
	} else { // right
		pIndex = (index - 1) / 2;
	}

	if (_heap[pIndex] < _heap[index]) {

		_heap[pIndex] ^= _heap[index];
		_heap[index] ^= _heap[pIndex];
		_heap[pIndex] ^= _heap[index];

		_insert(pIndex);
	}
}

void init_heap() {
	memset(_heap, 0, sizeof(_heap));
}

void insert_heap(int v) {
	if (0 == _heap[0]) {
		_heap[1] = v;
		_heap[0] = 1;

		return;
	}

	_heap[0]++;
	_heap[_heap[0]] = v;
	_insert(_heap[0]);
}

static void _printAll() {
	printf("Size: %d\n", _heap[0]);

	int i = 1;

	for (; i <= _heap[0]; i++) {
		printf("%d ", _heap[i]);
	}

	printf("\n\n");
}

static void _run() {
	init_heap();
	insert_heap(1);
	_printAll();
	insert_heap(2);
	_printAll();
	insert_heap(3);
	_printAll();
	insert_heap(4);
	_printAll();
	insert_heap(5);
	_printAll();
	insert_heap(6);
	_printAll();
	insert_heap(7);
	_printAll();
}

void heap() {
	_run();
}
