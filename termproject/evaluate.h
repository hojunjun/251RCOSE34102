#ifndef EVALUATE_H
#define EVALUATE_H

#include "types.h"

float get_average_waiting_time();
float get_average_turnaround_time();
float get_average_response_time();
float get_average_completion_time();
int get_max_waiting_time();
int get_max_turnaround_time();
int get_max_response_time();
int get_max_completion_time();
int get_min_waiting_time();
int get_min_turnaround_time();
int get_min_response_time();
int get_min_completion_time();
float get_variance_waiting_time();
float get_variance_turnaround_time();
float get_variance_response_time();
float get_variance_completion_time();
int get_first_arrival_time();
int get_sum_burst_time();
float get_cpu_utilization();
float get_throughput();
int get_idle_time();
int get_sum_io_time();
int get_context_switch();

void print_gantt();
void print_process_table();
void evaluate(char* algorithm);
void compare();

#endif