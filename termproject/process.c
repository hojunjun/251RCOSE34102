#include "process.h"
#include <stdio.h>
#include <stdlib.h>

void create_process(int pid, int arrival_time, int burst_time, int priority) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Maximum number of processes reached\n");
        return;
    }

    Process *p = &processes[num_processes];
    if (pid == 0) {
        p->pid = num_processes++;
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
    p->current_io = 0;
    p->cpu_time = 0;
}

void create_random_process(int pid) {
    int arrival_time = rand() % 20;
    int burst_time = (rand() % 20) + 1;
    int priority = rand() % 10;
    
    int io_count = rand() % 4;
    
    create_process(pid, arrival_time, burst_time, priority);
    
    Process *p = &processes[num_processes - 1];
    p->io_count = io_count;
    
    for (int i = 0; i < io_count; i++) {
        p->io[i].request_time = (rand() % (burst_time - 1)) + 1;
        p->io[i].burst_time = (rand() % 5) + 1;
        p->io[i].completed = 0;
    }
}

void create_processes(int random) {
    if (random) {
        for (int i = 0; i < MAX_PROCESSES; i++) {
            create_random_process(0);
        }
    } else {
        create_process(0, 0, 4, 2);
        create_process(0, 1, 3, 3);
        create_process(0, 2, 5, 1);
        create_process(0, 3, 2, 4);
        create_process(0, 4, 4, 2);
    }
}

void reset_processes() {
    for (int i = 0; i < num_processes; i++) {
        current_processes[i] = processes[i];
    }
    completed_processes = 0;
}

void print_process() {
    printf("\nCurrent Process Status\n");
    printf("PID\tArrival\tBurst\tPriority\tState\t\tRemaining\tIO Count\n");
    printf("----------------------------------------------------------------\n");
    for (int i = 0; i < num_processes; i++) {
        Process *p = &current_processes[i];
        printf("%d\t%d\t%d\t%d\t\t", 
               p->pid, p->arrival_time, p->burst_time, p->priority);
        
        switch (p->state) {
            case READY:
                printf("READY\t\t");
                break;
            case RUNNING:
                printf("RUNNING\t\t");
                break;
            case WAITING:
                printf("WAITING\t\t");
                break;
            case TERMINATED:
                printf("TERMINATED\t");
                break;
        }
        
        printf("%d\t\t%d\n", p->remaining_time, p->io_count);
    }
    printf("\n");
}

void print_process_table() {
    printf("\nProcess Execution Summary\n");
    printf("PID\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\tResponse\n");
    printf("--------------------------------------------------------------------------------\n");
    
    float avg_turnaround = 0, avg_waiting = 0, avg_response = 0;
    int completed_count = 0;
    
    for (int i = 0; i < num_processes; i++) {
        Process *p = &current_processes[i];
        if (p->state == TERMINATED) {
            printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t%d\n",
                   p->pid, p->arrival_time, p->burst_time, p->priority,
                   p->completion_time, p->turnaround_time, p->waiting_time, p->response_time);
            
            avg_turnaround += p->turnaround_time;
            avg_waiting += p->waiting_time;
            avg_response += p->response_time;
            completed_count++;
        }
    }
    
    if (completed_count > 0) {
        avg_turnaround /= completed_count;
        avg_waiting /= completed_count;
        avg_response /= completed_count;
        
        printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);
        printf("Average Waiting Time: %.2f\n", avg_waiting);
        printf("Average Response Time: %.2f\n", avg_response);
    }
    printf("\n");
}

