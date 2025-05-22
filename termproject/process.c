#include "process.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>

void init_processes(){
    for (int i = 0; i < num_processes; i++){
        current_processes[i] = processes[i];
    }
    completed_processes = 0;
}

void create_process(int pid, int arrival_time, int burst_time, int priority, int io_count, int* request_times, int* burst_times){
    if (num_processes >= MAX_PROCESSES){
        printf("Maximum number of processes reached\n");
        return;
    }

    Process *p = &processes[num_processes];
    if (pid == 0){
        p->pid = ++num_processes;
    } else{
        p->pid = pid;
        num_processes++;
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
    p->io_count = io_count;
    if (io_count > 0 && io_count < MAX_IO){
        create_io(p->io, p->io_count, request_times, burst_times);
    }
    p->current_io = 0;
    p->cpu_time = 0;
}

void create_random_process(int pid){
    int arrival_time = rand() % MAX_ARRIVAL_TIME;
    int burst_time = (rand() % (MAX_BURST_TIME - MIN_BURST_TIME)) + MIN_BURST_TIME;
    int priority = rand() % MAX_PRIORITY + 1;
    
    if (num_processes >= MAX_PROCESSES){
        printf("Maximum number of processes reached\n");
        return;
    }

    Process *p = &processes[num_processes];
    if (pid == 0){
        p->pid = ++num_processes;
    } else{
        p->pid = pid;
        num_processes++;
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

void create_processes(int choice){
    int num = 0;
    if (choice != 1){
        printf("Enter number of processes: ");
        scanf("%d", &num);
    }
    if (choice == 1){
        create_process(0, 0, 10, 2, 0, NULL, NULL);
        create_process(0, 2, 5, 3, 0, NULL, NULL);
        create_process(0, 4, 3, 1, 0, NULL, NULL);
    } else if (choice == 2){
        for (int i = 0; i < num; i++){
            create_random_process(0);
        }
    } else if (choice == 3){
        for (int i = 0; i < num; i++){
            create_random_process(0);
        }
    } else {
        int pid = 0;
        int arrival = 0;
        int burst = 0;
        int priority = 0;
        int io_count = 0;
        int* io_request = NULL;
        int* io_burst = NULL;
        for (int i = 0; i < num; i++){
            printf("\n========================================\n");
            printf("Process ");
            scanf("%d", &pid);
            printf("Arrival Time: ");
            scanf("%d", &arrival);
            printf("Burst Time: ");
            scanf("%d", &burst);
            printf("Priority: ");
            scanf("%d", &priority);
            printf("IO Count: ");
            scanf("%d", &io_count);
            if (io_count > 0){
                io_request = (int*)malloc(sizeof(int) * io_count);
                io_burst = (int*)malloc(sizeof(int) * io_count);
                for (int j = 0; j < io_count; j++){
                    printf("IO %d Request Time: ", j);
                    scanf("%d", &io_request[j]);
                    printf("IO %d Burst Time: ", j);
                    scanf("%d", &io_burst[j]);
                }
            }
            create_process(pid, arrival, burst, priority, io_count, io_request, io_burst);
            if (io_count > 0){
                free(io_request);
                free(io_burst);
                io_request = NULL;
                io_burst = NULL;
            }
            printf("========================================\n");
        }
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
