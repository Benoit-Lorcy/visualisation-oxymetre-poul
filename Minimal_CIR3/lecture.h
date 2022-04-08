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
 * @param handle
 */
void close_UART(void *handle);

/**
 * @brief
 *
 * @param handle
 * @param file_state
 * @return absorp
 */
absorp read_UART(void *handle, int *file_state);

/**
 * @brief
 *
 * @param file_pf
 * @param file_state
 * @return absorp
 */
absorp lecture(FILE *file_pf, int *file_state);

#endif