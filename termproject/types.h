#ifndef TYPES_H
#define TYPES_H

#define MAX_PROCESSES 100
#define MAX_TIME 10000
#define MAX_QUEUE_SIZE 100
#define TIME_QUANTUM 4
#define MAX_IO 5

typedef enum {
    READY,
    RUNNING,
    WAITING,
    TERMINATED
} ProcessState;

typedef struct {
    int request_time;
    int burst_time;
    int completed;
} IO;

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;

    int waiting_time;
    int turnaround_time;
    int completion_time;
    int response_time;

    ProcessState state;

    int io_count;
    IO io[MAX_IO];
    int current_io;
    int cpu_time;
} Process;

typedef struct {
    Process *processes[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

typedef struct {
    int pid;
    int start_time;
    int end_time;
} GanttItem;

extern Process processes[MAX_PROCESSES];
extern Process current_processes[MAX_PROCESSES];
extern int num_processes;
extern int completed_processes;
extern Queue ready_queue;
extern Queue waiting_queue;
extern GanttItem gantt[MAX_TIME];
extern int num_gantt_items;
extern int current_time;

#endif
