#include "scheduler.h"
#include "process.h"
#include "queue.h"
#include <stdio.h>
#include <assert.h>

Process* current;
int current_time;
int current_start;
int current_pid;


void init_scheduler(){
    init_processes();
    init_queues();

    num_gantt_items = 0;
    completed_processes = 0;
    for (int i = 0; i < MAX_TIME; i++){
        gantt[i].pid = -1;
        gantt[i].start_time = 0;
        gantt[i].end_time = 0;
    }

    current = NULL;
    current_time = 0;
    current_start = 0;
    current_pid = -1;
}

void check_io_request(){
    for (int i = 0; i < current->io_count; i++){
        if (current->io[i].request_time == current->cpu_time){
            current->state = WAITING;
            current->current_io = i;
            current_pid = -1;
            add_to_gantt(current->pid, current_start, current_time);
            enqueue(&waiting_queue, current);
            break;
        }
    }
}

void check_io_complete(){
    int waiting_size = waiting_queue.size;
    int waiting_front = waiting_queue.front;
    for (int i = 0; i < waiting_size; i++){
        Process* waiting = waiting_queue.processes[waiting_front+i];
        if (waiting->io[waiting->current_io].io_time == waiting->io[waiting->current_io].burst_time){
            waiting->io[waiting->current_io].completed = 1;
            waiting->current_io = -1;
            waiting->state = READY;
            remove_process(&waiting_queue, waiting);
            waiting_front--;
            enqueue(&ready_queue, waiting);
        }
    }
}

void arrive_process(int i){
    current_processes[i].state = READY;
    enqueue(&ready_queue, &current_processes[i]);
}

void run_process(){
    current->state = RUNNING;
    if (current->response_time == -1){
        current->response_time = current_time - current->arrival_time;
    }
    current_pid = current->pid;
    current_start = current_time;
}

void terminate_process(){
    current->state = TERMINATED;
    current->completion_time = current_time;
    current->turnaround_time = current->completion_time - current->arrival_time;
    current_pid = -1;
    add_to_gantt(current->pid, current_start, current_time);
    completed_processes++;
}

void preempt_process(){
    current->state = READY;
    current_pid = -1;
    add_to_gantt(current->pid, current_start, current_time);
    enqueue(&ready_queue, current);
}

void add_to_gantt(int pid, int start_time, int end_time){
    gantt[num_gantt_items].pid = pid;
    gantt[num_gantt_items].start_time = start_time;
    gantt[num_gantt_items].end_time = end_time;
    num_gantt_items++;
}

void update_queues(){
    for (int i = 0; i < ready_queue.size; i++){
        int index = (ready_queue.front + i) % MAX_QUEUE_SIZE;
        ready_queue.processes[index]->waiting_time++;
    }
    for (int i = 0; i < waiting_queue.size; i++){
        int index = (waiting_queue.front + i) % MAX_QUEUE_SIZE;
        waiting_queue.processes[index]->io[waiting_queue.processes[index]->current_io].io_time++;
    }
} 


void run_fcfs(){

    init_scheduler();

    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                check_io_request();
            }
            if (current->remaining_time==0){
                terminate_process();
            }
        }

        for (int i = 0; i < num_processes; i++){
            if (current_time==current_processes[i].arrival_time){
                arrive_process(i);
            }
        }

        check_io_complete();

        if (ready_queue.size > 0 && current_pid == -1){
            current = dequeue(&ready_queue);
            run_process();
        }

        update_queues();
        current_time++;
    }

    assert(completed_processes == num_processes);
    num_simulation++;
}

void run_sjf(){

    init_scheduler();

    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                check_io_request();
            }
            if (current->remaining_time==0){
                terminate_process();
            }
        }

        for (int i = 0; i < num_processes; i++){
            if (current_time==current_processes[i].arrival_time){
                arrive_process(i);
                
                if (current_pid > -1 && current->remaining_time > current_processes[i].remaining_time){
                    preempt_process();
                }
            }
        }

        check_io_complete();

        if (ready_queue.size > 0 && current_pid == -1){
            current = get_shortest_job(&ready_queue);
            run_process();
        }

        update_queues();
        current_time++;
    }

    assert(completed_processes == num_processes);
    num_simulation++;
}

void run_sjf_nonpreemptive(){

    init_scheduler();
    
    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                check_io_request();
            }
            if (current->remaining_time==0){
                terminate_process();
            }
        }

        for (int i = 0; i < num_processes; i++){
            if (current_time==current_processes[i].arrival_time){
                arrive_process(i);
            }
        }

        check_io_complete();

        if (ready_queue.size > 0 && current_pid == -1){
            current = get_shortest_job(&ready_queue);
            run_process();
        }

        update_queues();
        current_time++;
    }

    assert(completed_processes == num_processes);
    num_simulation++;
}

void run_priority(){

    init_scheduler();

    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                check_io_request();
            }
            if (current->remaining_time==0){
                terminate_process();
            }
        }

        for (int i = 0; i < num_processes; i++){
            if (current_time==current_processes[i].arrival_time){
                arrive_process(i);
                
                if (current_pid > -1 && current->priority > current_processes[i].priority){
                    preempt_process();
                }
            }
        }

        check_io_complete();

        if (ready_queue.size > 0 && current_pid == -1){
            current = get_highest_priority(&ready_queue);
            run_process();
        }

        update_queues();
        current_time++;
    }

    assert(completed_processes == num_processes);
    num_simulation++;
}

void run_priority_nonpreemptive(){
    init_scheduler();
    
    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                check_io_request();
            }
            if (current->remaining_time==0){
                terminate_process();
            }
        }

        for (int i = 0; i < num_processes; i++){
            if (current_time==current_processes[i].arrival_time){
                arrive_process(i);
            }
        }

        check_io_complete();

        if (ready_queue.size > 0 && current_pid == -1){
            current = get_highest_priority(&ready_queue);
            run_process();
        }

        update_queues();
        current_time++;
    }

    assert(completed_processes == num_processes);
    num_simulation++;
}

void run_rr(){
    init_scheduler();

    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                check_io_request();
            }
            if (current->remaining_time==0){
                terminate_process();
            }
            if (current_pid > -1 && (current_time - current_start) == RR_TIME_QUANTUM){
                preempt_process();
            }
        }

        for (int i = 0; i < num_processes; i++){
            if (current_time==current_processes[i].arrival_time){
                arrive_process(i);
            }
        }

        check_io_complete();

        if (ready_queue.size > 0 && current_pid == -1){
            current = dequeue(&ready_queue);
            run_process();
        }

        update_queues();
        current_time++;
    }

    assert(completed_processes == num_processes);
    num_simulation++;
}


void run_aging_priority(){

    init_scheduler();

    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                check_io_request();
            }
            if (current->remaining_time==0){
                terminate_process();
            }
            for (int i = 0; i < ready_queue.size; i++){
                int index = (ready_queue.front + i) % MAX_QUEUE_SIZE;
                if (current_pid > -1 && current->priority > ready_queue.processes[index]->priority){
                    preempt_process();
                }
            }
        }

        for (int i = 0; i < num_processes; i++){
            if (current_time==current_processes[i].arrival_time){
                arrive_process(i);
                
                if (current_pid > -1 && current->priority > current_processes[i].priority){
                    preempt_process();
                }
            }
        }

        check_io_complete();

        if (ready_queue.size > 0 && current_pid == -1){
            current = get_highest_priority(&ready_queue);
            run_process();
        }

        update_queues();
        for (int i = 0; i < ready_queue.size; i++){
            int index = (ready_queue.front + i) % MAX_QUEUE_SIZE;
            if (ready_queue.processes[index]->priority > 0 && ready_queue.processes[index]->waiting_time % AGING_TIME_QUANTUM == 0){
                ready_queue.processes[index]->priority--;
            }
        }    
        current_time++;
    }

    assert(completed_processes == num_processes);
    num_simulation++;
}

void run_aging_priority_nonpreemptive(){
    init_scheduler();
    
    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                check_io_request();
            }
            if (current->remaining_time==0){
                terminate_process();
            }
        }

        for (int i = 0; i < num_processes; i++){
            if (current_time==current_processes[i].arrival_time){
                arrive_process(i);
            }
        }

        check_io_complete();

        if (ready_queue.size > 0 && current_pid == -1){
            current = get_highest_priority(&ready_queue);
            run_process();
        }

        update_queues();
        for (int i = 0; i < ready_queue.size; i++){
            int index = (ready_queue.front + i) % MAX_QUEUE_SIZE;
            if (ready_queue.processes[index]->priority > 0 && ready_queue.processes[index]->waiting_time % AGING_TIME_QUANTUM == 0){
                ready_queue.processes[index]->priority--;
            }
        }    
        current_time++;
    }

    assert(completed_processes == num_processes);
    num_simulation++;
}

void run_hrrn(){

    init_scheduler();
    
    for (int i = 0; i < num_processes; i++){
        current_processes[i].priority = 0;
    }

    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                check_io_request();
            }
            if (current->remaining_time==0){
                terminate_process();
            }
            for (int i = 0; i < ready_queue.size; i++){
                int index = (ready_queue.front + i) % MAX_QUEUE_SIZE;
                if (current_pid > -1 && current->priority > ready_queue.processes[index]->priority){
                    preempt_process();
                }
            }
        }

        for (int i = 0; i < num_processes; i++){
            if (current_time==current_processes[i].arrival_time){
                arrive_process(i);
                
                if (current_pid > -1 && current->priority > current_processes[i].priority){
                    preempt_process();
                }
            }
        }

        check_io_complete();

        if (ready_queue.size > 0 && current_pid == -1){
            current = get_highest_priority(&ready_queue);
            run_process();
        }

        update_queues();
        for (int i = 0; i < ready_queue.size; i++){
            int index = (ready_queue.front + i) % MAX_QUEUE_SIZE;
            int response_ratio = (ready_queue.processes[index]->waiting_time + ready_queue.processes[index]->burst_time) * 1000 / ready_queue.processes[index]->burst_time;
            ready_queue.processes[index]->priority = -response_ratio;
        }    
        current_time++;
    }

    assert(completed_processes == num_processes);
    num_simulation++;
}

void run_hrrn_nonpreemptive(){
    init_scheduler();
    
    for (int i = 0; i < num_processes; i++){
        current_processes[i].priority = 0;
    }

    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                check_io_request();
            }
            if (current->remaining_time==0){
                terminate_process();
            }
        }

        for (int i = 0; i < num_processes; i++){
            if (current_time==current_processes[i].arrival_time){
                arrive_process(i);
            }
        }

        check_io_complete();

        if (ready_queue.size > 0 && current_pid == -1){
            current = get_highest_priority(&ready_queue);
            run_process();
        }

        update_queues();
        for (int i = 0; i < ready_queue.size; i++){
            int index = (ready_queue.front + i) % MAX_QUEUE_SIZE;
            int response_ratio = (ready_queue.processes[index]->waiting_time + ready_queue.processes[index]->burst_time) * 1000 / ready_queue.processes[index]->burst_time;
            ready_queue.processes[index]->priority = -response_ratio;
        }    
        current_time++;
    }

    assert(completed_processes == num_processes);
    num_simulation++;
}

void run_cfs(){
    int weight[num_processes];

    init_scheduler();

    for (int i = 0; i < num_processes; i++){
        weight[i] = (current_processes[i].priority < CFS_WEIGHT_THRESHOLD) ? 1 : 2;
        current_processes[i].priority = 0;
    }

    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                for (int i = 0; i < num_processes; i++){
                    if (current_pid == current_processes[i].pid){
                        current_processes[i].priority += weight[i];
                        break;
                    }
                }
                check_io_request();
            }
            if (current->remaining_time==0){
                terminate_process();
            }
            for (int i = 0; i < ready_queue.size; i++){
                int index = (ready_queue.front + i) % MAX_QUEUE_SIZE;
                if (current_pid > -1 && current->priority > ready_queue.processes[index]->priority){
                    preempt_process();
                }
            }
        }

        for (int i = 0; i < num_processes; i++){
            if (current_time==current_processes[i].arrival_time){
                arrive_process(i);
            }
        }

        check_io_complete();

        if (ready_queue.size > 0 && current_pid == -1){
            current = get_highest_priority(&ready_queue);
            run_process();
        }

        update_queues();
        current_time++;
    }

    assert(completed_processes == num_processes);
    num_simulation++;
}

void run_cfs_nonpreemptive(){
    int weight[num_processes];

    init_scheduler();

    for (int i = 0; i < num_processes; i++){
        weight[i] = (current_processes[i].priority < CFS_WEIGHT_THRESHOLD) ? 1 : 2;
        current_processes[i].priority = 0;
    }
    
    while(current_time < MAX_TIME && completed_processes != num_processes){
        if (current_pid > -1){
            if (current->remaining_time > 0){
                current->cpu_time++;
                current->remaining_time--;
                for (int i = 0; i < num_processes; i++){
                    if (current_pid == current_processes[i].pid){
                        current_processes[i].priority += weight[i];
                        break;
                    }
                }
                check_io_request();
            }
            if (current->remaining_time==0){
                terminate_process();
            }
        }

        for (int i = 0; i < num_processes; i++){
            if (current_time==current_processes[i].arrival_time){
                arrive_process(i);
            }
        }

        check_io_complete();

        if (ready_queue.size > 0 && current_pid == -1){
            current = get_highest_priority(&ready_queue);
            run_process();
        }

        update_queues();
        current_time++;
    }

    assert(completed_processes == num_processes);
    num_simulation++;
}