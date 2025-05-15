#ifndef PROCESS_H
#define PROCESS_H

#include "types.h"

void create_process(int pid, int arrival_time, int burst_time, int priority);
void create_random_process();
void create_processes(int random);

void reset_processes();
void print_process();
void print_processes_table();

#endif