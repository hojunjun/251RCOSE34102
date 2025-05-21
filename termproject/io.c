#include "io.h"
#include <stdlib.h>

void init_io(IO *io, int io_count, int burst){
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