#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// enqueue
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue %d.\n", value);
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("%d enqueued into the queue.\n", value);
    }
}
//dequeue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Nothing to dequeue.\n");
    } else {
        printf("%d dequeued from the queue.\n", queue[front]);
        front++;
    }
}
//view the front element
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main() {
   
    enqueue(10);
    enqueue(20);
    enqueue(30);   
    dequeue();    
    peek();   
    display();   
    printf("Exiting program.\n");
    return 0;
}
