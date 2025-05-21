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

void evaluate(){
    print_gantt();
    print_process_table();
    printf("Average waiting time: %.2f\tMax: %2d, Min:%2d\n", get_average_waiting_time(), get_max_waiting_time(), get_min_waiting_time());
    printf("Average turnaround time: %.2f\tMax: %2d, Min:%2d\n", get_average_turnaround_time(), get_max_turnaround_time(), get_min_turnaround_time());
    printf("Average response time: %.2f\tMax: %2d, Min:%2d\n", get_average_response_time(), get_max_response_time(), get_min_response_time());
    printf("Average completion time: %.2f\tMax: %2d, Min:%2d\n", get_average_completion_time(), get_max_completion_time(), get_min_completion_time());
}