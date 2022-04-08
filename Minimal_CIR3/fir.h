#ifndef FIR_H
#define FIR_H

#include "define.h"
#include "fichiers.h"

/**
 * @brief Parameters for the FIR filter
 */
typedef struct
{
    absorp *firBuffer; /* Buffer containing ordreFiltre number of last elements */
    float *coefFiltre; /* Coefficients for FIR filter */
    int ordreFiltre;   /* Order of FIR filter */
} param_fir;

/**
 * @brief FIR Filter function for automatic tests
 *
 * @param filename
 * @return absorp
 */
absorp firTest(char *filename);

/**
 * @brief FIR Filter initialisation
 *
 * @param coefFiltre
 * @param ordreFiltre
 * @return param_fir*
 */
param_fir *initFir(float *coefFiltre, int ordreFiltre);

/**
 * @brief FIR : finite impulse response
 *
 * @param myAbsorb
 * @param myFIR
 * @return absorp
 */
absorp fir(absorp myAbsorb, param_fir *myFIR);

/**
 * @brief free memory allocated to param_fir at initialisation
 *
 * @param myFIR
 */
void finFir(param_fir *myFIR);

#endif