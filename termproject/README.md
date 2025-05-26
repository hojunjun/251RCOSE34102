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

|   P1   |   P3   |   P2   |   P1   |  idle  |
0        4        7        12      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      1               0               18              18              8              0
2       TERMINATED      2       5       2               0               12              10              5              5
3       TERMINATED      4       3       1               0               7               3               0              0


Average waiting time: 4.33      Max:  8, Min: 0, Variance: 10.89
Average turnaround time: 10.33  Max: 18, Min: 3, Variance: 37.56
Average response time: 1.67     Max:  5, Min: 0, Variance: 5.56
Average completion time: 12.33  Max: 18, Min: 7, Variance: 20.22
CPU Utilization: 100.00%
Throughput: 16.67 process per 100s
CPU time: 18
IO time: 0
Idle time: 0
Total time: 18
Context switch: 3 times

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



Comparation
========================================
Preemptive SJF has shortest average waiting time: 3.67
34% shorter than average (5.54)

Preemptive SJF has shortest average turnaround time: 9.67
16% shorter than average (11.54)

Preemptive SJF has shortest average response time: 1.00
75% shorter than average (3.96)

FCFS has shortest max completion time: 18
Preemptive SJF has shortest max completion time: 18
Nonpreemptive SJF has shortest max completion time: 18
Preemptive Priority has shortest max completion time: 18
Nonpreemptive Priority has shortest max completion time: 18
RR has shortest max completion time: 18
Aging Preemptive Priority has shortest max completion time: 18
Aging Nonpreemptive Priority has shortest max completion time: 18
All algorithms have same max completion time

RR has smallest variance of waiting time: 0.22
99% smaller than average (15.72)

FCFS has highest cpu utilization: 1.00
Preemptive SJF has highest cpu utilization: 1.00
Nonpreemptive SJF has highest cpu utilization: 1.00
Preemptive Priority has highest cpu utilization: 1.00
Nonpreemptive Priority has highest cpu utilization: 1.00
RR has highest cpu utilization: 1.00
Aging Preemptive Priority has highest cpu utilization: 1.00
Aging Nonpreemptive Priority has highest cpu utilization: 1.00
All algorithms have same cpu utilization

FCFS has highest throughput: 0.17
Preemptive SJF has highest throughput: 0.17
Nonpreemptive SJF has highest throughput: 0.17
Preemptive Priority has highest throughput: 0.17
Nonpreemptive Priority has highest throughput: 0.17
RR has highest throughput: 0.17
Aging Preemptive Priority has highest throughput: 0.17
Aging Nonpreemptive Priority has highest throughput: 0.17
All algorithms have same throughput

FCFS has smallest idle time: 0
Preemptive SJF has smallest idle time: 0
Nonpreemptive SJF has smallest idle time: 0
Preemptive Priority has smallest idle time: 0
Nonpreemptive Priority has smallest idle time: 0
RR has smallest idle time: 0
Aging Preemptive Priority has smallest idle time: 0
Aging Nonpreemptive Priority has smallest idle time: 0
All algorithms have same idle time

FCFS has smallest context switch: 2
Nonpreemptive SJF has smallest context switch: 2
Nonpreemptive Priority has smallest context switch: 2
Aging Nonpreemptive Priority has smallest context switch: 2
36% smaller than average (3.12)
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
Arrival Time: 37
Burst Time: 14
Priority: 3
IO Count: 3
IO 0 Request Time: 3
IO 0 Burst Time: 3
IO 1 Request Time: 4
IO 1 Burst Time: 2
IO 2 Request Time: 9
IO 2 Burst Time: 2
========================================

========================================
Process 2
Arrival Time: 9
Burst Time: 7
Priority: 3
IO Count: 3
IO 0 Request Time: 1
IO 0 Burst Time: 4
IO 1 Request Time: 3
IO 1 Burst Time: 5
IO 2 Request Time: 5
IO 2 Burst Time: 1
========================================

========================================
Process 3
Arrival Time: 18
Burst Time: 10
Priority: 5
IO Count: 3
IO 0 Request Time: 2
IO 0 Burst Time: 4
IO 1 Request Time: 3
IO 1 Burst Time: 5
IO 2 Request Time: 8
IO 2 Burst Time: 3
========================================

========================================
Process 4
Arrival Time: 46
Burst Time: 13
Priority: 10
IO Count: 1
IO 0 Request Time: 7
IO 0 Burst Time: 2
========================================

========================================
Process 5
Arrival Time: 27
Burst Time: 8
Priority: 1
IO Count: 1
IO 0 Request Time: 3
IO 0 Burst Time: 5
========================================



Running FCFS

Gantt chart
========================================

|  idle  |   P2   |  idle  |   P2   |  idle  |   P3   |  idle  |   P2   |  idle  |   P3   |   P2   |   P5   |   P3   |   P5   |   P1   |   P3   |  idle  |   P4   |   P1   |  idle  |   P4   |   P1   |  idle  |   P1   |  idle  |
0        9       10        14      16        18      20        21      23        24       25       27       30       35       40       43      45        46       53      54        55       61      66        68      73        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      37      14      3               3               73              36              15             3
2       TERMINATED      9       7       3               3               27              18              1              0
3       TERMINATED      18      10      5               3               45              27              5              0
4       TERMINATED      46      13      10              1               61              15              0              0
5       TERMINATED      27      8       1               1               40              13              0              0


Average waiting time: 4.20      Max: 15, Min: 0, Variance: 32.56
Average turnaround time: 21.80  Max: 36, Min:13, Variance: 73.36
Average response time: 0.60     Max:  3, Min: 0, Variance: 1.44
Average completion time: 49.20  Max: 73, Min:27, Variance: 260.16
CPU Utilization: 81.25%
Throughput: 7.81 process per 100s
CPU time: 52
IO time: 36
Idle time: 12
Total time: 64
Context switch: 13 times

========================================


Running SJF

Gantt chart
========================================

|  idle  |   P2   |  idle  |   P2   |  idle  |   P3   |  idle  |   P2   |  idle  |   P2   |   P3   |   P5   |  idle  |   P3   |   P5   |   P3   |   P1   |   P4   |   P1   |  idle  |   P4   |   P1   |  idle  |   P1   |  idle  |
0        9       10        14      16        18      20        21      23        24       26       27      30        32       37       42       44       47       54      55        56       62      67        69      74        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      37      14      3               3               74              37              16             7
2       TERMINATED      9       7       3               3               26              17              0              0
3       TERMINATED      18      10      5               3               44              26              4              0
4       TERMINATED      46      13      10              1               62              16              1              1
5       TERMINATED      27      8       1               1               42              15              2              0


Average waiting time: 4.60      Max: 16, Min: 0, Variance: 34.24
Average turnaround time: 22.20  Max: 37, Min:15, Variance: 70.16
Average response time: 1.60     Max:  7, Min: 0, Variance: 7.44
Average completion time: 49.60  Max: 74, Min:26, Variance: 279.04
CPU Utilization: 80.00%
Throughput: 7.69 process per 100s
CPU time: 52
IO time: 36
Idle time: 13
Total time: 65
Context switch: 12 times

========================================


Running SJF Non-Preemptive

Gantt chart
========================================

|  idle  |   P2   |  idle  |   P2   |  idle  |   P3   |  idle  |   P2   |  idle  |   P2   |   P3   |   P5   |  idle  |   P3   |   P5   |   P3   |   P1   |   P4   |   P1   |  idle  |   P4   |   P1   |  idle  |   P1   |  idle  |
0        9       10        14      16        18      20        21      23        24       26       27      30        32       37       42       44       47       54      55        56       62      67        69      74        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      37      14      3               3               74              37              16             7
2       TERMINATED      9       7       3               3               26              17              0              0
3       TERMINATED      18      10      5               3               44              26              4              0
4       TERMINATED      46      13      10              1               62              16              1              1
5       TERMINATED      27      8       1               1               42              15              2              0


Average waiting time: 4.60      Max: 16, Min: 0, Variance: 34.24
Average turnaround time: 22.20  Max: 37, Min:15, Variance: 70.16
Average response time: 1.60     Max:  7, Min: 0, Variance: 7.44
Average completion time: 49.60  Max: 74, Min:26, Variance: 279.04
CPU Utilization: 80.00%
Throughput: 7.69 process per 100s
CPU time: 52
IO time: 36
Idle time: 13
Total time: 65
Context switch: 12 times

========================================


Running Priority

Gantt chart
========================================

|  idle  |   P2   |  idle  |   P2   |  idle  |   P3   |  idle  |   P2   |  idle  |   P2   |   P3   |   P5   |  idle  |   P3   |   P5   |   P1   |   P3   |   P4   |   P1   |  idle  |   P4   |   P1   |  idle  |   P1   |  idle  |
0        9       10        14      16        18      20        21      23        24       26       27      30        32       37       42       45       47       54      55        56       62      67        69      74        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      37      14      3               3               74              37              16             5
2       TERMINATED      9       7       3               3               26              17              0              0
3       TERMINATED      18      10      5               3               47              29              7              0
4       TERMINATED      46      13      10              1               62              16              1              1
5       TERMINATED      27      8       1               1               42              15              2              0


Average waiting time: 5.20      Max: 16, Min: 0, Variance: 34.96
Average turnaround time: 22.80  Max: 37, Min:15, Variance: 76.16
Average response time: 1.20     Max:  5, Min: 0, Variance: 3.76
Average completion time: 50.20  Max: 74, Min:26, Variance: 273.76
CPU Utilization: 80.00%
Throughput: 7.69 process per 100s
CPU time: 52
IO time: 36
Idle time: 13
Total time: 65
Context switch: 12 times

========================================


Running Priority Non-Preemptive

Gantt chart
========================================

|  idle  |   P2   |  idle  |   P2   |  idle  |   P3   |  idle  |   P2   |  idle  |   P2   |   P3   |   P5   |  idle  |   P3   |   P5   |   P1   |   P3   |   P4   |   P1   |  idle  |   P4   |   P1   |  idle  |   P1   |  idle  |
0        9       10        14      16        18      20        21      23        24       26       27      30        32       37       42       45       47       54      55        56       62      67        69      74        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      37      14      3               3               74              37              16             5
2       TERMINATED      9       7       3               3               26              17              0              0
3       TERMINATED      18      10      5               3               47              29              7              0
4       TERMINATED      46      13      10              1               62              16              1              1
5       TERMINATED      27      8       1               1               42              15              2              0


Average waiting time: 5.20      Max: 16, Min: 0, Variance: 34.96
Average turnaround time: 22.80  Max: 37, Min:15, Variance: 76.16
Average response time: 1.20     Max:  5, Min: 0, Variance: 3.76
Average completion time: 50.20  Max: 74, Min:26, Variance: 273.76
CPU Utilization: 80.00%
Throughput: 7.69 process per 100s
CPU time: 52
IO time: 36
Idle time: 13
Total time: 65
Context switch: 12 times

========================================


Running RR

Gantt chart
========================================

|  idle  |   P2   |  idle  |   P2   |  idle  |   P3   |  idle  |   P2   |  idle  |   P3   |   P2   |   P5   |   P5   |   P3   |   P3   |   P3   |   P5   |   P5   |   P1   |   P3   |   P5   |   P1   |  idle  |   P4   |   P4   |   P1   |   P4   |   P4   |   P1   |   P1   |   P4   |   P1   |   P4   |   P4   |   P1   |   P1   |   P1   |  idle  |
0        9       10        14      16        18      20        21      23        24       25       27       29       30       32       34       35       37       39       41       43       44      45        46       48       50       51       53       54       56       58       60       61       63       65       67       69      70        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      37      14      3               3               70              33              12             2
2       TERMINATED      9       7       3               3               27              18              1              0
3       TERMINATED      18      10      5               3               43              25              3              0
4       TERMINATED      46      13      10              1               65              19              4              0
5       TERMINATED      27      8       1               1               44              17              4              0


Average waiting time: 4.80      Max: 12, Min: 1, Variance: 14.16
Average turnaround time: 22.40  Max: 33, Min:17, Variance: 35.84
Average response time: 0.40     Max:  2, Min: 0, Variance: 0.64
Average completion time: 49.80  Max: 70, Min:27, Variance: 247.76
CPU Utilization: 85.25%
Throughput: 8.20 process per 100s
CPU time: 52
IO time: 36
Idle time: 9
Total time: 61
Context switch: 19 times

========================================


Running Aging Priority

Gantt chart
========================================

|  idle  |   P2   |  idle  |   P2   |  idle  |   P3   |  idle  |   P2   |  idle  |   P2   |   P3   |   P5   |  idle  |   P3   |   P5   |   P1   |   P3   |   P4   |   P1   |  idle  |   P4   |   P1   |  idle  |   P1   |  idle  |
0        9       10        14      16        18      20        21      23        24       26       27      30        32       37       42       45       47       54      55        56       62      67        69      74        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      37      14      0               3               74              37              16             5
2       TERMINATED      9       7       3               3               26              17              0              0
3       TERMINATED      18      10      4               3               47              29              7              0
4       TERMINATED      46      13      10              1               62              16              1              1
5       TERMINATED      27      8       1               1               42              15              2              0


Average waiting time: 5.20      Max: 16, Min: 0, Variance: 34.96
Average turnaround time: 22.80  Max: 37, Min:15, Variance: 76.16
Average response time: 1.20     Max:  5, Min: 0, Variance: 3.76
Average completion time: 50.20  Max: 74, Min:26, Variance: 273.76
CPU Utilization: 80.00%
Throughput: 7.69 process per 100s
CPU time: 52
IO time: 36
Idle time: 13
Total time: 65
Context switch: 12 times

========================================


Running Aging Priority Non-Preemptive

Gantt chart
========================================

|  idle  |   P2   |  idle  |   P2   |  idle  |   P3   |  idle  |   P2   |  idle  |   P2   |   P3   |   P5   |  idle  |   P3   |   P5   |   P1   |   P3   |   P4   |   P1   |  idle  |   P4   |   P1   |  idle  |   P1   |  idle  |
0        9       10        14      16        18      20        21      23        24       26       27      30        32       37       42       45       47       54      55        56       62      67        69      74        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      37      14      0               3               74              37              16             5
2       TERMINATED      9       7       3               3               26              17              0              0
3       TERMINATED      18      10      4               3               47              29              7              0
4       TERMINATED      46      13      10              1               62              16              1              1
5       TERMINATED      27      8       1               1               42              15              2              0


Average waiting time: 5.20      Max: 16, Min: 0, Variance: 34.96
Average turnaround time: 22.80  Max: 37, Min:15, Variance: 76.16
Average response time: 1.20     Max:  5, Min: 0, Variance: 3.76
Average completion time: 50.20  Max: 74, Min:26, Variance: 273.76
CPU Utilization: 80.00%
Throughput: 7.69 process per 100s
CPU time: 52
IO time: 36
Idle time: 13
Total time: 65
Context switch: 12 times

========================================



Comparation
========================================
FCFS has shortest average waiting time: 4.20
14% shorter than average (4.88)

FCFS has shortest average turnaround time: 21.80
3% shorter than average (22.48)

RR has shortest average response time: 0.40
64% shorter than average (1.12)

RR has shortest max completion time: 70
5% shorter than average (73.38)

RR has smallest variance of waiting time: 14.16
56% smaller than average (31.88)

RR has highest cpu utilization: 0.85
5% higher than average (0.81)

RR has highest throughput: 0.08
5% higher than average (0.08)

RR has smallest idle time: 9
27% smaller than average (12.38)

Preemptive SJF has smallest context switch: 12
Nonpreemptive SJF has smallest context switch: 12
Preemptive Priority has smallest context switch: 12
Nonpreemptive Priority has smallest context switch: 12
Aging Preemptive Priority has smallest context switch: 12
Aging Nonpreemptive Priority has smallest context switch: 12
8% smaller than average (13.00)


 ~/d/o/251RCOSE34102/termproject  on main !5  ./main                                                ✔  at 11:04:45
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
Arrival Time: 6
Burst Time: 11
Priority: 9
IO Count: 1
IO 0 Request Time: 1
IO 0 Burst Time: 3
========================================

========================================
Process 2
Arrival Time: 32
Burst Time: 16
Priority: 10
IO Count: 3
IO 0 Request Time: 3
IO 0 Burst Time: 4
IO 1 Request Time: 8
IO 1 Burst Time: 2
IO 2 Request Time: 13
IO 2 Burst Time: 2
========================================

========================================
Process 3
Arrival Time: 1
Burst Time: 15
Priority: 4
IO Count: 2
IO 0 Request Time: 6
IO 0 Burst Time: 4
IO 1 Request Time: 10
IO 1 Burst Time: 1
========================================

========================================
Process 4
Arrival Time: 22
Burst Time: 17
Priority: 5
IO Count: 2
IO 0 Request Time: 4
IO 0 Burst Time: 4
IO 1 Request Time: 13
IO 1 Burst Time: 4
========================================

========================================
Process 5
Arrival Time: 2
Burst Time: 7
Priority: 2
IO Count: 2
IO 0 Request Time: 2
IO 0 Burst Time: 1
IO 1 Request Time: 3
IO 1 Burst Time: 5
========================================



Running FCFS

Gantt chart
========================================

|  idle  |   P3   |   P5   |   P1   |   P5   |   P3   |   P1   |   P5   |   P3   |   P4   |   P2   |  idle  |   P4   |   P2   |   P4   |   P2   |  idle  |   P2   |  idle  |
0        1        7        9        10       11       15       25       29       34       38      41        42       51       56       60      65        67      70        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      6       11      9               1               25              19              5              3
2       TERMINATED      32      16      10              3               70              38              14             6
3       TERMINATED      1       15      4               2               34              33              13             0
4       TERMINATED      22      17      5               2               60              38              13             12
5       TERMINATED      2       7       2               2               29              27              14             5


Average waiting time: 11.80     Max: 14, Min: 5, Variance: 11.76
Average turnaround time: 31.00  Max: 38, Min:19, Variance: 52.40
Average response time: 5.20     Max: 12, Min: 0, Variance: 15.76
Average completion time: 43.60  Max: 70, Min:25, Variance: 323.44
CPU Utilization: 95.65%
Throughput: 7.25 process per 100s
CPU time: 66
IO time: 30
Idle time: 3
Total time: 69
Context switch: 13 times

========================================


Running SJF

Gantt chart
========================================

|  idle  |   P3   |   P5   |   P3   |   P5   |   P1   |   P3   |   P1   |   P5   |   P3   |   P4   |   P3   |   P4   |   P2   |  idle  |   P4   |   P2   |  idle  |   P2   |  idle  |   P2   |  idle  |
0        1        2        4        6        7        8        11       21       25       29       33       38       47      50        51       55      60        62      67        69      72        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      6       11      9               1               21              15              1              1
2       TERMINATED      32      16      10              3               72              40              16             15
3       TERMINATED      1       15      4               2               38              37              17             0
4       TERMINATED      22      17      5               2               55              33              8              7
5       TERMINATED      2       7       2               2               25              23              10             0


Average waiting time: 10.40     Max: 17, Min: 1, Variance: 33.84
Average turnaround time: 29.60  Max: 40, Min:15, Variance: 86.24
Average response time: 4.60     Max: 15, Min: 0, Variance: 33.84
Average completion time: 42.20  Max: 72, Min:21, Variance: 362.96
CPU Utilization: 92.96%
Throughput: 7.04 process per 100s
CPU time: 66
IO time: 30
Idle time: 5
Total time: 71
Context switch: 14 times

========================================


Running SJF Non-Preemptive

Gantt chart
========================================

|  idle  |   P3   |   P5   |   P1   |   P5   |   P3   |   P1   |   P5   |   P3   |   P2   |   P4   |   P2   |   P4   |   P2   |   P4   |   P2   |  idle  |
0        1        7        9        10       11       15       25       29       34       37       41       46       55       60       64      67        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      6       11      9               1               25              19              5              3
2       TERMINATED      32      16      10              3               67              35              11             2
3       TERMINATED      1       15      4               2               34              33              13             0
4       TERMINATED      22      17      5               2               64              42              17             15
5       TERMINATED      2       7       2               2               29              27              14             5


Average waiting time: 12.00     Max: 17, Min: 5, Variance: 16.00
Average turnaround time: 31.20  Max: 42, Min:19, Variance: 60.16
Average response time: 5.00     Max: 15, Min: 0, Variance: 27.60
Average completion time: 43.80  Max: 67, Min:25, Variance: 322.96
CPU Utilization: 100.00%
Throughput: 7.58 process per 100s
CPU time: 66
IO time: 30
Idle time: 0
Total time: 66
Context switch: 14 times

========================================


Running Priority

Gantt chart
========================================

|  idle  |   P3   |   P5   |   P3   |   P5   |   P1   |  idle  |   P3   |   P5   |   P3   |   P4   |   P1   |   P4   |   P2   |  idle  |   P4   |   P2   |  idle  |   P2   |  idle  |   P2   |  idle  |
0        1        2        4        9        10      11        13       17       21       26       30       40       49      52        53       57      62        64      69        71      74        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      6       11      9               1               40              34              20             4
2       TERMINATED      32      16      10              3               74              42              18             17
3       TERMINATED      1       15      4               2               26              25              5              0
4       TERMINATED      22      17      5               2               57              35              10             4
5       TERMINATED      2       7       2               2               21              19              6              0


Average waiting time: 11.80     Max: 20, Min: 5, Variance: 37.76
Average turnaround time: 31.00  Max: 42, Min:19, Variance: 65.20
Average response time: 5.00     Max: 17, Min: 0, Variance: 39.20
Average completion time: 43.60  Max: 74, Min:21, Variance: 387.44
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

|  idle  |   P3   |   P5   |   P1   |   P5   |   P3   |   P1   |   P5   |   P3   |   P4   |   P2   |  idle  |   P4   |   P2   |   P4   |   P2   |  idle  |   P2   |  idle  |
0        1        7        9        10       11       15       25       29       34       38      41        42       51       56       60      65        67      70        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      6       11      9               1               25              19              5              3
2       TERMINATED      32      16      10              3               70              38              14             6
3       TERMINATED      1       15      4               2               34              33              13             0
4       TERMINATED      22      17      5               2               60              38              13             12
5       TERMINATED      2       7       2               2               29              27              14             5


Average waiting time: 11.80     Max: 14, Min: 5, Variance: 11.76
Average turnaround time: 31.00  Max: 38, Min:19, Variance: 52.40
Average response time: 5.20     Max: 12, Min: 0, Variance: 15.76
Average completion time: 43.60  Max: 70, Min:25, Variance: 323.44
CPU Utilization: 95.65%
Throughput: 7.25 process per 100s
CPU time: 66
IO time: 30
Idle time: 3
Total time: 69
Context switch: 13 times

========================================


Running RR

Gantt chart
========================================

|  idle  |   P3   |   P5   |   P3   |   P1   |   P5   |   P3   |   P1   |   P1   |   P5   |   P1   |   P3   |   P5   |   P1   |   P3   |   P4   |   P1   |   P3   |   P4   |   P2   |   P3   |   P2   |   P3   |   P4   |   P4   |   P2   |   P4   |   P2   |   P4   |   P2   |   P4   |  idle  |   P2   |   P2   |   P4   |   P2   |   P4   |   P2   |   P2   |  idle  |
0        1        3        5        7        8        9        11       13       15       17       19       21       23       25       27       29       31       33       35       37       39       40       41       43       45       47       49       51       53       54      55        56       58       60       62       63       65       67      68        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      6       11      9               1               31              25              11             1
2       TERMINATED      32      16      10              3               68              36              12             3
3       TERMINATED      1       15      4               2               41              40              20             0
4       TERMINATED      22      17      5               2               65              43              18             5
5       TERMINATED      2       7       2               2               23              21              8              1


Average waiting time: 13.80     Max: 20, Min: 8, Variance: 20.16
Average turnaround time: 33.00  Max: 43, Min:21, Variance: 73.20
Average response time: 2.00     Max:  5, Min: 0, Variance: 3.20
Average completion time: 45.60  Max: 68, Min:23, Variance: 324.64
CPU Utilization: 98.51%
Throughput: 7.46 process per 100s
CPU time: 66
IO time: 30
Idle time: 1
Total time: 67
Context switch: 32 times

========================================


Running Aging Priority

Gantt chart
========================================

|  idle  |   P3   |   P5   |   P3   |   P5   |   P1   |  idle  |   P3   |   P5   |   P3   |   P4   |   P1   |   P4   |   P2   |  idle  |   P4   |   P2   |  idle  |   P2   |  idle  |   P2   |  idle  |
0        1        2        4        9        10      11        13       17       21       26       30       40       49      52        53       57      62        64      69        71      74        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      6       11      5               1               40              34              20             4
2       TERMINATED      32      16      7               3               74              42              18             17
3       TERMINATED      1       15      3               2               26              25              5              0
4       TERMINATED      22      17      3               2               57              35              10             4
5       TERMINATED      2       7       1               2               21              19              6              0


Average waiting time: 11.80     Max: 20, Min: 5, Variance: 37.76
Average turnaround time: 31.00  Max: 42, Min:19, Variance: 65.20
Average response time: 5.00     Max: 17, Min: 0, Variance: 39.20
Average completion time: 43.60  Max: 74, Min:21, Variance: 387.44
CPU Utilization: 90.41%
Throughput: 6.85 process per 100s
CPU time: 66
IO time: 30
Idle time: 7
Total time: 73
Context switch: 13 times

========================================


Running Aging Priority Non-Preemptive

Gantt chart
========================================

|  idle  |   P3   |   P5   |   P1   |   P5   |   P3   |   P1   |   P5   |   P3   |   P4   |   P2   |  idle  |   P4   |   P2   |   P4   |   P2   |  idle  |   P2   |  idle  |
0        1        7        9        10       11       15       25       29       34       38      41        42       51       56       60      65        67      70        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting        Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      6       11      8               1               25              19              5              3
2       TERMINATED      32      16      8               3               70              38              14             6
3       TERMINATED      1       15      2               2               34              33              13             0
4       TERMINATED      22      17      3               2               60              38              13             12
5       TERMINATED      2       7       0               2               29              27              14             5


Average waiting time: 11.80     Max: 14, Min: 5, Variance: 11.76
Average turnaround time: 31.00  Max: 38, Min:19, Variance: 52.40
Average response time: 5.20     Max: 12, Min: 0, Variance: 15.76
Average completion time: 43.60  Max: 70, Min:25, Variance: 323.44
CPU Utilization: 95.65%
Throughput: 7.25 process per 100s
CPU time: 66
IO time: 30
Idle time: 3
Total time: 69
Context switch: 13 times

========================================



Comparation
========================================
Preemptive SJF has shortest average waiting time: 10.40
13% shorter than average (11.90)

Preemptive SJF has shortest average turnaround time: 29.60
5% shorter than average (31.10)

RR has shortest average response time: 2.00
57% shorter than average (4.65)

Nonpreemptive SJF has shortest max completion time: 67
5% shorter than average (70.62)

FCFS has smallest variance of waiting time: 11.76
Nonpreemptive Priority has smallest variance of waiting time: 11.76
Aging Nonpreemptive Priority has smallest variance of waiting time: 11.76
48% smaller than average (22.60)

Nonpreemptive SJF has highest cpu utilization: 1.00
5% higher than average (0.95)

Nonpreemptive SJF has highest throughput: 0.08
5% higher than average (0.07)

Nonpreemptive SJF has smallest idle time: 0
100% smaller than average (3.62)

FCFS has smallest context switch: 13
Preemptive Priority has smallest context switch: 13
Nonpreemptive Priority has smallest context switch: 13
Aging Preemptive Priority has smallest context switch: 13
Aging Nonpreemptive Priority has smallest context switch: 13
17% smaller than average (15.62)
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



Comparation
========================================
Nonpreemptive SJF has shortest average waiting time: 9.50
Nonpreemptive Priority has shortest average waiting time: 9.50
7% shorter than average (10.25)

Nonpreemptive SJF has shortest average turnaround time: 28.75
Nonpreemptive Priority has shortest average turnaround time: 28.75
3% shorter than average (29.50)

RR has shortest average response time: 0.75
82% shorter than average (4.09)

RR has shortest max completion time: 65
6% shorter than average (69.00)

FCFS has smallest variance of waiting time: 8.19
Preemptive SJF has smallest variance of waiting time: 8.19
76% smaller than average (34.70)

RR has highest cpu utilization: 0.98
8% higher than average (0.91)

RR has highest throughput: 0.08
8% higher than average (0.07)

RR has smallest idle time: 1
80% smaller than average (5.00)

Nonpreemptive SJF has smallest context switch: 11
Preemptive Priority has smallest context switch: 11
Nonpreemptive Priority has smallest context switch: 11
15% smaller than average (13.00)
```