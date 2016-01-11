/*
 * remove_extra_backet.c
 *
 *  Created on: Jan 11, 2016
 *      Author: rafael
 */

#include "remove_extra_backet.h"

struct Node {
	char v;
	struct Node *next;
};

static struct Node *_head;

static void _push(char v) {
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));

	if (NULL == _head) {
		node->next = NULL;
	} else {
		node->next = _head;
	}

	node->v = v;
	_head = node;
}

static char _pop() {
	if (NULL == _head) {
		printf("Nothing in stack\n");

		return 0;
	}

	struct Node *n = _head;
	char tmp = _head->v;

	_head = _head->next;

	free(n);

	return tmp;
}

static void _run() {
	char r[128];
	int i = 0;

	for (; i < 128; i++) {
		r[i] = 0;
	}

	scanf("%s", r);
	i = 0;

	while ('\0' != r[i]) {
		if ('(' == r[i]) {
			if ('(' == r[i + 1]) {
				_push(-(i + 1));
			} else {
				_push(i + 1);
			}

			i++;
		} else if (')' == r[i]) {
			if (')' == r[i - 1] && _head->v < 0) {
				r[-(_head->v + 1)] = '$';
				r[i] = '$';
				_pop();
			} else if (')' == r[i - 1] && _head->v > 0) {
				printf("Something is wrong\n");

				return;
			} else {
				_pop();
			}

			i++;
		} else {
			i++;
		}
	}

	for (i = 0; i < 128 && '\0' != r[i]; i++) {
		if ('$' != r[i]) {
			printf("%c", r[i]);
		}
	}
}

void remove_extra_backet() {
	_run();
}
