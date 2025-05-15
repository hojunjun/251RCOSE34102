#ifndef QUEUE_H
#define QUEUE_H

#include "types.h"

void init_queue(Queue *q);
void init_queues();
int is_empty(Queue *q);
int is_full(Queue *q);
void enqueue(Queue *q, Process *p);
Process *dequeue(Queue *q);

void remove_process(Queue *q, Process *p);

Process *get_shortest_job(Queue *q);
Process *get_highest_priority(Queue *q);

void reset_queues();
void update_queues();

#endif