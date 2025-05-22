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
    - preemptive priority
    - nonpreemptive priority
    - rr
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
    - more algorithms
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
Arrival Time: 15
Burst Time: 15
Priority: 9
IO Count: 2
IO 0 Request Time: 3
IO 0 Burst Time: 3
IO 1 Request Time: 9
IO 1 Burst Time: 5
========================================

========================================
Process 2
Arrival Time: 46
Burst Time: 7
Priority: 8
IO Count: 2
IO 0 Request Time: 2
IO 0 Burst Time: 2
IO 1 Request Time: 4
IO 1 Burst Time: 5
========================================

========================================
Process 3
Arrival Time: 19
Burst Time: 18
Priority: 9
IO Count: 2
IO 0 Request Time: 3
IO 0 Burst Time: 2
IO 1 Request Time: 12
IO 1 Burst Time: 1
========================================

========================================
Process 4
Arrival Time: 30
Burst Time: 9
Priority: 10
IO Count: 3
IO 0 Request Time: 2
IO 0 Burst Time: 5
IO 1 Request Time: 4
IO 1 Burst Time: 4
IO 2 Request Time: 7
IO 2 Burst Time: 1
========================================
Running FCFS

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P4   |   P1   |   P3   |   P4   |   P2   |  idle  |   P4   |   P2   |   P4   |  idle  |   P2   |  idle  |
0        15      18        19       22       28       37       39       45       51       53      55        57       60       62      64        67      70        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               45              30              7               0
2       TERMINATED      46      7       8               2               70              24              10              7
3       TERMINATED      19      18      9               2               51              32              11              0
4       TERMINATED      30      9       10              3               64              34              15              7


Average waiting time: 10.75     Max: 15, Min: 7
Average turnaround time: 30.00  Max: 34, Min:24
Average response time: 3.50     Max:  7, Min: 0
Average completion time: 57.50  Max: 70, Min:45

========================================

Running SJF

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P4   |   P3   |   P1   |   P3   |   P4   |   P2   |  idle  |   P4   |   P2   |   P4   |  idle  |   P2   |  idle  |
0        15      18        19       22       28       30       32       39       45       51       53      55        57       60       62      64        67      70        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               45              30              7               0
2       TERMINATED      46      7       8               2               70              24              10              7
3       TERMINATED      19      18      9               2               51              32              11              0
4       TERMINATED      30      9       10              3               64              34              15              0


Average waiting time: 10.75     Max: 15, Min: 7
Average turnaround time: 30.00  Max: 34, Min:24
Average response time: 1.75     Max:  7, Min: 0
Average completion time: 57.50  Max: 70, Min:45

========================================

Running SJF Non-Preemptive

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P1   |   P3   |   P2   |   P4   |   P2   |  idle  |   P4   |   P2   |  idle  |   P4   |  idle  |   P4   |  idle  |
0        15      18        19       22       28       37       43       49       51       53      55        58       60      63        64      67        68      70        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               43              28              5               0
2       TERMINATED      46      7       8               2               63              17              3               3
3       TERMINATED      19      18      9               2               49              30              9               0
4       TERMINATED      30      9       10              3               70              40              21              21


Average waiting time: 9.50      Max: 21, Min: 3
Average turnaround time: 28.75  Max: 40, Min:17
Average response time: 6.00     Max: 21, Min: 0
Average completion time: 56.25  Max: 70, Min:43

========================================

Running Priority

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P1   |   P3   |   P2   |   P3   |   P2   |   P4   |  idle  |   P2   |   P4   |  idle  |   P4   |  idle  |   P4   |  idle  |
0        15      18        19       22       28       37       43       46       48       51       53      55        58       61      63        67      70        71      73        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               43              28              5               0
2       TERMINATED      46      7       8               2               61              15              1               0
3       TERMINATED      19      18      9               2               51              32              11              0
4       TERMINATED      30      9       10              3               73              43              24              23


Average waiting time: 10.25     Max: 24, Min: 1
Average turnaround time: 29.50  Max: 43, Min:15
Average response time: 5.75     Max: 23, Min: 0
Average completion time: 57.00  Max: 73, Min:43

========================================

Running Priority Non-Preemptive

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P1   |   P3   |   P2   |   P4   |   P2   |  idle  |   P4   |   P2   |  idle  |   P4   |  idle  |   P4   |  idle  |
0        15      18        19       22       28       37       43       49       51       53      55        58       60      63        64      67        68      70        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               43              28              5               0
2       TERMINATED      46      7       8               2               63              17              3               3
3       TERMINATED      19      18      9               2               49              30              9               0
4       TERMINATED      30      9       10              3               70              40              21              21


Average waiting time: 9.50      Max: 21, Min: 3
Average turnaround time: 28.75  Max: 40, Min:17
Average response time: 6.00     Max: 21, Min: 0
Average completion time: 56.25  Max: 70, Min:43

========================================

Running RR

Gantt chart
========================================

|  idle  |   P1   |   P1   |  idle  |   P3   |   P3   |   P1   |   P1   |   P3   |   P1   |   P3   |   P4   |   P3   |   P1   |   P3   |   P1   |   P4   |   P3   |   P1   |  idle  |   P1   |   P2   |   P3   |   P1   |   P4   |   P3   |   P2   |   P4   |   P3   |  idle  |   P3   |   P4   |  idle  |   P4   |  idle  |
0        15       17      18        19       21       22       24       26       28       30       32       34       36       38       40       42       44       45      47        45       47       49       51       52       54       56       58       59      61        59       61      63        61      63        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               52              37              13              0
2       READY           46      7       8               2               0               0               7               1
3       RUNNING         19      18      9               2               61              42              23              0
4       TERMINATED      30      9       10              3               63              33              15              2


Average waiting time: 14.50     Max: 23, Min: 7
Average turnaround time: 28.00  Max: 42, Min: 0
Average response time: 0.75     Max:  2, Min: 0
Average completion time: 44.00  Max: 63, Min: 0

========================================
```

```
CPU Scheduling Simulator
========================================
1. Random
2. File
========================================
Enter your choice: 2
Enter number of processes: 3

========================================
Process 1
Arrival Time: 0
Burst Time: 10
Priority: 2
IO Count: 0
========================================

========================================
Process 2
Arrival Time: 2
Burst Time: 5
Priority: 3
IO Count: 0
========================================

========================================
Process 3
Arrival Time: 4
Burst Time: 3
Priority: 1
IO Count: 0
========================================
Running FCFS

Gantt chart
========================================

|   P1   |   P2   |   P3   |  idle  |
0        10       15      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      2               0               10              10              0               0
2       TERMINATED      2       5       3               0               15              13              8               8
3       TERMINATED      4       3       1               0               18              14              11              11


Average waiting time: 6.33      Max: 11, Min: 0
Average turnaround time: 12.33  Max: 14, Min:10
Average response time: 6.33     Max: 11, Min: 0
Average completion time: 14.33  Max: 18, Min:10

========================================

Running SJF

Gantt chart
========================================

|   P1   |   P2   |   P3   |   P1   |  idle  |
0        2        7        10      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      2               0               18              18              8               0
2       TERMINATED      2       5       3               0               7               5               0               0
3       TERMINATED      4       3       1               0               10              6               3               3


Average waiting time: 3.67      Max:  8, Min: 0
Average turnaround time: 9.67   Max: 18, Min: 5
Average response time: 1.00     Max:  3, Min: 0
Average completion time: 11.67  Max: 18, Min: 7

========================================

Running SJF Non-Preemptive

Gantt chart
========================================

|   P1   |   P3   |   P2   |  idle  |
0        10       13      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      2               0               10              10              0               0
2       TERMINATED      2       5       3               0               18              16              11              11
3       TERMINATED      4       3       1               0               13              9               6               6


Average waiting time: 5.67      Max: 11, Min: 0
Average turnaround time: 11.67  Max: 16, Min: 9
Average response time: 5.67     Max: 11, Min: 0
Average completion time: 13.67  Max: 18, Min:10

========================================

Running Priority

Gantt chart
========================================

|   P1   |   P3   |   P1   |   P2   |  idle  |
0        4        7        13      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      2               0               13              13              3               0
2       TERMINATED      2       5       3               0               18              16              11              11
3       TERMINATED      4       3       1               0               7               3               0               0


Average waiting time: 4.67      Max: 11, Min: 0
Average turnaround time: 10.67  Max: 16, Min: 3
Average response time: 3.67     Max: 11, Min: 0
Average completion time: 12.67  Max: 18, Min: 7

========================================

Running Priority Non-Preemptive

Gantt chart
========================================

|   P1   |   P3   |   P2   |  idle  |
0        10       13      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      2               0               10              10              0               0
2       TERMINATED      2       5       3               0               18              16              11              11
3       TERMINATED      4       3       1               0               13              9               6               6


Average waiting time: 5.67      Max: 11, Min: 0
Average turnaround time: 11.67  Max: 16, Min: 9
Average response time: 5.67     Max: 11, Min: 0
Average completion time: 13.67  Max: 18, Min:10

========================================

Running RR

Gantt chart
========================================

|   P1   |   P1   |   P2   |   P1   |   P3   |   P2   |   P1   |   P3   |   P2   |   P1   |  idle  |   P1   |  idle  |
0        2        4        6        8        10       12       14       15       16      18        16      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       RUNNING         0       10      2               0               18              18              8               0
2       TERMINATED      2       5       3               0               16              14              9               2
3       TERMINATED      4       3       1               0               15              11              8               4


Average waiting time: 8.33      Max:  9, Min: 8
Average turnaround time: 14.33  Max: 18, Min:11
Average response time: 2.00     Max:  4, Min: 0
Average completion time: 16.33  Max: 18, Min:15

========================================
```