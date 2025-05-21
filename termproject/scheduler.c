#include "scheduler.h"
#include "process.h"
#include "queue.h"
#include <stdio.h>


void init_scheduler() {
    num_gantt_items = 0;
    completed_processes = 0;
    for (int i = 0; i < MAX_TIME; i++) {
        gantt[i].pid = -1;
        gantt[i].start_time = 0;
        gantt[i].end_time = 0;
    }
}

void run_fcfs(){
    Process* current = NULL;
    int current_time = 0;
    int current_start = 0;
    int current_pid = -1;

    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                for (int i = 0; i < current->io_count; i++){
                    if (current->io[i].request_time == current->cpu_time){
                        current->state = WAITING;
                        current->current_io = i;
                        current_pid = -1;
                        add_to_gantt(current->pid, current_start, current_time);
                        enqueue(&waiting_queue, current);
                        break;
                    }
                }
            }
            if (current->remaining_time==0){
                current->state = TERMINATED;
                current->completion_time = current_time;
                current->turnaround_time = current->completion_time - current->arrival_time;
                current_pid = -1;
                add_to_gantt(current->pid, current_start, current_time);
                completed_processes++;
            }
        }

        for (int i = 0; i < num_processes; i++) {
            if (current_time==current_processes[i].arrival_time){
                current_processes[i].state = READY;
                enqueue(&ready_queue, &current_processes[i]);
            }
        }

        int waiting_size = waiting_queue.size;
        int waiting_front = waiting_queue.front;
        for (int i = 0; i < waiting_size; i++) {
            Process* waiting = waiting_queue.processes[waiting_front+i];
            if (waiting->io[waiting->current_io].io_time == waiting->io[waiting->current_io].burst_time) {
                waiting->io[waiting->current_io].completed = 1;
                waiting->current_io = -1;
                waiting->state = READY;
                remove_process(&waiting_queue, waiting);
                enqueue(&ready_queue, waiting);
            }
        }

        if (ready_queue.size > 0 && current_pid == -1){
            current = dequeue(&ready_queue);
            current->state = RUNNING;
            if (current->response_time == -1){
                current->response_time = current_time - current->arrival_time;
            }
            current_pid = current->pid;
            current_start = current_time;
        }

        update_queues();
        current_time++;
    }
}

void run_sjf(){
    Process* current = NULL;
    int current_time = 0;
    int current_start = 0;
    int current_pid = -1;

    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                for (int i = 0; i < current->io_count; i++){
                    if (current->io[i].request_time == current->cpu_time){
                        current->state = WAITING;
                        current->current_io = i;
                        current_pid = -1;
                        add_to_gantt(current->pid, current_start, current_time);
                        enqueue(&waiting_queue, current);
                        break;
                    }
                }
            }
            if (current->remaining_time==0){
                current->state = TERMINATED;
                current->completion_time = current_time;
                current->turnaround_time = current->completion_time - current->arrival_time;
                current_pid = -1;
                add_to_gantt(current->pid, current_start, current_time);
                completed_processes++;
            }
        }

        for (int i = 0; i < num_processes; i++) {
            if (current_time==current_processes[i].arrival_time){
                current_processes[i].state = READY;
                enqueue(&ready_queue, &current_processes[i]);
                
                if (current_pid > -1 && current->remaining_time > current_processes[i].remaining_time){
                    current->state = READY;
                    current_pid = -1;
                    add_to_gantt(current->pid, current_start, current_time);
                    enqueue(&ready_queue, current);
                }
            }
        }

        int waiting_size = waiting_queue.size;
        int waiting_front = waiting_queue.front;
        for (int i = 0; i < waiting_size; i++) {
            Process* waiting = waiting_queue.processes[waiting_front+i];
            if (waiting->io[waiting->current_io].io_time == waiting->io[waiting->current_io].burst_time) {
                waiting->io[waiting->current_io].completed = 1;
                waiting->current_io = -1;
                waiting->state = READY;
                remove_process(&waiting_queue, waiting);
                enqueue(&ready_queue, waiting);

                if (current_pid > -1 && current->remaining_time > waiting->remaining_time){
                    current->state = READY;
                    current_pid = -1;
                    add_to_gantt(current->pid, current_start, current_time);
                    enqueue(&ready_queue, current);
                }
            }
        }

        if (ready_queue.size > 0 && current_pid == -1){
            current = get_shortest_job(&ready_queue);
            current->state = RUNNING;
            if (current->response_time == -1){
                current->response_time = current_time - current->arrival_time;
            }
            current_pid = current->pid;
            current_start = current_time;
        }

        update_queues();
        current_time++;
    }
}

void run_sjf_nonpreemptive(){
    Process* current = NULL;
    int current_time = 0;
    int current_start = 0;
    int current_pid = -1;
    
    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                for (int i = 0; i < current->io_count; i++){
                    if (current->io[i].request_time == current->cpu_time){
                        current->state = WAITING;
                        current->current_io = i;
                        current_pid = -1;
                        add_to_gantt(current->pid, current_start, current_time);
                        enqueue(&waiting_queue, current);
                        break;
                    }
                }
            }
            if (current->remaining_time==0){
                current->state = TERMINATED;
                current->completion_time = current_time;
                current->turnaround_time = current->completion_time - current->arrival_time;
                current_pid = -1;
                add_to_gantt(current->pid, current_start, current_time);
                completed_processes++;
            }
        }

        for (int i = 0; i < num_processes; i++) {
            if (current_time==current_processes[i].arrival_time){
                current_processes[i].state = READY;
                enqueue(&ready_queue, &current_processes[i]);
            }
        }

        int waiting_size = waiting_queue.size;
        int waiting_front = waiting_queue.front;
        for (int i = 0; i < waiting_size; i++) {
            Process* waiting = waiting_queue.processes[waiting_front+i];
            if (waiting->io[waiting->current_io].io_time == waiting->io[waiting->current_io].burst_time) {
                waiting->io[waiting->current_io].completed = 1;
                waiting->current_io = -1;
                waiting->state = READY;
                remove_process(&waiting_queue, waiting);
                enqueue(&ready_queue, waiting);
            }
        }

        if (ready_queue.size > 0 && current_pid == -1){
            current = get_shortest_job(&ready_queue);
            current->state = RUNNING;
            if (current->response_time == -1){
                current->response_time = current_time - current->arrival_time;
            }
            current_pid = current->pid;
            current_start = current_time;
        }

        update_queues();
        current_time++;
    }
}

void add_to_gantt(int pid, int start_time, int end_time){
    gantt[num_gantt_items].pid = pid;
    gantt[num_gantt_items].start_time = start_time;
    gantt[num_gantt_items].end_time = end_time;
    num_gantt_items++;
}

void print_gantt(){
    printf("\nGantt chart\n");
    printf("========================================\n\n");
    if (gantt[0].start_time != 0){
        printf("|  idle  |");
    } else {
        printf("|");
    }
    for (int i = 0; i < num_gantt_items ; i++){
        printf("   P%-3d |", gantt[i].pid);
        if(gantt[i].end_time != gantt[i+1].start_time){
            printf("  idle  |");
        }
    }
    if (gantt[0].start_time != 0){
        printf("\n0\t ");
    } else {
        printf("\n");
    }
    for (int i = 0; i < num_gantt_items ; i++){
        if(gantt[i].end_time != gantt[i+1].start_time){
            printf("%-5d%5d", gantt[i].start_time, gantt[i].end_time);
            printf("        ");
        }
        else {
            printf("%-9d", gantt[i].start_time);
        }
    }
    printf("fin\n\n");
}