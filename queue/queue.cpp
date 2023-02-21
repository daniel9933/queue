#include "queue.h"
#include <iostream>


void initQueue(Queue *q, unsigned int size)
{
	q->maxSize = size;
	q->count = 0;
	q->elements = new int[q->maxSize];
	q->empty = true;
}

void cleanQueue(Queue* q)
{
	delete[] q->elements;
}

bool isEmpty(Queue* q)
{
	return q->empty;
}

bool isFull(Queue* q)
{
	return (q->count == q->maxSize);
}



void enqueue(Queue* q, unsigned int newValue)
{
	if(!isFull(q))//if queue isn't full 
	{
		q->elements[q->count] = newValue;//insert the value in the count position at the array
		q->count++;//add one to the count to advance the queue.
		q->empty = false;//queue isn't full anymore.
	}
}

int dequeue(Queue* q)
{
	if (isEmpty(q))
	{
		return -1;
	}

	else
	{
		int ans = q->elements[0];//save the answer we need to return.
		unsigned int i = 0;

		for (i = 1; i < q->count; i++)
		{
			q->elements[i - 1] = q->elements[i];//every element is now equal to the one after him.

		}
		q->count--;
		q->empty = (q->count == 0);

		return ans;
	}
}