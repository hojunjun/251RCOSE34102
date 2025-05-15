#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "types.h"
#include "process.h"
#include "io.h"
#include "queue.h"
#include "scheduler.h"

Process processes[MAX_PROCESSES];
int num_processes = 0;
int completed_processes = 0;
Queue ready_queue;
Queue waiting_queue;
GanttItem gantt[MAX_TIME];
int num_gantt_items = 0;
int current_time = 0;

void init() {
    init_io();
    init_scheduler();
    init_queues();
}

int main() {
    srand(time(NULL));
    int choice;
    printf("CPU Scheduling Simulator\n");
    printf("========================================\n");
    printf("1. Random\n");
    printf("2. File\n");
    printf("========================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    init();

    if (choice == 2) {
        create_processes(0);
    } else {
        create_processes(1);
    }

    print_processes_table();

    printf("Running FCFS\n");
    reset_scheduler();
    run_fcfs();
    print_gantt();
    evaluate();

    printf("Running SJF\n");
    reset_scheduler();
    run_sjf();
    print_gantt();
    evaluate();

    printf("Running SJF Non-Preemptive\n");
    reset_scheduler();
    run_sjf_nonpreemptive();
    print_gantt();
    evaluate();

    printf("Running Priority\n");
    reset_scheduler();
    run_priority();
    print_gantt();
    evaluate();

    printf("Running Priority Non-Preemptive\n");
    reset_scheduler();
    run_priority_nonpreemptive();
    print_gantt();
    evaluate();
    
    printf("Running RR\n");
    reset_scheduler();
    run_rr();
    print_gantt();
    evaluate();
}