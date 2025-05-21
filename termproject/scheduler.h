#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "types.h"

void init_scheduler();

void run_fcfs();
void run_sjf();
void run_sjf_nonpreemptive();
void run_priority();
void run_priority_nonpreemptive();
void run_rr();

void add_to_gantt(int pid, int start_time, int end_time);
void print_gantt();

int get_average_waiting_time();
int get_average_turnaround_time();
int get_average_response_time();
int get_average_completion_time();
int get_max_waiting_time();
int get_max_turnaround_time();
int get_max_response_time();
int get_max_completion_time();
int get_min_waiting_time();
int get_min_turnaround_time();
int get_min_response_time();
int get_min_completion_time();

void evaluate();

#endif