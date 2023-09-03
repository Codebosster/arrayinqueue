#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Queue {
    struct Node* front;
    struct Node* rear;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}


void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    
    queue->rear->next = newNode;
    queue->rear = newNode;
}


int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    
    struct Node* temp = queue->front;
    int data = temp->data;
    
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    
    return data;
}

int main() {
    struct Queue* queue = createQueue();
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    
    return 0;
}
