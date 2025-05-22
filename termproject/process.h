#ifndef PROCESS_H
#define PROCESS_H

#include "types.h"

void init_processes();

void create_process(int pid, int arrival_time, int burst_time, int priority, int io_count, int* request_times, int* burst_times);
void create_random_process(int pid);
void create_processes(int random);

void print_process(Process *p);

#endif