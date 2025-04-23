void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return;
    }
    printf("Removed %d\n", q->items[q->front]);
    q->front++;
    if (q->front > q->rear) {
        // Reset the queue when all elements are dequeued
        q->front = -1;
        q->rear = -1;
    }
}

