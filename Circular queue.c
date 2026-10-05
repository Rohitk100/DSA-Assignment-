#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

/* ENQUEUE operation */
void enqueue(int value)
{
    /* Check whether queue is full */
    if ((rear + 1) % MAX == front)
    {
        printf("\nQueue Overflow! Queue is full.\n");
        return;
    }

    /* First element */
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;

    printf("\n%d inserted into the circular queue.\n", value);
}

/* DEQUEUE operation */
void dequeue()
{
    int value;

    if (front == -1)
    {
        printf("\nQueue Underflow! Queue is empty.\n");
        return;
    }

    value = queue[front];

    printf("\n%d deleted from the circular queue.\n", value);

    /* Only one element was present */
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

/* FRONT operation */
void showFront()
{
    if (front == -1)
    {
        printf("\nQueue is empty. No front element.\n");
        return;
    }

    printf("\nFront element = %d\n", queue[front]);
}

/* DISPLAY operation */
void display()
{
    int i;

    if (