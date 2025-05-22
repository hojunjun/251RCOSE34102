#ifndef TYPES_H
#define TYPES_H

#define MAX_PROCESSES 10
#define MAX_ARRIVAL_TIME 50
#define MAX_BURST_TIME 20
#define MIN_BURST_TIME 6
#define MAX_PRIORITY 10
#define MAX_QUEUE_SIZE MAX_PROCESSES
#define TIME_QUANTUM 4
#define MAX_IO 3
#define MAX_IO_BURST_TIME 5
#define MAX_TIME MAX_ARRIVAL_TIME + MAX_PROCESSES * (MAX_BURST_TIME + MAX_IO * MAX_IO_BURST_TIME)
#define RR_TIME_QUANTUM 2

typedef enum {
    READY,
    RUNNING,
    WAITING,
    TERMINATED
} ProcessState;

typedef struct {
    int request_time;
    int burst_time;
    int io_time;
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

#endif
