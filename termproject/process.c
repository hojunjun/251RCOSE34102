#include "process.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>

void init_processes() {
    for (int i = 0; i < num_processes; i++) {
        current_processes[i] = processes[i];
    }
    completed_processes = 0;
}

void create_process(int pid, int arrival_time, int burst_time, int priority) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Maximum number of processes reached\n");
        return;
    }

    Process *p = &processes[num_processes];
    if (pid == 0) {
        p->pid = ++num_processes;
    } else {
        p->pid = pid;
    }
    p->arrival_time = arrival_time;
    p->burst_time = burst_time;
    p->remaining_time = burst_time;
    p->priority = priority;
    p->waiting_time = 0;
    p->turnaround_time = 0;
    p->completion_time = 0;
    p->response_time = -1;
    p->state = READY;
    p->io_count = 0;
    //int request_times[2] = {2, 5};
    //int burst_times[2] = {1, 2};
    //create_io(p->io, p->io_count, request_times, burst_times);
    p->current_io = 0;
    p->cpu_time = 0;
}

void create_random_process(int pid) {
    int arrival_time = rand() % MAX_ARRIVAL_TIME;
    int burst_time = (rand() % (MAX_BURST_TIME - MIN_BURST_TIME)) + MIN_BURST_TIME;
    int priority = rand() % MAX_PRIORITY + 1;
    
    if (num_processes >= MAX_PROCESSES) {
        printf("Maximum number of processes reached\n");
        return;
    }

    Process *p = &processes[num_processes];
    if (pid == 0) {
        p->pid = ++num_processes;
    } else {
        p->pid = pid;
    }
    p->arrival_time = arrival_time;
    p->burst_time = burst_time;
    p->remaining_time = burst_time;
    p->priority = priority;
    p->waiting_time = 0;
    p->turnaround_time = 0;
    p->completion_time = 0;
    p->response_time = -1;
    p->state = READY;
    p->io_count = rand() % MAX_IO + 1;
    create_random_io(p->io, p->io_count, p->burst_time);
    p->current_io = 0;
    p->cpu_time = 0;
}

void create_processes(int random, int num) {
    if (random) {
        for (int i = 0; i < num; i++) {
            create_random_process(0);
        }
    } else {
        create_process(0, 0, 10, 2);
        create_process(0, 2, 5, 3);
        create_process(0, 4, 3, 1);
    }
}

void print_process(Process *p){
    printf("\n========================================\n");
    printf("Process %d\n", p->pid);
    printf("Arrival Time: %d\n", p->arrival_time);
    printf("Burst Time: %d\n", p->burst_time);
    printf("Priority: %d\n", p->priority);
    printf("IO Count: %d\n", p->io_count);
    for (int i = 0; i < p->io_count; i++){
        printf("IO %d Request Time: %d\n", i, p->io[i].request_time);
        printf("IO %d Burst Time: %d\n", i, p->io[i].burst_time);
    }
    printf("========================================\n");
}
