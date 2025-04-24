#include <stdio.h>
#define SIZE 100

struct Queue {
    int items[SIZE];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q) {
    return q->rear == SIZE - 1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1 || q->front > q->rear;
}


void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front++;
    // Reset the queue if it's now empty
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return value;
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    display(&q);

    enqueue(&q, 40);
    display(&q);

    return 0;
}
