#include <stdio.h>
#include <stdlib.h>
#include "dataStructures/commons.h"

struct queue
{
    struct processBlock *items;     // array to store queue elements
    int maxsize;    // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int size;       // current capacity of the queue
};
 
struct queue* newQueue(int size)
{
    struct queue *pt = NULL;
    pt = (struct queue*)malloc(sizeof(struct queue));
 
    pt->items = (struct processBlock*)malloc(size * sizeof(struct processBlock));
    pt->maxsize = size;
    pt->front = 0;
    pt->rear = -1;
    pt->size = 0;
 
    return pt;
}
 
int size(struct queue *pt) {
    return pt->size;
}
 
int isEmpty(struct queue *pt) {
    return !size(pt);
}
 
struct processBlock * front(struct queue *pt)
{
    if (isEmpty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    return &pt->items[pt->front];
}
 
void enqueue(struct queue *pt, struct processBlock* x)
{
    if (size(pt) == pt->maxsize)
    {
        printf("Overflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    pt->rear = (pt->rear + 1) % pt->maxsize;    // circular queue
    pt->items[pt->rear] = *x;
    pt->size++;
 
    printf("front = %d, rear = %d\n", pt->front, pt->rear);
}
 
void dequeue(struct queue *pt)
{
    if (isEmpty(pt))    // front == rear
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    pt->front = (pt->front + 1) % pt->maxsize;  // circular queue
    pt->size--;
 
    printf("front = %d, rear = %d\n", pt->front, pt->rear);
}