#ifndef LECTURE_H
#define LECTURE_H

#include "define.h"

/**
 * @brief
 *
 * @return void*
 */
void *init_UART();

/**
 * @brief
 *
 * @return void*
 */
void close_UART(void *handle);

/**
 * @brief
 *
 * @return void*
 */
absorp read_UART(void *handle, int *file_state);

/**
 * @brief
 *
 * @return void*
 */
absorp lecture(FILE *file_pf, int *file_state);

#endif