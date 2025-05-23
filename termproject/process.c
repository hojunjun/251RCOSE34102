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
    if (io_count > 0 && io_count < MAX_IO + 1){
        create_io(p->io, p->io_count, request_times, burst_times);
    }
    p->current_io = 0;
    p->cpu_time = 0;
}

void create_random_process(int pid){
    int arrival_time = rand() % MAX_ARRIVAL_TIME;
    int burst_time = (rand() % (MAX_BURST_TIME - MIN_BURST_TIME)) + MIN_BURST_TIME;
    int priority = rand() % MAX_PRIORITY + 1;

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
    if (num < 0 || num > MAX_PROCESSES){
        printf("number of process should be between 0 and %d\n", MAX_PROCESSES);
        exit(0);
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
            char path[32];
            sprintf(path, "processes/process%d.txt", i+1);
            FILE *fp = fopen(path, "r");
            if (fp == NULL){
                printf("cannot open %s\n", path);
                printf("Usage:\n<pid>\n<arrival>\n<burst>\n<priority>\n<io count>\n<io request time> <io burst time>\n");
                exit(0);
            }
            int pid = 0;
            int arrival = 0;
            int burst = 0;
            int priority = 0;
            int io_count = 0;
            int* io_request = NULL;
            int* io_burst = NULL;
            if (fscanf(fp, "%d", &pid) != 1 || fscanf(fp, "%d", &arrival) != 1 || fscanf(fp, "%d", &burst) != 1 || fscanf(fp, "%d", &priority) != 1 || fscanf(fp, "%d", &io_count) != 1){
                printf("Usage:\n<pid>\n<arrival>\n<burst>\n<priority>\n<io count>\n<io request time> <io burst time>\n");
                fclose(fp);
                exit(0);
            }
            if (arrival < 0 || arrival > MAX_ARRIVAL_TIME){
                printf("arrival time should be between 0 and %d\n", MAX_ARRIVAL_TIME);
                fclose(fp);
                exit(0);
            }
            if (burst < MIN_BURST_TIME || burst > MAX_BURST_TIME){
                printf("burst time should be between %d and %d\n", MIN_BURST_TIME, MAX_BURST_TIME);
                fclose(fp);
                exit(0);
            }
            if (io_count < 0 || io_count > MAX_IO){
                printf("io count should be between 0 and %d\n", MAX_IO);
                fclose(fp);
                exit(0);
            }
            if (io_count > 0){
                io_request = (int*)malloc(sizeof(int) * io_count);
                io_burst = (int*)malloc(sizeof(int) * io_count);
                for (int j = 0; j < io_count; j++){
                    if (fscanf(fp, "%d %d", &io_request[j], &io_burst[j]) != 2){
                        printf("Usage:\n<pid>\n<arrival>\n<burst>\n<priority>\n<io count>\n<io request time> <io burst time>\n");
                        fclose(fp);
                        exit(0);
                    }
                    if (io_request[j] < 0 || io_request[j] > burst){
                        printf("io request time should be between 0 and %d\n", burst);
                        fclose(fp);
                        exit(0);
                    }
                    if (io_burst[j] < 0 || io_burst[j] > MAX_IO_BURST_TIME){
                        printf("io burst time should be between 0 and %d\n", MAX_IO_BURST_TIME);
                        fclose(fp);
                        exit(0);
                    }
                }
                fclose(fp);
                create_process(pid, arrival, burst, priority, io_count, io_request, io_burst);
                if (io_count > 0){
                    free(io_request);
                    free(io_burst);
                    io_request = NULL;
                    io_burst = NULL;
                }

            }
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
            if (arrival < 0 || arrival > MAX_ARRIVAL_TIME){
                printf("arrival time should be between 0 and %d\n", MAX_ARRIVAL_TIME);
                exit(0);
            }
            printf("Burst Time: ");
            scanf("%d", &burst);
            if (burst < MIN_BURST_TIME || burst > MAX_BURST_TIME){
                printf("burst time should be between %d and %d\n", MIN_BURST_TIME, MAX_BURST_TIME);
                exit(0);
            }
            printf("Priority: ");
            scanf("%d", &priority);
            printf("IO Count: ");
            scanf("%d", &io_count);
            if (io_count < 0 || io_count > MAX_IO){
                printf("io count should be between 0 and %d\n", MAX_IO);
                exit(0);
            }
            if (io_count > 0){
                io_request = (int*)malloc(sizeof(int) * io_count);
                io_burst = (int*)malloc(sizeof(int) * io_count);
                for (int j = 0; j < io_count; j++){
                    printf("IO %d Request Time: ", j);
                    scanf("%d", &io_request[j]);
                    if (io_request[j] < 0 || io_request[j] > burst){
                        printf("io request time should be between 0 and %d\n", burst);
                        exit(0);
                    }
                    printf("IO %d Burst Time: ", j);
                    scanf("%d", &io_burst[j]);
                    if (io_burst[j] < 0 || io_burst[j] > MAX_IO_BURST_TIME){
                        printf("io burst time should be between 0 and %d\n", MAX_IO_BURST_TIME);
                        exit(0);
                    }
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
