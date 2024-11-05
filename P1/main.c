#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct
{
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

CircularQueue* createQueue(void);
_Bool isFull(CircularQueue* q);
_Bool isEmpty(CircularQueue* q);
void clear_queue(CircularQueue* q);

CircularQueue* createQueue(void)
{
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = -1;
    q->rear = -1;
    return q;
}

_Bool isFull(CircularQueue* q)
{
    return (q->rear + 1) % MAX == q->front;
}

_Bool isEmpty(CircularQueue* q)
{
    return q->front == -1;
}

void enqueue(CircularQueue* q, int value)
{
    if (isFull(q))
    {
        q->front = (q->front + 1) % MAX; // Overwrite oldest data
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    if (q->front == -1)
    {
        q->front = 0;
    }
}

int dequeue(CircularQueue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

void clear_queue(CircularQueue* q)
{
    q->front = -1;
    q->rear = -1;
}

int main(void)
{
    CircularQueue* q = createQueue();
    int choice, value;

    while (1)
        {
        printf("1. Write to Queue\n2. Dequeue\n3. Clear Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to dequeue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1)
                {
                    printf("clear_queued: %d\n", value);
                }
                break;
            case 3:
                clear_queue(q);
                printf("Queue cleared\n");
                break;
            case 4:
                free(q);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
