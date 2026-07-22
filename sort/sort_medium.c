// --- icludes ---

#include "./sort.h"

// test
#include <stdio.h>

float my_sqrt(int x) {
	if (x < 0) return -1;
	if (x == 0) return 0;

	double guess = x;

	int i = 0;
	while (i < 30) {
		guess = (guess + x / guess) / 2.0;
		i++;
	}

	return guess;
}

int getMax(t_stack *stack) {
	int max = stack->first->val;
	t_element* currentElement = stack->first->next;
	while (currentElement) {
		if (currentElement->val > max) max = currentElement->val;
		currentElement = currentElement->next;
	}
	return max;
}

int getMin(t_stack* stack) {
	int min = stack->first->val;
	t_element* currentElement = stack->first->next;
	while (currentElement) {
		if (currentElement->val < min) min = currentElement->val;
		currentElement = currentElement->next;
	}
	return min;
}

static int isElementInBucket(t_element* element, t_element* bucket[], int count) {
	int i = 0;
	while (i < count) {
		if (bucket[i] == element)
			return 1;
		i++;
	}
	return 0;
}

void addBucketToStackB(t_element* bucket[], int count, t_stack_machine* machine) {
	t_stack* stack = &machine->stacks[0];
	int remaining = count;
	while (remaining > 0) {
		if (isElementInBucket(stack->first, bucket, count)) {
			machine_operation_execute(machine, PB);
			remaining--;
		} else {
			machine_operation_execute(machine, RA);
		}
	}
}

void addAllBucketsToStackB(int numberOfBuckets, int len,
	t_element* buckets[numberOfBuckets][len], int* numberOfElements,
	t_stack_machine* machine) {
	int execution = numberOfBuckets - 1;
	while (execution >= 0) {
		addBucketToStackB(buckets[execution], numberOfElements[execution], machine);
		execution--;
	}
}

void createBuckets(t_stack* aStack, int numberOfBuckets, long range, int min,
	int len, t_element* buckets[numberOfBuckets][len], int* numberOfElements) {
	t_element* currentElement = aStack -> first;
	while (currentElement) {
		long normalizedVal = (long)currentElement -> val - (long)min;
		int bucketNumber = (int)((normalizedVal * numberOfBuckets) / range);
		buckets[bucketNumber][numberOfElements[bucketNumber]] = currentElement;
		numberOfElements[bucketNumber]++;
		currentElement = currentElement -> next;
	}
}

void sortStack(t_stack* stack) {
	if (!stack || stack->len <= 1)
		return;
	t_element* current = stack->first->next;
	while (current) {
		t_element* node = current;
		t_element* prev = node->prev;
		while (prev && prev->val < node->val) {
			int tmp = prev->val;
			prev->val = node->val;
			node->val = tmp;
			node = prev;
			prev = node->prev;
		}
		current = current->next;
	}
}

void pushBtoA(t_stack_machine* machine) {
	if (!machine)
		return;
	while (machine->stacks[1].len > 0)
		machine_operation_execute(machine, PA);
}

void sort_medium(t_stack_machine* machine) {
	t_stack aStack = machine -> stacks[0];
	int max = getMax(&aStack);
	int min = getMin(&aStack);
	long range = (long)max - (long)min + 1;
	int numberOfBuckets = my_sqrt(aStack.len);

	int *numberOfElements = calloc(numberOfBuckets, sizeof(int));
	t_element* buckets[numberOfBuckets][aStack.len];

	createBuckets(&aStack, numberOfBuckets, range, min, aStack.len, buckets, numberOfElements);

	addAllBucketsToStackB(numberOfBuckets, aStack.len, buckets, numberOfElements, machine);
	sortStack(&machine->stacks[1]);
	pushBtoA(machine);

	free(numberOfElements);

	t_element* cursor = machine->stacks[0].first;
	while (cursor) {
		printf("%d\n", cursor->val);
		cursor = cursor->next;
	}
}