#ifndef IO_H
#define IO_H

#include "types.h"

void create_io(IO *io, int io_count, int* request_times, int* burst_times);
void create_random_io(IO *io, int io_count, int burst);

#endif