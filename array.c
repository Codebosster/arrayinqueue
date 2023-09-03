#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty() {
    return front == -1 && rear == -1;
}

void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = data;
}

int dequeue() {
    int data;
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else if (front == rear) {
        data = queue[front];
        front = rear = -1;
    } else {
        data = queue[front];
        front++;
    }
    return data;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    
    return 0;
}
