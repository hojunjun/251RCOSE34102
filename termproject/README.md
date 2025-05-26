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
    - aging preemptive priority
    - aging nonpreemptive priority
    - preemptive hrrn
    - nonpreemptive hrrn
    - preemptive cfs
    - nonpreemptive cfs
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
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      2               0               10              10              0              0
2       TERMINATED      2       5       3               0               15              13              8              8
3       TERMINATED      4       3       1               0               18              14              11             11


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
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      2               0               18              18              8              0
2       TERMINATED      2       5       3               0               7               5               0              0
3       TERMINATED      4       3       1               0               10              6               3              3


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
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      2               0               10              10              0              0
2       TERMINATED      2       5       3               0               18              16              11             11
3       TERMINATED      4       3       1               0               13              9               6              6


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
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      2               0               13              13              3              0
2       TERMINATED      2       5       3               0               18              16              11             11
3       TERMINATED      4       3       1               0               7               3               0              0


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
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      2               0               10              10              0              0
2       TERMINATED      2       5       3               0               18              16              11             11
3       TERMINATED      4       3       1               0               13              9               6              6


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
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      2               0               18              18              8              0
2       TERMINATED      2       5       3               0               16              14              9              2
3       TERMINATED      4       3       1               0               15              11              8              4


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


Running Aging Priority

Gantt chart
========================================

|   P1   |   P3   |   P2   |   P1   |   P2   |  idle  |
0        4        7        9        15      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      1               0               15              15              5              0
2       TERMINATED      2       5       1               0               18              16              11             5
3       TERMINATED      4       3       1               0               7               3               0              0


Average waiting time: 5.33      Max: 11, Min: 0, Variance: 20.22
Average turnaround time: 11.33  Max: 16, Min: 3, Variance: 34.89
Average response time: 1.67     Max:  5, Min: 0, Variance: 5.56
Average completion time: 13.33  Max: 18, Min: 7, Variance: 21.56
CPU Utilization: 100.00%
Throughput: 16.67 process per 100s
CPU time: 18
IO time: 0
Idle time: 0
Total time: 18
Context switch: 4 times

========================================


Running Aging Priority Non-Preemptive

Gantt chart
========================================

|   P1   |   P3   |   P2   |  idle  |
0        10       13      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      2               0               10              10              0              0
2       TERMINATED      2       5       1               0               18              16              11             11
3       TERMINATED      4       3       0               0               13              9               6              6


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


Running HRRN

Gantt chart
========================================

|   P1   |   P2   |   P3   |   P2   |   P3   |   P2   |   P1   |  idle  |
0        3        5        6        7        9        11      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      -1800           0               18              18              8              0
2       TERMINATED      2       5       -1800           0               11              9               4              1
3       TERMINATED      4       3       -1666           0               9               5               2              1


Average waiting time: 4.67      Max:  8, Min: 2, Variance: 6.22
Average turnaround time: 10.67  Max: 18, Min: 5, Variance: 29.56
Average response time: 0.67     Max:  1, Min: 0, Variance: 0.22
Average completion time: 12.67  Max: 18, Min: 9, Variance: 14.89
CPU Utilization: 100.00%
Throughput: 16.67 process per 100s
CPU time: 18
IO time: 0
Idle time: 0
Total time: 18
Context switch: 6 times

========================================


Running HRRN Non-Preemptive

Gantt chart
========================================

|   P1   |   P3   |   P2   |  idle  |
0        10       13      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      0               0               10              10              0              0
2       TERMINATED      2       5       -3200           0               18              16              11             11
3       TERMINATED      4       3       -3000           0               13              9               6              6


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


Running CFS

Gantt chart
========================================

|   P1   |   P2   |   P3   |   P2   |   P1   |   P2   |   P1   |  idle  |
0        3        5        8        10       12       13      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      10              0               18              18              8              0
2       TERMINATED      2       5       5               0               13              11              6              1
3       TERMINATED      4       3       3               0               8               4               1              1


Average waiting time: 5.00      Max:  8, Min: 1, Variance: 8.67
Average turnaround time: 11.00  Max: 18, Min: 4, Variance: 32.67
Average response time: 0.67     Max:  1, Min: 0, Variance: 0.22
Average completion time: 13.00  Max: 18, Min: 8, Variance: 16.67
CPU Utilization: 100.00%
Throughput: 16.67 process per 100s
CPU time: 18
IO time: 0
Idle time: 0
Total time: 18
Context switch: 6 times

========================================


Running CFS Non-Preemptive

Gantt chart
========================================

|   P1   |   P2   |   P3   |  idle  |
0        10       15      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      10              0               10              10              0              0
2       TERMINATED      2       5       5               0               15              13              8              8
3       TERMINATED      4       3       3               0               18              14              11             11


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



Comparation
========================================
Preemptive SJF has shortest average waiting time: 3.67
34% shorter than average (5.58)

Preemptive SJF has shortest average turnaround time: 9.67
17% shorter than average (11.58)

Preemptive HRRN has shortest average response time: 0.67
Preemptive CFS has shortest average response time: 0.67
82% shorter than average (3.75)

FCFS has shortest max completion time: 18
Preemptive SJF has shortest max completion time: 18
Nonpreemptive SJF has shortest max completion time: 18
Preemptive Priority has shortest max completion time: 18
Nonpreemptive Priority has shortest max completion time: 18
RR has shortest max completion time: 18
Aging Preemptive Priority has shortest max completion time: 18
Aging Nonpreemptive Priority has shortest max completion time: 18
Preemptive HRRN has shortest max completion time: 18
Nonpreemptive HRRN has shortest max completion time: 18
Preemptive CFS has shortest max completion time: 18
Nonpreemptive CFS has shortest max completion time: 18
All algorithms have same max completion time

RR has smallest variance of waiting time: 0.22
99% smaller than average (15.98)

FCFS has highest cpu utilization: 1.00
Preemptive SJF has highest cpu utilization: 1.00
Nonpreemptive SJF has highest cpu utilization: 1.00
Preemptive Priority has highest cpu utilization: 1.00
Nonpreemptive Priority has highest cpu utilization: 1.00
RR has highest cpu utilization: 1.00
Aging Preemptive Priority has highest cpu utilization: 1.00
Aging Nonpreemptive Priority has highest cpu utilization: 1.00
Preemptive HRRN has highest cpu utilization: 1.00
Nonpreemptive HRRN has highest cpu utilization: 1.00
Preemptive CFS has highest cpu utilization: 1.00
Nonpreemptive CFS has highest cpu utilization: 1.00
All algorithms have same cpu utilization

FCFS has highest throughput: 0.17
Preemptive SJF has highest throughput: 0.17
Nonpreemptive SJF has highest throughput: 0.17
Preemptive Priority has highest throughput: 0.17
Nonpreemptive Priority has highest throughput: 0.17
RR has highest throughput: 0.17
Aging Preemptive Priority has highest throughput: 0.17
Aging Nonpreemptive Priority has highest throughput: 0.17
Preemptive HRRN has highest throughput: 0.17
Nonpreemptive HRRN has highest throughput: 0.17
Preemptive CFS has highest throughput: 0.17
Nonpreemptive CFS has highest throughput: 0.17
All algorithms have same throughput

FCFS has smallest idle time: 0
Preemptive SJF has smallest idle time: 0
Nonpreemptive SJF has smallest idle time: 0
Preemptive Priority has smallest idle time: 0
Nonpreemptive Priority has smallest idle time: 0
RR has smallest idle time: 0
Aging Preemptive Priority has smallest idle time: 0
Aging Nonpreemptive Priority has smallest idle time: 0
Preemptive HRRN has smallest idle time: 0
Nonpreemptive HRRN has smallest idle time: 0
Preemptive CFS has smallest idle time: 0
Nonpreemptive CFS has smallest idle time: 0
All algorithms have same idle time

FCFS has smallest context switch: 2
Nonpreemptive SJF has smallest context switch: 2
Nonpreemptive Priority has smallest context switch: 2
Aging Nonpreemptive Priority has smallest context switch: 2
Nonpreemptive HRRN has smallest context switch: 2
Nonpreemptive CFS has smallest context switch: 2
43% smaller than average (3.50)
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
Arrival Time: 28
Burst Time: 10
Priority: 7
IO Count: 1
IO 0 Request Time: 4
IO 0 Burst Time: 3
========================================

========================================
Process 2
Arrival Time: 5
Burst Time: 8
Priority: 3
IO Count: 2
IO 0 Request Time: 1
IO 0 Burst Time: 3
IO 1 Request Time: 6
IO 1 Burst Time: 5
========================================

========================================
Process 3
Arrival Time: 3
Burst Time: 17
Priority: 1
IO Count: 1
IO 0 Request Time: 13
IO 0 Burst Time: 1
========================================

========================================
Process 4
Arrival Time: 31
Burst Time: 6
Priority: 5
IO Count: 2
IO 0 Request Time: 2
IO 0 Burst Time: 4
IO 1 Request Time: 5
IO 1 Burst Time: 4
========================================

========================================
Process 5
Arrival Time: 19
Burst Time: 16
Priority: 6
IO Count: 3
IO 0 Request Time: 4
IO 0 Burst Time: 2
IO 1 Request Time: 9
IO 1 Burst Time: 2
IO 2 Request Time: 14
IO 2 Burst Time: 5
========================================



Running FCFS

Gantt chart
========================================

|  idle  |   P3   |   P2   |   P3   |   P5   |   P2   |   P5   |   P1   |   P4   |   P2   |   P5   |   P1   |   P4   |   P5   |  idle  |   P4   |  idle  |
0        3        16       17       21       25       30       35       39       41       43       48       54       57      59        61      62        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      7               1               54              26              13             7
2       TERMINATED      5       8       3               2               43              38              22             11
3       TERMINATED      3       17      1               1               21              18              0              0
4       TERMINATED      31      6       5               2               62              31              17             8
5       TERMINATED      19      16      6               3               59              40              15             2


Average waiting time: 13.40     Max: 22, Min: 0, Variance: 53.84
Average turnaround time: 30.60  Max: 40, Min:18, Variance: 64.64
Average response time: 5.60     Max: 11, Min: 0, Variance: 16.24
Average completion time: 47.80  Max: 62, Min:21, Variance: 221.36
CPU Utilization: 96.61%
Throughput: 8.47 process per 100s
CPU time: 57
IO time: 29
Idle time: 2
Total time: 59
Context switch: 13 times

========================================


Running SJF

Gantt chart
========================================

|  idle  |   P3   |   P2   |   P3   |   P2   |   P3   |   P5   |   P2   |   P1   |   P4   |   P1   |   P5   |   P4   |   P1   |   P4   |   P5   |  idle  |   P5   |  idle  |   P5   |  idle  |
0        3        5        6        17       22       26       28       30       31       33       36       38       41       47       48      53        55      60        65      67        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      7               1               47              19              6              2
2       TERMINATED      5       8       3               2               30              25              9              0
3       TERMINATED      3       17      1               1               26              23              5              0
4       TERMINATED      31      6       5               2               48              17              3              0
5       TERMINATED      19      16      6               3               67              48              23             7


Average waiting time: 9.20      Max: 23, Min: 3, Variance: 51.36
Average turnaround time: 26.40  Max: 48, Min:17, Variance: 124.64
Average response time: 1.80     Max:  7, Min: 0, Variance: 7.36
Average completion time: 43.60  Max: 67, Min:26, Variance: 214.64
CPU Utilization: 89.06%
Throughput: 7.81 process per 100s
CPU time: 57
IO time: 29
Idle time: 7
Total time: 64
Context switch: 14 times

========================================


Running SJF Non-Preemptive

Gantt chart
========================================

|  idle  |   P3   |   P2   |   P3   |   P2   |   P5   |   P1   |   P2   |   P4   |   P1   |   P4   |   P5   |   P4   |  idle  |   P5   |  idle  |   P5   |  idle  |
0        3        16       17       21       26       30       34       36       38       44       47       52      53        54      59        64      66        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      7               1               44              16              3              2
2       TERMINATED      5       8       3               2               36              31              15             11
3       TERMINATED      3       17      1               1               21              18              0              0
4       TERMINATED      31      6       5               2               53              22              8              5
5       TERMINATED      19      16      6               3               66              47              22             7


Average waiting time: 9.60      Max: 22, Min: 0, Variance: 64.24
Average turnaround time: 26.80  Max: 47, Min:16, Variance: 128.56
Average response time: 5.00     Max: 11, Min: 0, Variance: 14.80
Average completion time: 44.00  Max: 66, Min:21, Variance: 231.60
CPU Utilization: 90.48%
Throughput: 7.94 process per 100s
CPU time: 57
IO time: 29
Idle time: 6
Total time: 63
Context switch: 12 times

========================================


Running Priority

Gantt chart
========================================

|  idle  |   P3   |   P2   |   P3   |   P2   |   P5   |   P1   |   P2   |   P4   |   P5   |   P4   |   P5   |   P4   |   P1   |  idle  |   P5   |   P1   |  idle  |
0        3        16       17       21       26       30       31       33       35       40       43       48       49      52        53       55      61        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      7               1               61              33              20             2
2       TERMINATED      5       8       3               2               33              28              12             11
3       TERMINATED      3       17      1               1               21              18              0              0
4       TERMINATED      31      6       5               2               49              18              4              2
5       TERMINATED      19      16      6               3               55              36              11             7


Average waiting time: 9.40      Max: 20, Min: 0, Variance: 47.84
Average turnaround time: 26.60  Max: 36, Min:18, Variance: 55.84
Average response time: 4.40     Max: 11, Min: 0, Variance: 16.24
Average completion time: 43.80  Max: 61, Min:21, Variance: 216.96
CPU Utilization: 98.28%
Throughput: 8.62 process per 100s
CPU time: 57
IO time: 29
Idle time: 1
Total time: 58
Context switch: 14 times

========================================


Running Priority Non-Preemptive

Gantt chart
========================================

|  idle  |   P3   |   P2   |   P3   |   P2   |   P5   |   P1   |   P2   |   P4   |   P5   |   P4   |   P5   |   P4   |   P1   |   P5   |  idle  |
0        3        16       17       21       26       30       34       36       38       43       46       51       52       58      60        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      7               1               58              30              17             2
2       TERMINATED      5       8       3               2               36              31              15             11
3       TERMINATED      3       17      1               1               21              18              0              0
4       TERMINATED      31      6       5               2               52              21              7              5
5       TERMINATED      19      16      6               3               60              41              16             7


Average waiting time: 11.00     Max: 17, Min: 0, Variance: 42.80
Average turnaround time: 28.20  Max: 41, Min:18, Variance: 66.16
Average response time: 5.00     Max: 11, Min: 0, Variance: 14.80
Average completion time: 45.40  Max: 60, Min:21, Variance: 219.84
CPU Utilization: 100.00%
Throughput: 8.77 process per 100s
CPU time: 57
IO time: 29
Idle time: 0
Total time: 57
Context switch: 13 times

========================================


Running RR

Gantt chart
========================================

|  idle  |   P3   |   P3   |   P2   |   P3   |   P3   |   P2   |   P3   |   P2   |   P3   |   P2   |   P5   |   P3   |   P5   |   P3   |   P2   |   P3   |   P1   |   P5   |   P4   |   P1   |   P5   |   P5   |   P4   |   P1   |   P4   |   P5   |   P1   |   P5   |   P1   |   P4   |   P5   |  idle  |   P5   |  idle  |
0        3        5        7        8        10       12       14       16       18       20       21       23       24       26       28       30       32       34       36       38       40       42       43       45       47       48       50       52       54       56       57      58        63      65        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      7               1               56              28              15             4
2       TERMINATED      5       8       3               2               30              25              9              2
3       TERMINATED      3       17      1               1               32              29              11             0
4       TERMINATED      31      6       5               2               57              26              12             5
5       TERMINATED      19      16      6               3               65              46              21             2


Average waiting time: 13.60     Max: 21, Min: 9, Variance: 17.44
Average turnaround time: 30.80  Max: 46, Min:25, Variance: 59.76
Average response time: 2.60     Max:  5, Min: 0, Variance: 3.04
Average completion time: 48.00  Max: 65, Min:30, Variance: 202.80
CPU Utilization: 91.94%
Throughput: 8.06 process per 100s
CPU time: 57
IO time: 29
Idle time: 5
Total time: 62
Context switch: 27 times

========================================


Running Aging Priority

Gantt chart
========================================

|  idle  |   P3   |   P2   |   P3   |   P2   |   P5   |   P1   |   P2   |   P4   |   P5   |   P1   |   P4   |   P5   |   P1   |   P4   |  idle  |   P1   |   P5   |   P1   |  idle  |
0        3        16       17       21       26       30       31       33       35       40       42       45       50       51      52        54       57       59      62        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      3               1               62              34              21             2
2       TERMINATED      5       8       1               2               33              28              12             11
3       TERMINATED      3       17      1               1               21              18              0              0
4       TERMINATED      31      6       4               2               52              21              7              2
5       TERMINATED      19      16      3               3               59              40              15             7


Average waiting time: 11.00     Max: 21, Min: 0, Variance: 50.80
Average turnaround time: 28.20  Max: 40, Min:18, Variance: 65.76
Average response time: 4.40     Max: 11, Min: 0, Variance: 16.24
Average completion time: 45.40  Max: 62, Min:21, Variance: 250.64
CPU Utilization: 96.61%
Throughput: 8.47 process per 100s
CPU time: 57
IO time: 29
Idle time: 2
Total time: 59
Context switch: 16 times

========================================


Running Aging Priority Non-Preemptive

Gantt chart
========================================

|  idle  |   P3   |   P2   |   P3   |   P2   |   P5   |   P1   |   P2   |   P4   |   P5   |   P4   |   P5   |   P1   |   P4   |   P5   |  idle  |
0        3        16       17       21       26       30       34       36       38       43       46       51       57       58      60        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      4               1               57              29              16             2
2       TERMINATED      5       8       0               2               36              31              15             11
3       TERMINATED      3       17      1               1               21              18              0              0
4       TERMINATED      31      6       3               2               58              27              13             5
5       TERMINATED      19      16      3               3               60              41              16             7


Average waiting time: 12.00     Max: 16, Min: 0, Variance: 37.20
Average turnaround time: 29.20  Max: 41, Min:18, Variance: 54.56
Average response time: 5.00     Max: 11, Min: 0, Variance: 14.80
Average completion time: 46.40  Max: 60, Min:21, Variance: 237.04
CPU Utilization: 100.00%
Throughput: 8.77 process per 100s
CPU time: 57
IO time: 29
Idle time: 0
Total time: 57
Context switch: 13 times

========================================


Running HRRN

Gantt chart
========================================

|  idle  |   P3   |   P2   |   P3   |   P2   |   P3   |   P2   |   P3   |   P2   |   P3   |   P5   |   P3   |   P5   |   P3   |   P5   |   P1   |   P5   |   P4   |   P1   |   P5   |   P1   |   P5   |   P4   |   P5   |   P4   |   P1   |   P5   |   P1   |   P4   |   P1   |   P5   |  idle  |   P5   |  idle  |
0        3        6        7        11       15       16       17       22       24       26       27       28       29       30       32       34       35       37       38       39       40       42       43       44       46       50       51       52       53       54      58        63      65        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      -2300           1               54              26              13             4
2       TERMINATED      5       8       -1375           2               24              19              3              1
3       TERMINATED      3       17      -1529           1               30              27              9              0
4       TERMINATED      31      6       -2333           2               53              22              8              4
5       TERMINATED      19      16      -2312           3               65              46              21             7


Average waiting time: 10.80     Max: 21, Min: 3, Variance: 36.16
Average turnaround time: 28.00  Max: 46, Min:19, Variance: 89.20
Average response time: 3.20     Max:  7, Min: 0, Variance: 6.16
Average completion time: 45.20  Max: 65, Min:24, Variance: 242.16
CPU Utilization: 91.94%
Throughput: 8.06 process per 100s
CPU time: 57
IO time: 29
Idle time: 5
Total time: 62
Context switch: 29 times

========================================


Running HRRN Non-Preemptive

Gantt chart
========================================

|  idle  |   P3   |   P2   |   P3   |   P2   |   P5   |   P1   |   P2   |   P4   |   P5   |   P4   |   P1   |   P4   |   P5   |  idle  |   P5   |  idle  |
0        3        16       17       21       26       30       34       36       38       43       46       52       53      58        63      65        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      -2100           1               52              24              11             2
2       TERMINATED      5       8       -2875           2               36              31              15             11
3       TERMINATED      3       17      0               1               21              18              0              0
4       TERMINATED      31      6       -2333           2               53              22              8              5
5       TERMINATED      19      16      -2312           3               65              46              21             7


Average waiting time: 11.00     Max: 21, Min: 0, Variance: 49.20
Average turnaround time: 28.20  Max: 46, Min:18, Variance: 96.96
Average response time: 5.00     Max: 11, Min: 0, Variance: 14.80
Average completion time: 45.40  Max: 65, Min:21, Variance: 233.84
CPU Utilization: 91.94%
Throughput: 8.06 process per 100s
CPU time: 57
IO time: 29
Idle time: 5
Total time: 62
Context switch: 12 times

========================================


Running CFS

Gantt chart
========================================

|  idle  |   P3   |   P2   |   P3   |   P2   |   P3   |   P5   |   P2   |   P5   |   P1   |   P4   |   P3   |   P1   |   P4   |   P5   |   P3   |   P1   |   P4   |   P5   |   P3   |   P1   |   P5   |   P1   |  idle  |   P5   |  idle  |   P5   |  idle  |
0        3        6        7        11       16       20       24       26       28       32       34       36       39       42       43       45       46       47       48       50       51       52      53        54      59        64      66        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      20              1               53              25              12             0
2       TERMINATED      5       8       8               2               26              21              5              1
3       TERMINATED      3       17      17              1               50              47              29             0
4       TERMINATED      31      6       12              2               47              16              2              1
5       TERMINATED      19      16      32              3               66              47              22             1


Average waiting time: 14.00     Max: 29, Min: 2, Variance: 103.60
Average turnaround time: 31.20  Max: 47, Min:16, Variance: 174.56
Average response time: 0.60     Max:  1, Min: 0, Variance: 0.24
Average completion time: 48.40  Max: 66, Min:26, Variance: 167.44
CPU Utilization: 90.48%
Throughput: 7.94 process per 100s
CPU time: 57
IO time: 29
Idle time: 6
Total time: 63
Context switch: 22 times

========================================


Running CFS Non-Preemptive

Gantt chart
========================================

|  idle  |   P3   |   P2   |   P3   |   P5   |   P2   |   P1   |   P4   |   P2   |   P5   |   P4   |   P1   |   P4   |   P5   |  idle  |   P5   |  idle  |
0        3        16       17       21       25       30       34       36       38       43       46       52       53      58        63      65        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      20              1               52              24              11             2
2       TERMINATED      5       8       8               2               38              33              17             11
3       TERMINATED      3       17      17              1               21              18              0              0
4       TERMINATED      31      6       12              2               53              22              8              3
5       TERMINATED      19      16      32              3               65              46              21             2


Average waiting time: 11.40     Max: 21, Min: 0, Variance: 53.04
Average turnaround time: 28.60  Max: 46, Min:18, Variance: 99.84
Average response time: 3.60     Max: 11, Min: 0, Variance: 14.64
Average completion time: 45.80  Max: 65, Min:21, Variance: 226.96
CPU Utilization: 91.94%
Throughput: 8.06 process per 100s
CPU time: 57
IO time: 29
Idle time: 5
Total time: 62
Context switch: 12 times

========================================



Comparation
========================================
Preemptive SJF has shortest average waiting time: 9.20
19% shorter than average (11.37)

Preemptive SJF has shortest average turnaround time: 26.40
8% shorter than average (28.57)

Preemptive CFS has shortest average response time: 0.60
84% shorter than average (3.85)

Nonpreemptive Priority has shortest max completion time: 60
Aging Nonpreemptive Priority has shortest max completion time: 60
6% shorter than average (63.67)

RR has smallest variance of waiting time: 17.44
66% smaller than average (50.63)

Nonpreemptive Priority has highest cpu utilization: 1.00
Aging Nonpreemptive Priority has highest cpu utilization: 1.00
6% higher than average (0.94)

Nonpreemptive Priority has highest throughput: 0.09
Aging Nonpreemptive Priority has highest throughput: 0.09
6% higher than average (0.08)

Nonpreemptive Priority has smallest idle time: 0
Aging Nonpreemptive Priority has smallest idle time: 0
100% smaller than average (3.67)

Nonpreemptive SJF has smallest context switch: 12
Nonpreemptive HRRN has smallest context switch: 12
Nonpreemptive CFS has smallest context switch: 12
27% smaller than average (16.42)
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
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               45              30              7              0
2       TERMINATED      46      7       8               2               70              24              10             7
3       TERMINATED      19      18      9               2               51              32              11             0
4       TERMINATED      30      9       10              3               64              34              15             7


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
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               45              30              7              0
2       TERMINATED      46      7       8               2               70              24              10             7
3       TERMINATED      19      18      9               2               51              32              11             0
4       TERMINATED      30      9       10              3               64              34              15             0


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
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               43              28              5              0
2       TERMINATED      46      7       8               2               63              17              3              3
3       TERMINATED      19      18      9               2               49              30              9              0
4       TERMINATED      30      9       10              3               70              40              21             21


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
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               43              28              5              0
2       TERMINATED      46      7       8               2               61              15              1              0
3       TERMINATED      19      18      9               2               51              32              11             0
4       TERMINATED      30      9       10              3               73              43              24             23


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
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               43              28              5              0
2       TERMINATED      46      7       8               2               63              17              3              3
3       TERMINATED      19      18      9               2               49              30              9              0
4       TERMINATED      30      9       10              3               70              40              21             21


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
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               47              32              9              0
2       TERMINATED      46      7       8               2               65              19              5              1
3       TERMINATED      19      18      9               2               60              41              20             0
4       TERMINATED      30      9       10              3               62              32              13             2


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


Running Aging Priority

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P1   |   P4   |   P3   |   P4   |   P2   |  idle  |   P2   |   P4   |  idle  |   P2   |   P4   |   P2   |   P4   |  idle  |
0        15      18        19       22       28       37       43       44       50       51      53        55       57      59        62       64       67       68      70        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      8               2               43              28              5              0
2       TERMINATED      46      7       7               2               68              22              8              5
3       TERMINATED      19      18      7               2               50              31              10             0
4       TERMINATED      30      9       6               3               70              40              21             13


Average waiting time: 11.00     Max: 21, Min: 5, Variance: 36.50
Average turnaround time: 30.25  Max: 40, Min:22, Variance: 42.19
Average response time: 4.50     Max: 13, Min: 0, Variance: 28.25
Average completion time: 57.75  Max: 70, Min:43, Variance: 133.19
CPU Utilization: 89.09%
Throughput: 7.27 process per 100s
CPU time: 49
IO time: 28
Idle time: 6
Total time: 55
Context switch: 13 times

========================================


Running Aging Priority Non-Preemptive

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P1   |   P4   |   P3   |   P2   |   P4   |   P2   |  idle  |   P4   |   P2   |   P4   |  idle  |
0        15      18        19       22       28       37       43       45       51       53       55      57        59       62       65      67        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      8               2               43              28              5              0
2       TERMINATED      46      7       7               2               65              19              5              5
3       TERMINATED      19      18      7               2               51              32              11             0
4       TERMINATED      30      9       7               3               67              37              18             13


Average waiting time: 9.75      Max: 18, Min: 5, Variance: 28.69
Average turnaround time: 29.00  Max: 37, Min:19, Variance: 43.50
Average response time: 4.50     Max: 13, Min: 0, Variance: 28.25
Average completion time: 56.50  Max: 67, Min:43, Variance: 98.75
CPU Utilization: 94.23%
Throughput: 7.69 process per 100s
CPU time: 49
IO time: 28
Idle time: 3
Total time: 52
Context switch: 12 times

========================================


Running HRRN

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P1   |   P3   |   P1   |   P3   |   P4   |   P3   |   P1   |   P3   |   P1   |   P4   |   P1   |   P3   |   P1   |   P3   |   P4   |   P2   |   P3   |   P4   |   P2   |   P3   |   P4   |   P2   |   P3   |  idle  |   P2   |  idle  |
0        15      18        19       22       26       27       28       29       30       33       35       38       40       41       42       44       45       46       48       50       52       53       54       55       56       57       59       61      62        66      69        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      -1666           2               48              33              10             0
2       TERMINATED      46      7       -2285           2               69              23              9              6
3       TERMINATED      19      18      -2222           2               62              43              22             0
4       TERMINATED      30      9       -2111           3               59              29              10             3


Average waiting time: 12.75     Max: 22, Min: 9, Variance: 28.69
Average turnaround time: 32.00  Max: 43, Min:23, Variance: 53.00
Average response time: 2.25     Max:  6, Min: 0, Variance: 6.19
Average completion time: 59.50  Max: 69, Min:48, Variance: 57.25
CPU Utilization: 90.74%
Throughput: 7.41 process per 100s
CPU time: 49
IO time: 28
Idle time: 5
Total time: 54
Context switch: 27 times

========================================


Running HRRN Non-Preemptive

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P4   |   P1   |   P4   |   P3   |   P4   |   P2   |   P4   |   P2   |  idle  |   P2   |  idle  |
0        15      18        19       22       28       37       39       45       47       53       56       58       60      62        67      70        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      -1466           2               45              30              7              0
2       TERMINATED      46      7       -2428           2               70              24              10             10
3       TERMINATED      19      18      -1722           2               53              34              13             0
4       TERMINATED      30      9       -2222           3               60              30              11             7


Average waiting time: 10.25     Max: 13, Min: 7, Variance: 4.69
Average turnaround time: 29.50  Max: 34, Min:24, Variance: 12.75
Average response time: 4.25     Max: 10, Min: 0, Variance: 19.19
Average completion time: 57.00  Max: 70, Min:45, Variance: 84.50
CPU Utilization: 89.09%
Throughput: 7.27 process per 100s
CPU time: 49
IO time: 28
Idle time: 6
Total time: 55
Context switch: 11 times

========================================


Running CFS

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P1   |   P4   |   P3   |   P1   |   P3   |   P4   |   P1   |   P4   |   P2   |   P4   |   P3   |   P2   |   P4   |   P1   |   P3   |   P2   |   P3   |  idle  |
0        15      18        19       22       25       29       31       33       35       36       39       41       45       47       49       50       52       54       56       58       60       63      65        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      30              2               58              43              20             0
2       TERMINATED      46      7       14              2               63              17              3              1
3       TERMINATED      19      18      36              2               65              46              25             0
4       TERMINATED      30      9       18              3               56              26              7              1


Average waiting time: 13.75     Max: 25, Min: 3, Variance: 81.69
Average turnaround time: 33.00  Max: 46, Min:17, Variance: 143.50
Average response time: 0.50     Max:  1, Min: 0, Variance: 0.25
Average completion time: 60.50  Max: 65, Min:56, Variance: 13.25
CPU Utilization: 98.00%
Throughput: 8.00 process per 100s
CPU time: 49
IO time: 28
Idle time: 1
Total time: 50
Context switch: 20 times

========================================


Running CFS Non-Preemptive

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P4   |   P1   |   P4   |   P2   |   P3   |   P2   |   P4   |  idle  |   P4   |   P2   |  idle  |
0        15      18        19       22       28       37       39       45       47       49       55       57      60        61       63      66        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      30              2               45              30              7              0
2       TERMINATED      46      7       14              2               66              20              6              1
3       TERMINATED      19      18      36              2               55              36              15             0
4       TERMINATED      30      9       18              3               63              33              14             7


Average waiting time: 10.50     Max: 15, Min: 6, Variance: 16.25
Average turnaround time: 29.75  Max: 36, Min:20, Variance: 36.19
Average response time: 2.00     Max:  7, Min: 0, Variance: 8.50
Average completion time: 57.25  Max: 66, Min:45, Variance: 66.19
CPU Utilization: 96.08%
Throughput: 7.84 process per 100s
CPU time: 49
IO time: 28
Idle time: 2
Total time: 51
Context switch: 11 times

========================================



Comparation
========================================
Nonpreemptive SJF has shortest average waiting time: 9.50
Nonpreemptive Priority has shortest average waiting time: 9.50
13% shorter than average (10.88)

Nonpreemptive SJF has shortest average turnaround time: 28.75
Nonpreemptive Priority has shortest average turnaround time: 28.75
5% shorter than average (30.12)

Preemptive CFS has shortest average response time: 0.50
86% shorter than average (3.48)

RR has shortest max completion time: 65
Preemptive CFS has shortest max completion time: 65
5% shorter than average (68.75)

Nonpreemptive HRRN has smallest variance of waiting time: 4.69
87% smaller than average (34.73)

RR has highest cpu utilization: 0.98
Preemptive CFS has highest cpu utilization: 0.98
7% higher than average (0.91)

RR has highest throughput: 0.08
Preemptive CFS has highest throughput: 0.08
7% higher than average (0.07)

RR has smallest idle time: 1
Preemptive CFS has smallest idle time: 1
79% smaller than average (4.75)

Nonpreemptive SJF has smallest context switch: 11
Preemptive Priority has smallest context switch: 11
Nonpreemptive Priority has smallest context switch: 11
Nonpreemptive HRRN has smallest context switch: 11
Nonpreemptive CFS has smallest context switch: 11
24% smaller than average (14.50)
```