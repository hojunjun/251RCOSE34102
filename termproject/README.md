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



Comparation
========================================
Preemptive SJF has shortest average waiting time: 3.67
34% shorter than average (5.57)

Preemptive SJF has shortest average turnaround time: 9.67
16% shorter than average (11.57)

Preemptive HRRN has shortest average response time: 0.67
82% shorter than average (3.80)

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
All algorithms have same max completion time

RR has smallest variance of waiting time: 0.22
99% smaller than average (16.16)

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
All algorithms have same idle time

FCFS has smallest context switch: 2
Nonpreemptive SJF has smallest context switch: 2
Nonpreemptive Priority has smallest context switch: 2
Aging Nonpreemptive Priority has smallest context switch: 2
Nonpreemptive HRRN has smallest context switch: 2
41% smaller than average (3.40)
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
IO 0 Burst Time: 2
========================================

========================================
Process 2
Arrival Time: 38
Burst Time: 6
Priority: 8
IO Count: 2
IO 0 Request Time: 2
IO 0 Burst Time: 1
IO 1 Request Time: 5
IO 1 Burst Time: 4
========================================

========================================
Process 3
Arrival Time: 25
Burst Time: 17
Priority: 9
IO Count: 1
IO 0 Request Time: 1
IO 0 Burst Time: 4
========================================

========================================
Process 4
Arrival Time: 11
Burst Time: 16
Priority: 5
IO Count: 3
IO 0 Request Time: 2
IO 0 Burst Time: 4
IO 1 Request Time: 6
IO 1 Burst Time: 5
IO 2 Request Time: 11
IO 2 Burst Time: 1
========================================

========================================
Process 5
Arrival Time: 23
Burst Time: 17
Priority: 6
IO Count: 3
IO 0 Request Time: 4
IO 0 Burst Time: 2
IO 1 Request Time: 9
IO 1 Burst Time: 5
IO 2 Request Time: 10
IO 2 Burst Time: 2
========================================



Running FCFS

Gantt chart
========================================

|  idle  |   P4   |  idle  |   P4   |  idle  |   P5   |   P3   |   P4   |   P1   |   P5   |   P3   |   P4   |   P2   |   P1   |   P5   |   P2   |   P5   |   P2   |  idle  |
0        11      13        17      21        23       27       28       33       37       42       58       63       65       71       72       75       82      83        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      7               1               71              43              31             5
2       TERMINATED      38      6       8               2               83              45              34             25
3       TERMINATED      25      17      9               1               58              33              12             2
4       TERMINATED      11      16      5               3               63              52              26             0
5       TERMINATED      23      17      6               3               82              59              33             0


Average waiting time: 27.20     Max: 34, Min:12, Variance: 65.36
Average turnaround time: 46.40  Max: 59, Min:33, Variance: 76.64
Average response time: 6.40     Max: 25, Min: 0, Variance: 89.84
Average completion time: 71.40  Max: 83, Min:58, Variance: 99.44
CPU Utilization: 91.67%
Throughput: 6.94 process per 100s
CPU time: 66
IO time: 30
Idle time: 6
Total time: 72
Context switch: 13 times

========================================


Running SJF

Gantt chart
========================================

|  idle  |   P4   |  idle  |   P4   |  idle  |   P5   |   P4   |   P1   |   P4   |   P2   |   P1   |   P2   |   P5   |   P2   |   P3   |  idle  |   P5   |   P3   |   P5   |  idle  |
0        11      13        17      21        23       27       32       36       41       43       49       52       57       58      59        62       63       79      86        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      7               1               49              21              9              4
2       TERMINATED      38      6       8               2               58              20              9              3
3       TERMINATED      25      17      9               1               79              54              33             33
4       TERMINATED      11      16      5               3               41              30              4              0
5       TERMINATED      23      17      6               3               86              63              37             0


Average waiting time: 18.40     Max: 37, Min: 4, Variance: 188.64
Average turnaround time: 37.60  Max: 63, Min:20, Variance: 311.44
Average response time: 8.00     Max: 33, Min: 0, Variance: 158.80
Average completion time: 62.60  Max: 86, Min:41, Variance: 297.84
CPU Utilization: 88.00%
Throughput: 6.67 process per 100s
CPU time: 66
IO time: 30
Idle time: 9
Total time: 75
Context switch: 13 times

========================================


Running SJF Non-Preemptive

Gantt chart
========================================

|  idle  |   P4   |  idle  |   P4   |  idle  |   P5   |   P4   |   P1   |   P4   |   P2   |   P1   |   P2   |   P5   |   P2   |   P3   |  idle  |   P5   |   P3   |   P5   |  idle  |
0        11      13        17      21        23       27       32       36       41       43       49       52       57       58      59        62       63       79      86        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      7               1               49              21              9              4
2       TERMINATED      38      6       8               2               58              20              9              3
3       TERMINATED      25      17      9               1               79              54              33             33
4       TERMINATED      11      16      5               3               41              30              4              0
5       TERMINATED      23      17      6               3               86              63              37             0


Average waiting time: 18.40     Max: 37, Min: 4, Variance: 188.64
Average turnaround time: 37.60  Max: 63, Min:20, Variance: 311.44
Average response time: 8.00     Max: 33, Min: 0, Variance: 158.80
Average completion time: 62.60  Max: 86, Min:41, Variance: 297.84
CPU Utilization: 88.00%
Throughput: 6.67 process per 100s
CPU time: 66
IO time: 30
Idle time: 9
Total time: 75
Context switch: 13 times

========================================


Running Priority

Gantt chart
========================================

|  idle  |   P4   |  idle  |   P4   |  idle  |   P5   |   P4   |   P5   |   P4   |   P5   |   P1   |   P5   |   P1   |   P2   |   P3   |   P2   |  idle  |   P3   |   P2   |  idle  |
0        11      13        17      21        23       27       32       37       42       43       47       54       60       62       63      66        67       83      84        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      7               1               60              32              20             15
2       TERMINATED      38      6       8               2               84              46              35             22
3       TERMINATED      25      17      9               1               83              58              37             37
4       TERMINATED      11      16      5               3               42              31              5              0
5       TERMINATED      23      17      6               3               54              31              5              0


Average waiting time: 20.40     Max: 37, Min: 5, Variance: 192.64
Average turnaround time: 39.60  Max: 58, Min:31, Variance: 117.04
Average response time: 14.80    Max: 37, Min: 0, Variance: 196.56
Average completion time: 64.60  Max: 84, Min:42, Variance: 271.84
CPU Utilization: 90.41%
Throughput: 6.85 process per 100s
CPU time: 66
IO time: 30
Idle time: 7
Total time: 73
Context switch: 13 times

========================================


Running Priority Non-Preemptive

Gantt chart
========================================

|  idle  |   P4   |  idle  |   P4   |  idle  |   P5   |   P4   |   P5   |   P4   |   P5   |   P1   |   P5   |   P1   |   P2   |   P3   |   P2   |  idle  |   P3   |   P2   |  idle  |
0        11      13        17      21        23       27       32       37       42       43       47       54       60       62       63      66        67       83      84        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      7               1               60              32              20             15
2       TERMINATED      38      6       8               2               84              46              35             22
3       TERMINATED      25      17      9               1               83              58              37             37
4       TERMINATED      11      16      5               3               42              31              5              0
5       TERMINATED      23      17      6               3               54              31              5              0


Average waiting time: 20.40     Max: 37, Min: 5, Variance: 192.64
Average turnaround time: 39.60  Max: 58, Min:31, Variance: 117.04
Average response time: 14.80    Max: 37, Min: 0, Variance: 196.56
Average completion time: 64.60  Max: 84, Min:42, Variance: 271.84
CPU Utilization: 90.41%
Throughput: 6.85 process per 100s
CPU time: 66
IO time: 30
Idle time: 7
Total time: 73
Context switch: 13 times

========================================


Running RR

Gantt chart
========================================

|  idle  |   P4   |  idle  |   P4   |   P4   |  idle  |   P5   |   P5   |   P3   |   P4   |   P1   |   P5   |   P4   |   P1   |   P3   |   P5   |   P4   |   P2   |   P3   |   P1   |   P5   |   P4   |   P2   |   P3   |   P1   |   P4   |   P2   |   P5   |   P3   |   P1   |   P4   |   P3   |   P5   |   P2   |   P3   |   P5   |   P3   |   P5   |   P3   |   P5   |  idle  |
0        11      13        17       19      21        23       25       27       28       30       32       34       36       38       40       42       43       45       47       49       50       52       54       56       58       60       61       62       64       66       67       69       71       72       74       76       78       80       82      83        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      7               1               66              38              26             2
2       TERMINATED      38      6       8               2               72              34              23             5
3       TERMINATED      25      17      9               1               82              57              36             2
4       TERMINATED      11      16      5               3               67              56              30             0
5       TERMINATED      23      17      6               3               83              60              34             0


Average waiting time: 29.80     Max: 36, Min:23, Variance: 23.36
Average turnaround time: 49.00  Max: 60, Min:34, Variance: 116.00
Average response time: 1.80     Max:  5, Min: 0, Variance: 3.36
Average completion time: 74.00  Max: 83, Min:66, Variance: 52.40
CPU Utilization: 91.67%
Throughput: 6.94 process per 100s
CPU time: 66
IO time: 30
Idle time: 6
Total time: 72
Context switch: 33 times

========================================


Running Aging Priority

Gantt chart
========================================

|  idle  |   P4   |  idle  |   P4   |  idle  |   P5   |   P4   |   P5   |   P4   |   P1   |   P5   |   P1   |   P3   |   P2   |   P1   |   P5   |   P3   |   P5   |   P1   |   P3   |   P5   |   P2   |   P3   |   P2   |   P3   |  idle  |   P2   |  idle  |
0        11      13        17      21        23       27       32       34       39       41       44       46       47       49       54       55       58       64       65       68       69       71       78       79      82        83      84        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      2               1               65              37              25             11
2       TERMINATED      38      6       1               2               84              46              35             9
3       TERMINATED      25      17      2               1               82              57              36             21
4       TERMINATED      11      16      5               3               39              28              2              0
5       TERMINATED      23      17      2               3               69              46              20             0


Average waiting time: 23.60     Max: 36, Min: 2, Variance: 153.04
Average turnaround time: 42.80  Max: 57, Min:28, Variance: 94.96
Average response time: 8.20     Max: 21, Min: 0, Variance: 61.36
Average completion time: 67.80  Max: 84, Min:39, Variance: 260.56
CPU Utilization: 90.41%
Throughput: 6.85 process per 100s
CPU time: 66
IO time: 30
Idle time: 7
Total time: 73
Context switch: 21 times

========================================


Running Aging Priority Non-Preemptive

Gantt chart
========================================

|  idle  |   P4   |  idle  |   P4   |  idle  |   P5   |   P4   |   P5   |   P4   |   P1   |   P3   |   P5   |   P1   |   P5   |   P3   |   P2   |  idle  |   P2   |  idle  |   P2   |  idle  |
0        11      13        17      21        23       27       32       37       42       46       47       48       54       61       77      79        80      83        87      88        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      5               1               54              26              14             14
2       TERMINATED      38      6       1               2               88              50              39             39
3       TERMINATED      25      17      3               1               77              52              31             21
4       TERMINATED      11      16      4               3               42              31              5              0
5       TERMINATED      23      17      4               3               61              38              12             0


Average waiting time: 20.20     Max: 39, Min: 5, Variance: 161.36
Average turnaround time: 39.40  Max: 52, Min:26, Variance: 104.64
Average response time: 14.80    Max: 39, Min: 0, Variance: 212.56
Average completion time: 64.40  Max: 88, Min:42, Variance: 267.44
CPU Utilization: 85.71%
Throughput: 6.49 process per 100s
CPU time: 66
IO time: 30
Idle time: 11
Total time: 77
Context switch: 11 times

========================================


Running HRRN

Gantt chart
========================================

|  idle  |   P4   |  idle  |   P4   |  idle  |   P5   |   P3   |   P4   |   P5   |   P4   |   P1   |   P4   |   P1   |   P4   |   P1   |   P5   |   P4   |   P3   |   P5   |   P1   |   P2   |   P3   |   P2   |   P1   |   P2   |   P1   |   P2   |   P1   |   P4   |   P5   |   P4   |   P3   |   P5   |   P2   |   P4   |   P3   |   P5   |   P4   |   P3   |   P4   |   P3   |   P5   |   P3   |   P5   |   P3   |   P5   |   P3   |   P5   |  idle  |
0        11      13        17      21        23       26       27       28       29       30       32       33       34       35       36       37       38       39       40       42       43       44       45       47       49       50       51       52       53       54       55       56       57       58       59       60       61       62       63       64       69       70       73       75       77       79       80      83        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      -2200           1               52              24              12             2
2       TERMINATED      38      6       -2500           2               58              20              9              4
3       TERMINATED      25      17      -3000           1               80              55              34             1
4       TERMINATED      11      16      -2687           3               64              53              27             0
5       TERMINATED      23      17      -3000           3               83              60              34             0


Average waiting time: 23.20     Max: 34, Min: 9, Variance: 114.96
Average turnaround time: 42.40  Max: 60, Min:20, Variance: 284.24
Average response time: 1.40     Max:  4, Min: 0, Variance: 2.24
Average completion time: 67.40  Max: 83, Min:52, Variance: 147.84
CPU Utilization: 91.67%
Throughput: 6.94 process per 100s
CPU time: 66
IO time: 30
Idle time: 6
Total time: 72
Context switch: 43 times

========================================


Running HRRN Non-Preemptive

Gantt chart
========================================

|  idle  |   P4   |  idle  |   P4   |  idle  |   P5   |   P3   |   P4   |   P1   |   P5   |   P1   |   P2   |   P3   |   P2   |   P4   |   P2   |   P5   |  idle  |   P5   |  idle  |
0        11      13        17      21        23       27       28       33       37       42       48       50       66       69       74       75      76        78      85        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      28      10      -1800           1               48              20              8              5
2       TERMINATED      38      6       -5333           2               75              37              26             10
3       TERMINATED      25      17      -2176           1               66              41              20             2
4       TERMINATED      11      16      -3312           3               74              63              37             0
5       TERMINATED      23      17      -3117           3               85              62              36             0


Average waiting time: 25.40     Max: 37, Min: 8, Variance: 115.84
Average turnaround time: 44.60  Max: 63, Min:20, Variance: 263.44
Average response time: 3.40     Max: 10, Min: 0, Variance: 14.24
Average completion time: 69.60  Max: 85, Min:48, Variance: 153.04
CPU Utilization: 89.19%
Throughput: 6.76 process per 100s
CPU time: 66
IO time: 30
Idle time: 8
Total time: 74
Context switch: 12 times

========================================



Comparation
========================================
Preemptive SJF has shortest average waiting time: 18.40
Nonpreemptive SJF has shortest average waiting time: 18.40
19% shorter than average (22.70)

Preemptive SJF has shortest average turnaround time: 37.60
Nonpreemptive SJF has shortest average turnaround time: 37.60
10% shorter than average (41.90)

Preemptive HRRN has shortest average response time: 1.40
83% shorter than average (8.16)

FCFS has shortest max completion time: 83
RR has shortest max completion time: 83
Preemptive HRRN has shortest max completion time: 83
2% shorter than average (84.60)

RR has smallest variance of waiting time: 23.36
83% smaller than average (139.65)

FCFS has highest cpu utilization: 0.92
RR has highest cpu utilization: 0.92
Preemptive HRRN has highest cpu utilization: 0.92
2% higher than average (0.90)

FCFS has highest throughput: 0.07
RR has highest throughput: 0.07
Preemptive HRRN has highest throughput: 0.07
2% higher than average (0.07)

FCFS has smallest idle time: 6
RR has smallest idle time: 6
Preemptive HRRN has smallest idle time: 6
21% smaller than average (7.60)

Aging Nonpreemptive Priority has smallest context switch: 11
41% smaller than average (18.50)
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



Comparation
========================================
Nonpreemptive SJF has shortest average waiting time: 9.50
Nonpreemptive Priority has shortest average waiting time: 9.50
11% shorter than average (10.62)

Nonpreemptive SJF has shortest average turnaround time: 28.75
Nonpreemptive Priority has shortest average turnaround time: 28.75
4% shorter than average (29.88)

RR has shortest average response time: 0.75
81% shorter than average (3.92)

RR has shortest max completion time: 65
6% shorter than average (69.40)

Nonpreemptive HRRN has smallest variance of waiting time: 4.69
85% smaller than average (31.88)

RR has highest cpu utilization: 0.98
9% higher than average (0.90)

RR has highest throughput: 0.08
9% higher than average (0.07)

RR has smallest idle time: 1
81% smaller than average (5.40)

Nonpreemptive SJF has smallest context switch: 11
Preemptive Priority has smallest context switch: 11
Nonpreemptive Priority has smallest context switch: 11
Nonpreemptive HRRN has smallest context switch: 11
23% smaller than average (14.30)