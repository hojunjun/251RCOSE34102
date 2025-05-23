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
    - create process from files
    - create process from input
- queue
    - basic queue implementation
    - get shortest job
    - get highest priority job
- io
    - create hard coded io
    - create random io
    - create io from files
    - create io from input
- scheduler
    - fcfs
    - preemptive sjf
    - nonpreemptive sjf
    - preemptive priority
    - nonpreemptive priority
    - rr
- evaluation
    - average/max/min/variance waiting time
    - average/max/min/variance turnaround time
    - average/max/min/variance response time
    - average/max/min/variance completion time
    - cpu utilization
    - throughput
    - cpu time
    - io time
    - idle time
    - context switch
    - print gantt chart
    - print process table
    - comparation

## Todo
- scheduler
    - more algorithms

## Example
```
CPU Scheduling Simulator
========================================
1. Sample
2. Random
3. From file
4. Manual input
========================================
Enter your choice: 1

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


Average waiting time: 6.33      Max: 11, Min: 0, Variance: 21.56
Average turnaround time: 12.33  Max: 14, Min:10, Variance: 2.89
Average response time: 6.33     Max: 11, Min: 0, Variance: 21.56
Average completion time: 14.33  Max: 18, Min:10, Variance: 10.89
CPU Utilization: 100.00%
Throughput: 16.67 process per 100s
CPU time: 18
IO time: 0
Idle time: 0
Total time: 18
Context switch: 2 times

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


Average waiting time: 3.67      Max:  8, Min: 0, Variance: 10.89
Average turnaround time: 9.67   Max: 18, Min: 5, Variance: 34.89
Average response time: 1.00     Max:  3, Min: 0, Variance: 2.00
Average completion time: 11.67  Max: 18, Min: 7, Variance: 21.56
CPU Utilization: 100.00%
Throughput: 16.67 process per 100s
CPU time: 18
IO time: 0
Idle time: 0
Total time: 18
Context switch: 3 times

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


Average waiting time: 5.67      Max: 11, Min: 0, Variance: 20.22
Average turnaround time: 11.67  Max: 16, Min: 9, Variance: 9.56
Average response time: 5.67     Max: 11, Min: 0, Variance: 20.22
Average completion time: 13.67  Max: 18, Min:10, Variance: 10.89
CPU Utilization: 100.00%
Throughput: 16.67 process per 100s
CPU time: 18
IO time: 0
Idle time: 0
Total time: 18
Context switch: 2 times

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


Average waiting time: 4.67      Max: 11, Min: 0, Variance: 21.56
Average turnaround time: 10.67  Max: 16, Min: 3, Variance: 30.89
Average response time: 3.67     Max: 11, Min: 0, Variance: 26.89
Average completion time: 12.67  Max: 18, Min: 7, Variance: 20.22
CPU Utilization: 100.00%
Throughput: 16.67 process per 100s
CPU time: 18
IO time: 0
Idle time: 0
Total time: 18
Context switch: 3 times

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


Average waiting time: 5.67      Max: 11, Min: 0, Variance: 20.22
Average turnaround time: 11.67  Max: 16, Min: 9, Variance: 9.56
Average response time: 5.67     Max: 11, Min: 0, Variance: 20.22
Average completion time: 13.67  Max: 18, Min:10, Variance: 10.89
CPU Utilization: 100.00%
Throughput: 16.67 process per 100s
CPU time: 18
IO time: 0
Idle time: 0
Total time: 18
Context switch: 2 times

========================================


Running RR

Gantt chart
========================================

|   P1   |   P1   |   P2   |   P1   |   P3   |   P2   |   P1   |   P3   |   P2   |   P1   |  idle  |
0        2        4        6        8        10       12       14       15       16      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      2               0               18              18              8               0
2       TERMINATED      2       5       3               0               16              14              9               2
3       TERMINATED      4       3       1               0               15              11              8               4


Average waiting time: 8.33      Max:  9, Min: 8, Variance: 0.22
Average turnaround time: 14.33  Max: 18, Min:11, Variance: 8.22
Average response time: 2.00     Max:  4, Min: 0, Variance: 2.67
Average completion time: 16.33  Max: 18, Min:15, Variance: 1.56
CPU Utilization: 100.00%
Throughput: 16.67 process per 100s
CPU time: 18
IO time: 0
Idle time: 0
Total time: 18
Context switch: 8 times

========================================



Comparation
========================================
Preemptive SJF has shortest average waiting time: 3.67
36% shorter than average (5.72)

Preemptive SJF has shortest average turnaround time: 9.67
18% shorter than average (11.72)

Preemptive SJF has shortest average response time: 1.00
75% shorter than average (4.06)

FCFS has shortest max completion time: 18
Preemptive SJF has shortest max completion time: 18
Nonpreemptive SJF has shortest max completion time: 18
Preemptive Priority has shortest max completion time: 18
Nonpreemptive Priority has shortest max completion time: 18
RR has shortest max completion time: 18
All algorithms have same max completion time

RR has smallest variance of waiting time: 0.22
99% smaller than average (15.78)

FCFS has highest cpu utilization: 1.00
Preemptive SJF has highest cpu utilization: 1.00
Nonpreemptive SJF has highest cpu utilization: 1.00
Preemptive Priority has highest cpu utilization: 1.00
Nonpreemptive Priority has highest cpu utilization: 1.00
RR has highest cpu utilization: 1.00
All algorithms have same cpu utilization

FCFS has highest throughput: 0.17
Preemptive SJF has highest throughput: 0.17
Nonpreemptive SJF has highest throughput: 0.17
Preemptive Priority has highest throughput: 0.17
Nonpreemptive Priority has highest throughput: 0.17
RR has highest throughput: 0.17
All algorithms have same throughput

FCFS has smallest idle time: 0
Preemptive SJF has smallest idle time: 0
Nonpreemptive SJF has smallest idle time: 0
Preemptive Priority has smallest idle time: 0
Nonpreemptive Priority has smallest idle time: 0
RR has smallest idle time: 0
All algorithms have same idle time

FCFS has smallest context switch: 2
Nonpreemptive SJF has smallest context switch: 2
Nonpreemptive Priority has smallest context switch: 2
40% smaller than average (3.33)
```

```
CPU Scheduling Simulator
========================================
1. Sample
2. Random
3. From file
4. Manual input
========================================
Enter your choice: 2
Enter number of processes: 5

========================================
Process 1
Arrival Time: 39
Burst Time: 12
Priority: 7
IO Count: 1
IO 0 Request Time: 11
IO 0 Burst Time: 3
========================================

========================================
Process 2
Arrival Time: 10
Burst Time: 11
Priority: 4
IO Count: 2
IO 0 Request Time: 2
IO 0 Burst Time: 3
IO 1 Request Time: 7
IO 1 Burst Time: 5
========================================

========================================
Process 3
Arrival Time: 9
Burst Time: 16
Priority: 5
IO Count: 3
IO 0 Request Time: 1
IO 0 Burst Time: 2
IO 1 Request Time: 9
IO 1 Burst Time: 4
IO 2 Request Time: 10
IO 2 Burst Time: 3
========================================

========================================
Process 4
Arrival Time: 27
Burst Time: 18
Priority: 3
IO Count: 2
IO 0 Request Time: 8
IO 0 Burst Time: 3
IO 1 Request Time: 9
IO 1 Burst Time: 1
========================================

========================================
Process 5
Arrival Time: 3
Burst Time: 12
Priority: 1
IO Count: 2
IO 0 Request Time: 2
IO 0 Burst Time: 2
IO 1 Request Time: 9
IO 1 Burst Time: 1
========================================



Running FCFS

Gantt chart
========================================

|  idle  |   P5   |  idle  |   P5   |   P3   |   P2   |   P5   |   P3   |   P2   |   P4   |   P3   |   P2   |   P1   |   P4   |   P3   |   P4   |   P1   |  idle  |
0        3        5        7        14       15       17       20       28       33       41       42       46       57       58       64       73      74        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      39      12      7               1               74              35              20              7
2       TERMINATED      10      11      4               2               46              36              17              5
3       TERMINATED      9       16      5               3               64              55              30              5
4       TERMINATED      27      18      3               2               73              46              24              6
5       TERMINATED      3       12      1               2               20              17              2               0


Average waiting time: 18.60     Max: 30, Min: 2, Variance: 87.84
Average turnaround time: 37.80  Max: 55, Min:17, Variance: 161.36
Average response time: 4.60     Max:  7, Min: 0, Variance: 5.84
Average completion time: 55.40  Max: 74, Min:20, Variance: 414.24
CPU Utilization: 97.18%
Throughput: 7.04 process per 100s
CPU time: 69
IO time: 27
Idle time: 2
Total time: 71
Context switch: 13 times

========================================


Running SJF

Gantt chart
========================================

|  idle  |   P5   |  idle  |   P5   |   P2   |   P5   |   P2   |   P3   |  idle  |   P3   |   P2   |   P3   |   P1   |   P3   |   P1   |   P4   |  idle  |   P4   |  idle  |   P4   |  idle  |
0        3        5        7        14       16       19       24      25        27       35       39       40       51       57       58      66        69      70        71      80        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      39      12      7               1               58              19              4               1
2       TERMINATED      10      11      4               2               39              29              10              4
3       TERMINATED      9       16      5               3               57              48              23              15
4       TERMINATED      27      18      3               2               80              53              31              31
5       TERMINATED      3       12      1               2               19              16              1               0


Average waiting time: 13.80     Max: 31, Min: 1, Variance: 130.96
Average turnaround time: 33.00  Max: 53, Min:16, Variance: 225.20
Average response time: 10.20    Max: 31, Min: 0, Variance: 136.56
Average completion time: 50.60  Max: 80, Min:19, Variance: 418.64
CPU Utilization: 89.61%
Throughput: 6.49 process per 100s
CPU time: 69
IO time: 27
Idle time: 8
Total time: 77
Context switch: 10 times

========================================


Running SJF Non-Preemptive

Gantt chart
========================================

|  idle  |   P5   |  idle  |   P5   |   P2   |   P5   |   P2   |   P3   |  idle  |   P3   |   P2   |   P3   |   P1   |   P3   |   P1   |   P4   |  idle  |   P4   |  idle  |   P4   |  idle  |
0        3        5        7        14       16       19       24      25        27       35       39       40       51       57       58      66        69      70        71      80        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      39      12      7               1               58              19              4               1
2       TERMINATED      10      11      4               2               39              29              10              4
3       TERMINATED      9       16      5               3               57              48              23              15
4       TERMINATED      27      18      3               2               80              53              31              31
5       TERMINATED      3       12      1               2               19              16              1               0


Average waiting time: 13.80     Max: 31, Min: 1, Variance: 130.96
Average turnaround time: 33.00  Max: 53, Min:16, Variance: 225.20
Average response time: 10.20    Max: 31, Min: 0, Variance: 136.56
Average completion time: 50.60  Max: 80, Min:19, Variance: 418.64
CPU Utilization: 89.61%
Throughput: 6.49 process per 100s
CPU time: 69
IO time: 27
Idle time: 8
Total time: 77
Context switch: 10 times

========================================


Running Priority

Gantt chart
========================================

|  idle  |   P5   |  idle  |   P5   |   P2   |   P5   |   P2   |   P3   |  idle  |   P4   |   P2   |   P4   |   P3   |   P4   |   P3   |   P1   |   P3   |   P1   |  idle  |
0        3        5        7        14       16       19       24      25        27       35       39       40       48       57       58       69       75      76        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      39      12      7               1               76              37              22              19
2       TERMINATED      10      11      4               2               39              29              10              4
3       TERMINATED      9       16      5               3               75              66              41              15
4       TERMINATED      27      18      3               2               57              30              8               0
5       TERMINATED      3       12      1               2               19              16              1               0


Average waiting time: 16.40     Max: 41, Min: 1, Variance: 197.04
Average turnaround time: 35.60  Max: 66, Min:16, Variance: 277.04
Average response time: 7.60     Max: 19, Min: 0, Variance: 62.64
Average completion time: 53.20  Max: 76, Min:19, Variance: 476.16
CPU Utilization: 94.52%
Throughput: 6.85 process per 100s
CPU time: 69
IO time: 27
Idle time: 4
Total time: 73
Context switch: 13 times

========================================


Running Priority Non-Preemptive

Gantt chart
========================================

|  idle  |   P5   |  idle  |   P5   |   P2   |   P5   |   P2   |   P3   |  idle  |   P4   |   P2   |   P4   |   P3   |   P4   |   P3   |   P1   |   P3   |   P1   |  idle  |
0        3        5        7        14       16       19       24      25        27       35       39       40       48       57       58       69       75      76        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      39      12      7               1               76              37              22              19
2       TERMINATED      10      11      4               2               39              29              10              4
3       TERMINATED      9       16      5               3               75              66              41              15
4       TERMINATED      27      18      3               2               57              30              8               0
5       TERMINATED      3       12      1               2               19              16              1               0


Average waiting time: 16.40     Max: 41, Min: 1, Variance: 197.04
Average turnaround time: 35.60  Max: 66, Min:16, Variance: 277.04
Average response time: 7.60     Max: 19, Min: 0, Variance: 62.64
Average completion time: 53.20  Max: 76, Min:19, Variance: 476.16
CPU Utilization: 94.52%
Throughput: 6.85 process per 100s
CPU time: 69
IO time: 27
Idle time: 4
Total time: 73
Context switch: 13 times

========================================


Running RR

Gantt chart
========================================

|  idle  |   P5   |  idle  |   P5   |   P5   |   P3   |   P2   |   P5   |   P3   |   P5   |   P2   |   P3   |   P5   |   P2   |   P3   |   P5   |   P2   |   P4   |   P3   |   P4   |   P2   |   P4   |   P2   |   P1   |   P3   |   P4   |   P1   |   P3   |   P1   |   P4   |   P3   |   P1   |   P4   |   P3   |   P1   |   P4   |   P1   |   P4   |   P4   |   P1   |   P4   |  idle  |
0        3        5        7        9        11       12       14       16       18       19       21       23       25       27       29       30       31       33       35       37       39       41       43       45       46       48       50       52       54       55       57       59       61       63       65       67       68       70       72       73      74        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      39      12      7               1               73              34              19              4
2       TERMINATED      10      11      4               2               43              33              14              2
3       TERMINATED      9       16      5               3               63              54              29              2
4       TERMINATED      27      18      3               2               74              47              25              4
5       TERMINATED      3       12      1               2               30              27              12              0


Average waiting time: 19.80     Max: 29, Min:12, Variance: 41.36
Average turnaround time: 39.00  Max: 54, Min:27, Variance: 98.80
Average response time: 2.40     Max:  4, Min: 0, Variance: 2.24
Average completion time: 56.60  Max: 74, Min:30, Variance: 301.04
CPU Utilization: 97.18%
Throughput: 7.04 process per 100s
CPU time: 69
IO time: 27
Idle time: 2
Total time: 71
Context switch: 35 times

========================================



Comparation
========================================
Preemptive SJF has shortest average waiting time: 13.80
Nonpreemptive SJF has shortest average waiting time: 13.80
16% shorter than average (16.47)

Preemptive SJF has shortest average turnaround time: 33.00
Nonpreemptive SJF has shortest average turnaround time: 33.00
7% shorter than average (35.67)

RR has shortest average response time: 2.40
66% shorter than average (7.10)

FCFS has shortest max completion time: 74
RR has shortest max completion time: 74
3% shorter than average (76.67)

RR has smallest variance of waiting time: 41.36
68% smaller than average (130.87)

FCFS has highest cpu utilization: 0.97
RR has highest cpu utilization: 0.97
4% higher than average (0.94)

FCFS has highest throughput: 0.07
RR has highest throughput: 0.07
4% higher than average (0.07)

FCFS has smallest idle time: 2
RR has smallest idle time: 2
57% smaller than average (4.67)

Preemptive SJF has smallest context switch: 10
Nonpreemptive SJF has smallest context switch: 10
36% smaller than average (15.67)
```

```
CPU Scheduling Simulator
========================================
1. Sample
2. Random
3. From file
4. Manual input
========================================
Enter your choice: 3
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


Average waiting time: 10.75     Max: 15, Min: 7, Variance: 8.19
Average turnaround time: 30.00  Max: 34, Min:24, Variance: 14.00
Average response time: 3.50     Max:  7, Min: 0, Variance: 12.25
Average completion time: 57.50  Max: 70, Min:45, Variance: 99.25
CPU Utilization: 89.09%
Throughput: 7.27 process per 100s
CPU time: 49
IO time: 28
Idle time: 6
Total time: 55
Context switch: 12 times

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


Average waiting time: 10.75     Max: 15, Min: 7, Variance: 8.19
Average turnaround time: 30.00  Max: 34, Min:24, Variance: 14.00
Average response time: 1.75     Max:  7, Min: 0, Variance: 9.19
Average completion time: 57.50  Max: 70, Min:45, Variance: 99.25
CPU Utilization: 89.09%
Throughput: 7.27 process per 100s
CPU time: 49
IO time: 28
Idle time: 6
Total time: 55
Context switch: 13 times

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


Average waiting time: 9.50      Max: 21, Min: 3, Variance: 48.75
Average turnaround time: 28.75  Max: 40, Min:17, Variance: 66.69
Average response time: 6.00     Max: 21, Min: 0, Variance: 76.50
Average completion time: 56.25  Max: 70, Min:43, Variance: 115.69
CPU Utilization: 89.09%
Throughput: 7.27 process per 100s
CPU time: 49
IO time: 28
Idle time: 6
Total time: 55
Context switch: 11 times

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


Average waiting time: 10.25     Max: 24, Min: 1, Variance: 75.69
Average turnaround time: 29.50  Max: 43, Min:15, Variance: 100.25
Average response time: 5.75     Max: 23, Min: 0, Variance: 99.19
Average completion time: 57.00  Max: 73, Min:43, Variance: 126.00
CPU Utilization: 84.48%
Throughput: 6.90 process per 100s
CPU time: 49
IO time: 28
Idle time: 9
Total time: 58
Context switch: 11 times

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


Average waiting time: 9.50      Max: 21, Min: 3, Variance: 48.75
Average turnaround time: 28.75  Max: 40, Min:17, Variance: 66.69
Average response time: 6.00     Max: 21, Min: 0, Variance: 76.50
Average completion time: 56.25  Max: 70, Min:43, Variance: 115.69
CPU Utilization: 89.09%
Throughput: 7.27 process per 100s
CPU time: 49
IO time: 28
Idle time: 6
Total time: 55
Context switch: 11 times

========================================


Running RR

Gantt chart
========================================

|  idle  |   P1   |   P1   |  idle  |   P3   |   P3   |   P1   |   P1   |   P3   |   P1   |   P3   |   P4   |   P3   |   P1   |   P3   |   P1   |   P4   |   P3   |   P1   |   P2   |   P3   |   P4   |   P3   |   P2   |   P4   |   P3   |   P4   |   P2   |   P2   |  idle  |
0        15       17      18        19       21       22       24       26       28       30       32       34       36       38       40       42       44       45       47       49       51       53       55       57       58       60       62       64      65        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               47              32              9               0
2       TERMINATED      46      7       8               2               65              19              5               1
3       TERMINATED      19      18      9               2               60              41              20              0
4       TERMINATED      30      9       10              3               62              32              13              2


Average waiting time: 11.75     Max: 20, Min: 5, Variance: 30.69
Average turnaround time: 31.00  Max: 41, Min:19, Variance: 61.50
Average response time: 0.75     Max:  2, Min: 0, Variance: 0.69
Average completion time: 58.50  Max: 65, Min:47, Variance: 47.25
CPU Utilization: 98.00%
Throughput: 8.00 process per 100s
CPU time: 49
IO time: 28
Idle time: 1
Total time: 50
Context switch: 22 times

========================================



Comparation
========================================
Nonpreemptive SJF has shortest average waiting time: 9.50
Nonpreemptive Priority has shortest average waiting time: 9.50
9% shorter than average (10.42)

Nonpreemptive SJF has shortest average turnaround time: 28.75
Nonpreemptive Priority has shortest average turnaround time: 28.75
3% shorter than average (29.67)

RR has shortest average response time: 0.75
81% shorter than average (3.96)

RR has shortest max completion time: 65
7% shorter than average (69.67)

FCFS has smallest variance of waiting time: 8.19
Preemptive SJF has smallest variance of waiting time: 8.19
78% smaller than average (36.71)

RR has highest cpu utilization: 0.98
9% higher than average (0.90)

RR has highest throughput: 0.08
9% higher than average (0.07)

RR has smallest idle time: 1
82% smaller than average (5.67)

Nonpreemptive SJF has smallest context switch: 11
Preemptive Priority has smallest context switch: 11
Nonpreemptive Priority has smallest context switch: 11
17% smaller than average (13.33)
```
