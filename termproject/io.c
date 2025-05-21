#include "io.h"
#include <stdlib.h>

void create_io(IO *io, int io_count, int* request_times, int* burst_times){
    for (int i = 0; i < io_count; i++){
        io[i].request_time = request_times[i];
        io[i].burst_time = burst_times[i];
        io[i].io_time = 0;
        io[i].completed = 0;
    }
}

void create_random_io(IO *io, int io_count, int burst){
    int interval = burst / io_count;
    for (int i = 0; i < io_count; i++){
        while(io[i].request_time == 0){
            io[i].request_time = rand() % interval + (interval * i);
        }
        io[i].burst_time = rand() % MAX_IO_BURST_TIME + 1;
        io[i].io_time = 0;
        io[i].completed = 0;
    }
}