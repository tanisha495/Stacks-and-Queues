#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full (Overflow)\n");
        return;
    }
    if (front == -1) // First element
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    queue[rear] = value;
    printf("%d enqueued\n", value);
}
// Dequeue
void dequeue() {
    if (front == -1) {
        printf("Queue is empty (Underflow)\n");
        return;
    }
    int deleted = queue[front];

    if (front == rear) 
        front = rear = -1;
    else
        front = (front + 1) % SIZE;

    printf("%d dequeued\n", deleted);
}
//Front element
void peek() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is: %d\n", queue[front]);
}
// Display queue
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    dequeue();
    display();
    peek();
    return 0;
}
