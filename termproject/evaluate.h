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

void print_gantt();
void print_process_table();
void evaluate();

#endif