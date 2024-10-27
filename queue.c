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
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = element;
    newNode->next = *head;
    *head = newNode;
}

int pop(node **head) {
    assert(*head != NULL);
    node* temp = *head;
    int popped = temp->data;
    *head = (*head)->next;
    free(temp);
    return popped;
}

void enqueueStack(queue *q, int x) {
    push(x, &q->front);
    q->size++;
}

int dequeueStack(queue *q) {
    if (q->rear ==NULL) {
        while (q->front != NULL) {
            int element = pop(&q->front);
            push(element, &q->rear);
        }
    }
    assert(q->rear != NULL);
    q->size--;
    return pop(&q->rear);
}
