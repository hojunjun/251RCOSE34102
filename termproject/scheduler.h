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

#endif