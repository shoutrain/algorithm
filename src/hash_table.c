/*
 * hash_table.c
 *
 *  Created on: Jan 12, 2016
 *      Author: rafael
 */

#include "hash_table.h"

#define HASH_TABLE_SIZE 65535

struct Node {
	int key;
	int value;
	struct Node *next;
};

static struct Node *_hash_table[HASH_TABLE_SIZE];

static unsigned short _hash(int key) {
	unsigned short first = 0x0000FFFF & key;
	unsigned short second = key >> 16;

	return first ^ second;
}

static void _clear(struct Node *node) {
	if (NULL != node) {
		_clear(node->next);
	}

	free(node);
}

static void _printList(struct Node *node) {
	if (NULL != node) {
		printf(" key: %d - value: %d", node->key, node->value);
		_printList(node->next);
	}
}

void initHashTable() {
	memset(_hash_table, 0, sizeof(_hash_table));
}

void deinitHashTable() {
	int i = 0;

	for (; i < HASH_TABLE_SIZE; i++) {
		_clear(_hash_table[i]);
	}
}

bool insertValue(int key, int value) {
	unsigned short hashKey = _hash(key);

	if (NULL == _hash_table[hashKey]) {
		_hash_table[hashKey] = (struct Node *)malloc(sizeof(struct Node));
		_hash_table[hashKey]->key = key;
		_hash_table[hashKey]->value = value;
		_hash_table[hashKey]->next = NULL;

		return true;
	} else {
		struct Node **pp = &_hash_table[hashKey];

		do {
			if ((*pp)->key == key) {
				return false;
			}

			*pp = (*pp)->next;
		} while (NULL != *pp);

		*pp = (struct Node *)malloc(sizeof(struct Node));
		(*pp)->key = key;
		(*pp)->value = value;
		(*pp)->next = NULL;

		return true;
	}
}

bool deleteKey(int key) {
	unsigned short hashKey = _hash(key);

	if (NULL == _hash_table[hashKey]) {
		return false;
	}

	struct Node **pp = &_hash_table[hashKey];

	do {
		if ((*pp)->key == key) {
			struct Node *q = *pp;

			if (NULL != (*pp)->next) {
				*pp = (*pp)->next;
			} else {
				*pp = NULL;
			}

			free(q);

			return true;
		}

		*pp = (*pp)->next;
	} while (NULL != *pp);

	return false;
}

bool findKey(int key, int *value) {
	unsigned short hashKey = _hash(key);

	if (NULL == _hash_table[hashKey]) {
		return false;
	}

	struct Node *p = _hash_table[hashKey];

	do {
		if (p->key == key) {
			*value = p->value;

			return true;
		}

		p = p->next;
	} while (NULL != p);

	return false;
}

static void _printAll() {
	int i = 0;

	for (; i < HASH_TABLE_SIZE; i++) {
		if (NULL != _hash_table[i]) {
			printf("hashKey: %d", i);
			_printList(_hash_table[i]);
			printf("\n");
		}
	}

	printf("\n");
}

static void _run() {
	initHashTable();

	insertValue(12341234, 1);
	insertValue(234234323, 2);
	insertValue(456345, 3);
	insertValue(234236243, 4);
	_printAll();

	deleteKey(234236243);
	_printAll();

	deinitHashTable();
}

void hash_table() {
	_run();
}
