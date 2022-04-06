#ifndef LECTURE_H
#define LECTURE_H

#include "define.h"

void *init_UART();
void close_UART(void *handle);
absorp read_UART(void *handle, int *file_state);

absorp lecture(FILE *file_pf, int *file_state);

#endif