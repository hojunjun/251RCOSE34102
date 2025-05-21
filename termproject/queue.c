#include "queue.h"
#include <stdio.h>

void init_queue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void init_queues() {
    init_queue(&ready_queue);
    init_queue(&waiting_queue);
}

int is_empty(Queue *q) {
    return q->size == 0;
}

int is_full(Queue *q) {
    return q->size == MAX_QUEUE_SIZE;
}

void enqueue(Queue *q, Process *p) {
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->processes[q->rear] = p;
    q->size++;
}

Process *dequeue(Queue *q) {
    if (is_empty(q)) {
        return NULL;
    }
    Process *p = q->processes[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;
    return p;
}

void remove_process(Queue *q, Process *p) {
    if (is_empty(q)) {
        return;
    }
    
    int i, j;
    for (i = 0; i < q->size; i++) {
        int idx = (q->front + i) % MAX_QUEUE_SIZE;
        if (q->processes[idx] == p) {
            // Shift remaining elements
            for (j = i; j < q->size - 1; j++) {
                int curr = (q->front + j) % MAX_QUEUE_SIZE;
                int next = (q->front + j + 1) % MAX_QUEUE_SIZE;
                q->processes[curr] = q->processes[next];
            }
            q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            q->size--;
            return;
        }
    }
}

Process *get_shortest_job(Queue *q) {
    if (is_empty(q)) {
        return NULL;
    }
    
    Process *shortest = q->processes[q->front];
    int shortest_idx = q->front;
    
    for (int i = 1; i < q->size; i++) {
        int idx = (q->front + i) % MAX_QUEUE_SIZE;
        if (q->processes[idx]->remaining_time < shortest->remaining_time) {
            shortest = q->processes[idx];
            shortest_idx = idx;
        }
    }
    
    for (int i = shortest_idx; i < q->size - 1; i++) {
        int curr = (q->front + i) % MAX_QUEUE_SIZE;
        int next = (q->front + i + 1) % MAX_QUEUE_SIZE;
        q->processes[curr] = q->processes[next];
    }
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    q->size--;
    
    return shortest;
}

Process *get_highest_priority(Queue *q) {
    if (is_empty(q)) {
        return NULL;
    }
    
    Process *highest = q->processes[q->front];
    int highest_idx = q->front;
    
    for (int i = 1; i < q->size; i++) {
        int idx = (q->front + i) % MAX_QUEUE_SIZE;
        if (q->processes[idx]->priority < highest->priority) {
            highest = q->processes[idx];
            highest_idx = idx;
        }
    }
    
    for (int i = highest_idx; i < q->size - 1; i++) {
        int curr = (q->front + i) % MAX_QUEUE_SIZE;
        int next = (q->front + i + 1) % MAX_QUEUE_SIZE;
        q->processes[curr] = q->processes[next];
    }
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    q->size--;
    
    return highest;
}

void reset_queues() {
    init_queues();
}

void update_queues() {
    for (int i = 0; i < ready_queue.size; i++) {
        int index = (ready_queue.front + i) % MAX_QUEUE_SIZE;
        ready_queue.processes[index]->waiting_time++;
    }
} 