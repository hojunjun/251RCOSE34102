#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "types.h"
#include "process.h"
#include "io.h"
#include "queue.h"
#include "scheduler.h"
#include "evaluate.h"

Process processes[MAX_PROCESSES];
Process current_processes[MAX_PROCESSES];
int num_processes = 0;
int completed_processes = 0;
Queue ready_queue;
Queue waiting_queue;
GanttItem gantt[MAX_TIME];
int num_gantt_items = 0;
EvalItem evaluation[NUM_ALGORITHMS];
int num_simulation = 0;

int main(){
    srand(time(NULL));
    int choice, number;
    printf("CPU Scheduling Simulator\n");
    printf("========================================\n");
    printf("1. Sample\n");
    printf("2. Random\n");
    printf("3. From file\n");
    printf("4. Manual input\n");
    printf("========================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    create_processes(choice);

    init_processes();
    
    if (choice != 4){
        for (int i = 0; i < num_processes; i++){
            print_process(&current_processes[i]);
        }
    }
    printf("\n\n");
    
    printf("\nRunning FCFS\n");
    run_fcfs();
    evaluate("FCFS");

    printf("\nRunning SJF\n");
    run_sjf();
    evaluate("Preemptive SJF");

    printf("\nRunning SJF Non-Preemptive\n");
    run_sjf_nonpreemptive();
    evaluate("Nonpreemptive SJF");

    printf("\nRunning Priority\n");
    run_priority();
    evaluate("Preemptive Priority");

    printf("\nRunning Priority Non-Preemptive\n");
    run_priority_nonpreemptive();
    evaluate("Nonpreemptive Priority");
    
    printf("\nRunning RR\n");
    run_rr();
    evaluate("RR");

    printf("\nRunning Aging Priority\n");
    run_aging_priority();
    evaluate("Aging Preemptive Priority");

    printf("\nRunning Aging Priority Non-Preemptive\n");
    run_aging_priority_nonpreemptive();
    evaluate("Aging Nonpreemptive Priority");

    printf("\nRunning HRRN\n");
    run_hrrn();
    evaluate("Preemptive HRRN");

    printf("\nRunning HRRN Non-Preemptive\n");
    run_hrrn_nonpreemptive();
    evaluate("Nonpreemptive HRRN");

    compare();
    return 0;
}
