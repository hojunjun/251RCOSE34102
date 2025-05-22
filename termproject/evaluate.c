#include "evaluate.h"
#include "process.h"
#include "scheduler.h"
#include <stdio.h>

float get_average_waiting_time(){
    float total_waiting_time = 0;
    for (int i = 0; i< num_processes; i++){
        total_waiting_time += current_processes[i].waiting_time;
    }
    return total_waiting_time / num_processes;
}
float get_average_turnaround_time(){
    float total_turnaround_time = 0;
    for (int i = 0; i< num_processes; i++){
        total_turnaround_time += current_processes[i].turnaround_time;
    }
    return total_turnaround_time / num_processes;
}
float get_average_response_time(){
    float total_response_time = 0;
    for (int i = 0; i< num_processes; i++){
        total_response_time += current_processes[i].response_time;
    }
    return total_response_time / num_processes;
}
float get_average_completion_time(){
    float total_completion_time = 0;
    for (int i = 0; i< num_processes; i++){
        total_completion_time += current_processes[i].completion_time;
    }
    return total_completion_time / num_processes;
}

int get_max_waiting_time(){
    int max_waiting_time = 0;
    for (int i = 0; i< num_processes; i++){
        if (current_processes[i].waiting_time > max_waiting_time){
            max_waiting_time = current_processes[i].waiting_time;
        }
    }
    return max_waiting_time;
}
int get_max_turnaround_time(){
    int max_turnaround_time = 0;
    for (int i = 0; i< num_processes; i++){
        if (current_processes[i].turnaround_time > max_turnaround_time){
            max_turnaround_time = current_processes[i].turnaround_time;
        }
    }
    return max_turnaround_time;
}
int get_max_response_time(){
    int max_response_time = 0;
    for (int i = 0; i< num_processes; i++){
        if (current_processes[i].response_time > max_response_time){
            max_response_time = current_processes[i].response_time;
        }
    }
    return max_response_time;
}
int get_max_completion_time(){
    int max_completion_time = 0;
    for (int i = 0; i< num_processes; i++){
        if (current_processes[i].completion_time > max_completion_time){
            max_completion_time = current_processes[i].completion_time;
        }
    }
    return max_completion_time;
}

int get_min_waiting_time(){
    int min_waiting_time = MAX_TIME;
    for (int i = 0; i< num_processes; i++){
        if (current_processes[i].waiting_time < min_waiting_time){
            min_waiting_time = current_processes[i].waiting_time;
        }
    }
    return min_waiting_time;
}
int get_min_turnaround_time(){
    int min_turnaround_time = MAX_TIME;
    for (int i = 0; i< num_processes; i++){
        if (current_processes[i].turnaround_time < min_turnaround_time){
            min_turnaround_time = current_processes[i].turnaround_time;
        }
    }
    return min_turnaround_time;
}
int get_min_response_time(){
    int min_response_time = MAX_TIME;
    for (int i = 0; i< num_processes; i++){
        if (current_processes[i].response_time < min_response_time){
            min_response_time = current_processes[i].response_time;
        }
    }
    return min_response_time;
}
int get_min_completion_time(){
    int min_completion_time = MAX_TIME;
    for (int i = 0; i< num_processes; i++){
        if (current_processes[i].completion_time < min_completion_time){
            min_completion_time = current_processes[i].completion_time;
        }
    }
    return min_completion_time;
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

void print_process_table() {
    printf("\nProcess table\n");
    printf("========================================\n");
    printf("PID\tState\t\tArrival\tBurst\tPriority\tIO count\tCompletion\tTurnaround\tWaiting\t\tResponse\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < num_processes; i++) {
        Process *p = &current_processes[i];
        char* state;
        switch (p->state) {
            case READY:
                state = "READY";
                break;
            case RUNNING:
                state = "RUNNING";
                break;
            case WAITING:
                state = "WAITING";
                break;
            case TERMINATED:
                state = "TERMINATED";
                break;
        }
        if (p->state != TERMINATED){
            printf("%d\t%s\t\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p->pid, state, p->arrival_time, p->burst_time, p->priority, p->io_count, p->completion_time, p->turnaround_time, p->waiting_time, p->response_time);
        }
        else {
            printf("%d\t%s\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p->pid, state, p->arrival_time, p->burst_time, p->priority, p->io_count, p->completion_time, p->turnaround_time, p->waiting_time, p->response_time);
        }
    }
    
    printf("\n\n");
}

void evaluate(){
    print_gantt();
    print_process_table();
    printf("Average waiting time: %.2f\tMax: %2d, Min:%2d\n", get_average_waiting_time(), get_max_waiting_time(), get_min_waiting_time());
    printf("Average turnaround time: %.2f\tMax: %2d, Min:%2d\n", get_average_turnaround_time(), get_max_turnaround_time(), get_min_turnaround_time());
    printf("Average response time: %.2f\tMax: %2d, Min:%2d\n", get_average_response_time(), get_max_response_time(), get_min_response_time());
    printf("Average completion time: %.2f\tMax: %2d, Min:%2d\n", get_average_completion_time(), get_max_completion_time(), get_min_completion_time());
    printf("\n========================================\n\n");
}