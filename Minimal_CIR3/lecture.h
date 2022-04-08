#ifndef LECTURE_H
#define LECTURE_H

#include "define.h"

/**
 * @brief UART initialisation with ftd2xx
 *
 * @return void*
 */
void *init_UART();

/**
 * @brief Close UART connection
 *
 * @param handle
 */
void close_UART(void *handle);

/**
 * @brief  Read current data of UART connection
 *
 * @param handle
 * @param file_state
 * @return absorp
 */
absorp read_UART(void *handle, int *file_state);

/**
 * @brief Same as lireFichier with error handlling
 *
 * @param file_pf
 * @param file_state
 * @return absorp
 */
absorp lecture(FILE *file_pf, int *file_state);

#endif