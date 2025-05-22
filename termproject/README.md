# 2025-1 COSE341 Operating Systems Term Project - CPU Scheduling Simulator

## Usage

```
$ gcc main.c process.c queue.c scheduler.c io.c evaluate.c -o main
$ ./main
```

## Implemented
- process
    - create hard coded processes
    - create random processes
- queue
    - basic queue implementation
    - get shortest job
    - get highest priority job
- io
    - create hard coded io
    - create random io
- scheduler
    - fcfs
    - preemptive sjf
    - nonpreemptive sjf
- evaluation
    - average/max/min waiting time
    - average/max/min turnaround time
    - average/max/min response time
    - average/max/min completion time
    - print gantt chart
    - print process table

## Todo
- process
    - create process from files
    - create process from input
- io
    - create io from files
    - create io from input
- scheduler
    - preemptive priority
    - nonpreemptive priority
    - rr
- evaluation
    - compare
    - analyze

## Example
```
CPU Scheduling Simulator
========================================
1. Random
2. File
========================================
Enter your choice: 1
Enter number of processes: 4

========================================
Process 1
Arrival Time: 49
Burst Time: 17
Priority: 4
IO Count: 1
IO 0 Request Time: 10
IO 0 Burst Time: 5
========================================

========================================
Process 2
Arrival Time: 8
Burst Time: 7
Priority: 10
IO Count: 1
IO 0 Request Time: 6
IO 0 Burst Time: 2
========================================

========================================
Process 3
Arrival Time: 30
Burst Time: 6
Priority: 5
IO Count: 2
IO 0 Request Time: 2
IO 0 Burst Time: 5
IO 1 Request Time: 3
IO 1 Burst Time: 3
========================================

========================================
Process 4
Arrival Time: 16
Burst Time: 15
Priority: 6
IO Count: 1
IO 0 Request Time: 13
IO 0 Burst Time: 1
========================================
Running FCFS

Gantt chart
========================================

|  idle  |   P2   |  idle  |   P4   |   P2   |   P3   |   P4   |  idle  |   P3   |  idle  |   P3   |  idle  |   P1   |  idle  |   P1   |  idle  |
0        8       14        16       29       30       32      34        37      38        41      44        49      59        64      71        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      49      17      4               1               71              22              0               0
2       TERMINATED      8       7       10              1               30              22              13              0
3       TERMINATED      30      6       5               2               44              14              0               0
4       TERMINATED      16      15      6               1               34              18              2               0


Average waiting time: 3.75      Max: 13, Min: 0
Average turnaround time: 19.00  Max: 22, Min:14
Average response time: 0.00     Max:  0, Min: 0
Average completion time: 44.75  Max: 71, Min:30

========================================

Running SJF

Gantt chart
========================================

|  idle  |   P2   |  idle  |   P2   |   P4   |   P3   |   P4   |   P3   |  idle  |   P3   |  idle  |   P3   |  idle  |   P1   |  idle  |   P1   |  idle  |
0        8       14        16       17       30       31       33      34        39      40        43      46        49      59        64      71        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      49      17      4               1               71              22              0               0
2       TERMINATED      8       7       10              1               17              9               0               0
3       TERMINATED      30      6       5               2               46              16              2               0
4       TERMINATED      16      15      6               1               33              17              1               1


Average waiting time: 0.75      Max:  2, Min: 0
Average turnaround time: 16.00  Max: 22, Min: 9
Average response time: 0.25     Max:  1, Min: 0
Average completion time: 41.75  Max: 71, Min:17

========================================

Running SJF Non-Preemptive

Gantt chart
========================================

|  idle  |   P2   |  idle  |   P2   |   P4   |   P3   |   P4   |  idle  |   P3   |  idle  |   P3   |  idle  |   P1   |  idle  |   P1   |  idle  |
0        8       14        16       17       30       32      34        37      38        41      44        49      59        64      71        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      49      17      4               1               71              22              0               0
2       TERMINATED      8       7       10              1               17              9               0               0
3       TERMINATED      30      6       5               2               44              14              0               0
4       TERMINATED      16      15      6               1               34              18              2               1


Average waiting time: 0.50      Max:  2, Min: 0
Average turnaround time: 15.75  Max: 22, Min: 9
Average response time: 0.25     Max:  1, Min: 0
Average completion time: 41.50  Max: 71, Min:17

========================================
```

```
CPU Scheduling Simulator
========================================
1. Random
2. File
========================================
Enter your choice: 1
Enter number of processes: 4

========================================
Process 1
Arrival Time: 48
Burst Time: 17
Priority: 7
IO Count: 3
IO 0 Request Time: 3
IO 0 Burst Time: 5
IO 1 Request Time: 5
IO 1 Burst Time: 2
IO 2 Request Time: 14
IO 2 Burst Time: 4
========================================

========================================
Process 2
Arrival Time: 10
Burst Time: 16
Priority: 2
IO Count: 1
IO 0 Request Time: 5
IO 0 Burst Time: 4
========================================

========================================
Process 3
Arrival Time: 40
Burst Time: 16
Priority: 4
IO Count: 1
IO 0 Request Time: 1
IO 0 Burst Time: 2
========================================

========================================
Process 4
Arrival Time: 15
Burst Time: 18
Priority: 10
IO Count: 1
IO 0 Request Time: 8
IO 0 Burst Time: 3
========================================
Running FCFS

Gantt chart
========================================

|  idle  |   P2   |   P4   |   P2   |   P4   |   P3   |  idle  |   P3   |   P1   |  idle  |   P1   |  idle  |   P1   |  idle  |   P1   |  idle  |
0        10       15       23       34       44      45        47       62      65        70      72        74      83        87      90        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      48      17      7               3               90              42              14              14
2       TERMINATED      10      16      2               1               34              24              4               0
3       TERMINATED      40      16      4               1               62              22              4               4
4       TERMINATED      15      18      10              1               44              29              8               0


Average waiting time: 7.50      Max: 14, Min: 4
Average turnaround time: 29.25  Max: 42, Min:22
Average response time: 4.50     Max: 14, Min: 0
Average completion time: 57.50  Max: 90, Min:34

========================================

Running SJF

Gantt chart
========================================

|  idle  |   P2   |   P4   |   P2   |   P4   |  idle  |   P4   |   P3   |   P1   |   P3   |   P1   |  idle  |   P1   |  idle  |   P1   |  idle  |
0        10       15       19       30      34        37       47       48       51       66      68        70      79        83      86        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      48      17      7               3               86              38              10              0
2       TERMINATED      10      16      2               1               30              20              0               0
3       TERMINATED      40      16      4               1               66              26              8               7
4       TERMINATED      15      18      10              1               47              32              11              0


Average waiting time: 7.25      Max: 11, Min: 0
Average turnaround time: 29.00  Max: 38, Min:20
Average response time: 1.75     Max:  7, Min: 0
Average completion time: 57.25  Max: 86, Min:30

========================================

Running SJF Non-Preemptive

Gantt chart
========================================

|  idle  |   P2   |   P4   |   P2   |   P4   |   P3   |  idle  |   P3   |   P1   |  idle  |   P1   |  idle  |   P1   |  idle  |   P1   |  idle  |
0        10       15       23       34       44      45        47       62      65        70      72        74      83        87      90        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      48      17      7               3               90              42              14              14
2       TERMINATED      10      16      2               1               34              24              4               0
3       TERMINATED      40      16      4               1               62              22              4               4
4       TERMINATED      15      18      10              1               44              29              8               0


Average waiting time: 7.50      Max: 14, Min: 4
Average turnaround time: 29.25  Max: 42, Min:22
Average response time: 4.50     Max: 14, Min: 0
Average completion time: 57.50  Max: 90, Min:34

========================================
```