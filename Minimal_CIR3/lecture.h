#include "define.h"

void *init_UART();
void close_UART();
absorp read_UART(void *handle, int *file_state);

absorp lecture(FILE *file_pf, int *file_state);