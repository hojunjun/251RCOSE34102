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
    - create process from input
- queue
    - basic queue implementation
    - get shortest job
    - get highest priority job
- io
    - create hard coded io
    - create random io
    - create io from input
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
- io
    - create io from files
- scheduler
    - more algorithms
- evaluation
    - compare
    - analyze

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

|   P1   |   P1   |   P2   |   P1   |   P3   |   P2   |   P1   |   P3   |   P2   |   P1   |  idle  |
0        2        4        6        8        10       12       14       15       16      18        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      0       10      2               0               18              18              8               0
2       TERMINATED      2       5       3               0               16              14              9               2
3       TERMINATED      4       3       1               0               15              11              8               4


Average waiting time: 8.33      Max:  9, Min: 8
Average turnaround time: 14.33  Max: 18, Min:11
Average response time: 2.00     Max:  4, Min: 0
Average completion time: 16.33  Max: 18, Min:15

========================================
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
Arrival Time: 48
Burst Time: 17
Priority: 5
IO Count: 2
IO 0 Request Time: 3
IO 0 Burst Time: 2
IO 1 Request Time: 12
IO 1 Burst Time: 3
========================================

========================================
Process 2
Arrival Time: 18
Burst Time: 13
Priority: 5
IO Count: 2
IO 0 Request Time: 3
IO 0 Burst Time: 1
IO 1 Request Time: 7
IO 1 Burst Time: 5
========================================

========================================
Process 3
Arrival Time: 15
Burst Time: 7
Priority: 7
IO Count: 2
IO 0 Request Time: 2
IO 0 Burst Time: 2
IO 1 Request Time: 4
IO 1 Burst Time: 3
========================================

========================================
Process 4
Arrival Time: 21
Burst Time: 15
Priority: 7
IO Count: 2
IO 0 Request Time: 6
IO 0 Burst Time: 2
IO 1 Request Time: 10
IO 1 Burst Time: 4
========================================

========================================
Process 5
Arrival Time: 29
Burst Time: 19
Priority: 2
IO Count: 2
IO 0 Request Time: 1
IO 0 Burst Time: 4
IO 1 Request Time: 10
IO 1 Burst Time: 2
========================================
Running FCFS

Gantt chart
========================================

|  idle  |   P3   |  idle  |   P2   |   P3   |   P4   |   P2   |   P3   |   P5   |   P4   |   P2   |   P5   |   P4   |   P1   |   P5   |   P1   |  idle  |   P1   |  idle  |
0        15      17        18       21       23       29       33       36       37       41       47       56       61       64       73      82        85      90        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      48      17      5               2               90              42              20              13
2       TERMINATED      18      13      5               2               47              29              10              0
3       TERMINATED      15      7       7               2               36              21              9               0
4       TERMINATED      21      15      7               2               61              40              19              2
5       TERMINATED      29      19      2               2               73              44              19              7


Average waiting time: 15.40     Max: 20, Min: 9
Average turnaround time: 35.20  Max: 44, Min:21
Average response time: 4.40     Max: 13, Min: 0
Average completion time: 61.40  Max: 90, Min:36

========================================

Running SJF

Gantt chart
========================================

|  idle  |   P3   |  idle  |   P2   |   P3   |   P2   |   P3   |   P4   |   P2   |   P4   |   P5   |  idle  |   P1   |   P4   |   P1   |   P5   |   P1   |   P5   |  idle  |
0        15      17        18       21       23       27       30       36       42       46      47        48       51       56       65       74       79      88        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      48      17      5               2               79              31              9               0
2       TERMINATED      18      13      5               2               42              24              5               0
3       TERMINATED      15      7       7               2               30              15              3               0
4       TERMINATED      21      15      7               2               56              35              14              9
5       TERMINATED      29      19      2               2               88              59              34              17


Average waiting time: 13.00     Max: 34, Min: 3
Average turnaround time: 32.80  Max: 59, Min:15
Average response time: 5.20     Max: 17, Min: 0
Average completion time: 59.00  Max: 88, Min:30

========================================

Running SJF Non-Preemptive

Gantt chart
========================================

|  idle  |   P3   |  idle  |   P2   |   P3   |   P2   |   P3   |   P4   |   P2   |   P4   |   P5   |  idle  |   P1   |   P4   |   P1   |   P5   |   P1   |   P5   |  idle  |
0        15      17        18       21       23       27       30       36       42       46      47        48       51       56       65       74       79      88        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      48      17      5               2               79              31              9               0
2       TERMINATED      18      13      5               2               42              24              5               0
3       TERMINATED      15      7       7               2               30              15              3               0
4       TERMINATED      21      15      7               2               56              35              14              9
5       TERMINATED      29      19      2               2               88              59              34              17


Average waiting time: 13.00     Max: 34, Min: 3
Average turnaround time: 32.80  Max: 59, Min:15
Average response time: 5.20     Max: 17, Min: 0
Average completion time: 59.00  Max: 88, Min:30

========================================

Running Priority

Gantt chart
========================================

|  idle  |   P3   |  idle  |   P2   |   P3   |   P2   |   P4   |   P5   |   P3   |   P2   |   P5   |   P1   |   P5   |   P1   |   P4   |   P1   |   P4   |  idle  |   P4   |  idle  |
0        15      17        18       21       23       27       29       30       33       39       48       51       60       69       73       78      82        86      91        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      48      17      5               2               78              30              8               0
2       TERMINATED      18      13      5               2               39              21              2               0
3       TERMINATED      15      7       7               2               33              18              6               0
4       TERMINATED      21      15      7               2               91              70              49              6
5       TERMINATED      29      19      2               2               60              31              6               0


Average waiting time: 14.20     Max: 49, Min: 2
Average turnaround time: 34.00  Max: 70, Min:18
Average response time: 1.20     Max:  6, Min: 0
Average completion time: 60.20  Max: 91, Min:33

========================================

Running Priority Non-Preemptive

Gantt chart
========================================

|  idle  |   P3   |  idle  |   P2   |   P3   |   P2   |   P4   |   P5   |   P2   |   P5   |   P1   |   P5   |   P1   |   P3   |   P1   |   P4   |  idle  |   P4   |  idle  |
0        15      17        18       21       23       27       33       34       40       49       52       61       70       73       78      82        86      91        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      48      17      5               2               78              30              8               1
2       TERMINATED      18      13      5               2               40              22              3               0
3       TERMINATED      15      7       7               2               73              58              46              0
4       TERMINATED      21      15      7               2               91              70              49              6
5       TERMINATED      29      19      2               2               61              32              7               4


Average waiting time: 22.60     Max: 49, Min: 3
Average turnaround time: 42.40  Max: 70, Min:22
Average response time: 2.20     Max:  6, Min: 0
Average completion time: 68.60  Max: 91, Min:40

========================================

Running RR

Gantt chart
========================================

|  idle  |   P3   |  idle  |   P2   |   P3   |   P2   |   P4   |   P2   |   P4   |   P3   |   P2   |   P4   |   P5   |   P3   |   P4   |   P2   |   P4   |   P5   |   P2   |   P5   |   P2   |   P4   |   P1   |   P5   |   P4   |   P1   |   P5   |   P4   |   P5   |   P1   |   P1   |   P5   |   P1   |   P5   |   P1   |   P5   |   P1   |   P5   |   P5   |   P1   |   P1   |   P1   |  idle  |
0        15      17        18       20       22       23       25       27       29       31       33       35       36       37       39       41       43       45       47       49       51       53       55       57       59       60       62       63       64       66       68       70       72       74       76       78       79       81       82       84       86      87        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      48      17      5               2               87              39              17              5
2       TERMINATED      18      13      5               2               51              33              14              0
3       TERMINATED      15      7       7               2               37              22              10              0
4       TERMINATED      21      15      7               2               63              42              21              2
5       TERMINATED      29      19      2               2               82              53              28              6


Average waiting time: 18.00     Max: 28, Min:10
Average turnaround time: 37.80  Max: 53, Min:22
Average response time: 2.60     Max:  6, Min: 0
Average completion time: 64.00  Max: 87, Min:37

========================================
```

```
CPU Scheduling Simulator
========================================
1. Sample
2. Random
3. From file
4. Manual input
========================================
Enter your choice: 4
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

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P4   |   P1   |   P3   |   P2   |  idle  |   P2   |  idle  |   P2   |  idle  |
0        15      18        19       22       28       37       46       52       58      60        62      64        69      72        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               52              37              14              0
2       TERMINATED      46      7       8               2               72              26              12              12
3       TERMINATED      19      18      9               2               58              39              18              0
4       TERMINATED      30      9       10              3               46              16              7               7


Average waiting time: 12.75     Max: 18, Min: 7
Average turnaround time: 29.50  Max: 39, Min:16
Average response time: 4.75     Max: 12, Min: 0
Average completion time: 57.00  Max: 72, Min:46

========================================

Running SJF

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P4   |   P1   |   P3   |   P2   |   P3   |   P2   |   P3   |   P2   |  idle  |
0        15      18        19       22       28       30       39       45       46       48       54       56       62      65        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               45              30              7               0
2       TERMINATED      46      7       8               2               65              19              5               0
3       TERMINATED      19      18      9               2               62              43              22              0
4       TERMINATED      30      9       10              3               39              9               0               0


Average waiting time: 8.50      Max: 22, Min: 0
Average turnaround time: 25.25  Max: 43, Min: 9
Average response time: 0.00     Max:  0, Min: 0
Average completion time: 52.75  Max: 65, Min:39

========================================

Running SJF Non-Preemptive

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P1   |   P3   |   P2   |   P4   |   P2   |  idle  |   P2   |  idle  |
0        15      18        19       22       28       37       43       49       51       60      62        67      70        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               43              28              5               0
2       TERMINATED      46      7       8               2               70              24              10              3
3       TERMINATED      19      18      9               2               49              30              9               0
4       TERMINATED      30      9       10              3               60              30              21              21


Average waiting time: 11.25     Max: 21, Min: 5
Average turnaround time: 28.00  Max: 30, Min:24
Average response time: 6.00     Max: 21, Min: 0
Average completion time: 55.50  Max: 70, Min:43

========================================

Running Priority

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P1   |   P3   |   P2   |   P3   |   P2   |   P4   |   P2   |  idle  |
0        15      18        19       22       28       37       43       46       48       51       53       62      65        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               43              28              5               0
2       TERMINATED      46      7       8               2               65              19              5               0
3       TERMINATED      19      18      9               2               51              32              11              0
4       TERMINATED      30      9       10              3               62              32              23              23


Average waiting time: 11.00     Max: 23, Min: 5
Average turnaround time: 27.75  Max: 32, Min:19
Average response time: 5.75     Max: 23, Min: 0
Average completion time: 55.25  Max: 65, Min:43

========================================

Running Priority Non-Preemptive

Gantt chart
========================================

|  idle  |   P1   |  idle  |   P3   |   P1   |   P3   |   P1   |   P3   |   P2   |   P4   |   P2   |  idle  |   P2   |  idle  |
0        15      18        19       22       28       37       43       49       51       60      62        67      70        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               43              28              5               0
2       TERMINATED      46      7       8               2               70              24              10              3
3       TERMINATED      19      18      9               2               49              30              9               0
4       TERMINATED      30      9       10              3               60              30              21              21


Average waiting time: 11.25     Max: 21, Min: 5
Average turnaround time: 28.00  Max: 30, Min:24
Average response time: 6.00     Max: 21, Min: 0
Average completion time: 55.50  Max: 70, Min:43

========================================

Running RR

Gantt chart
========================================

|  idle  |   P1   |   P1   |  idle  |   P3   |   P3   |   P1   |   P1   |   P3   |   P1   |   P3   |   P4   |   P3   |   P4   |   P1   |   P3   |   P4   |   P1   |   P3   |   P4   |   P1   |   P2   |   P3   |   P4   |   P3   |   P2   |   P3   |  idle  |   P2   |   P2   |  idle  |
0        15       17      18        19       21       22       24       26       28       30       32       34       36       38       40       42       44       46       47       49       51       53       55       56       58       60      62        65       67      68        fin


Process table
========================================
PID     State           Arrival Burst   Priority        IO count        Completion      Turnaround      Waiting         Response
--------------------------------------------------------------------------------------------------------------------------------------
1       TERMINATED      15      15      9               2               51              36              13              0
2       TERMINATED      46      7       8               2               68              22              8               5
3       TERMINATED      19      18      9               2               62              43              22              0
4       TERMINATED      30      9       10              3               56              26              17              2


Average waiting time: 15.00     Max: 22, Min: 8
Average turnaround time: 31.75  Max: 43, Min:22
Average response time: 1.75     Max:  5, Min: 0
Average completion time: 59.25  Max: 68, Min:51

========================================
```