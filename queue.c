#include <stdio.h>
#include <assert.h>
#include "queue.h"
#include <stdlib.h>
#include <stdbool.h>

void initialize(queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool empty(const queue *q) {
    return q->size == 0;
}


bool full(const queue *q) {
    return false; /*som sidst kan den aldrig være fuld da det er en linked list*/
}

void enqueue(queue *q, int x) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;

    if (q->rear == NULL) { /*hvis den var tom før*/
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear =newNode;
    }
    q->size++;
}

int dequeue(queue *q){
    assert(q->size > 0);

    node* temp = q->front;
    int dequeued = temp->data;

    q->front = q->front->next;

    if (q-> front == NULL) { /*hvis den tømmes*/
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return dequeued;
}


// Opgave 4
void push(int element, node **head) {

}

int pop(node **head) {
    return -1;
}

void enqueueStack(queue *q, int x) {

}

int dequeueStack(queue *q) {
    return -1;
}
