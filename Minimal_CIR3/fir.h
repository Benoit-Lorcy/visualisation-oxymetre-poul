#ifndef FIR_H
#define FIR_H

#include "define.h"
#include "fichiers.h"

/**
 * @brief Parameters for the FIR filter
 */
typedef struct
{
    absorp *firBuffer;
    float *coefFiltre;
    int ordreFiltre;
} param_fir;

/**
 * @brief
 *
 * @param filename
 * @return absorp
 */
absorp firTest(char *filename);

/**
 * @brief
 *
 * @param coefFiltre
 * @param ordreFiltre
 * @return param_fir*
 */
param_fir *initFir(float *coefFiltre, int ordreFiltre);

/**
 * @brief
 *
 * @param myAbsorb
 * @param myFIR
 * @return absorp
 */
absorp fir(absorp myAbsorb, param_fir *myFIR);

/**
 * @brief
 *
 * @param myFIR
 */
void finFir(param_fir *myFIR);

#endif