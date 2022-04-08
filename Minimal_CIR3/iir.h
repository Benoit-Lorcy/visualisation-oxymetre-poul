#ifndef IIR_H
#define IIR_H

#include "define.h"
#include "fichiers.h"

/**
 * @brief Parameters for the IIR filter
 */
typedef struct
{
    float alpha;       /*  */
    absorp lastInput;  /*  */
    absorp lastOutput; /* Despacito */
} param_iir;

/**
 * @brief IIR Filter function for automatic tests
 *
 * @param filename
 * @return absorp
 */
absorp iirTest(char *filename);

/**
 * @brief IIR Filter initialisation
 *
 *
 * @param alpha
 * @return param_iir*
 */
param_iir *initIIR(float alpha);

/**
 * @brief IIR Filter : infinite impulse response
 *
 * @param myAbsorb
 * @param myIIR
 * @return absorp
 */
absorp iir(absorp myAbsorb, param_iir *myIIR);

/**
 * @brief free memory allocated to param_iir at initialisation
 *
 * @param myIIR
 */
void finIIR(param_iir *myIIR);

#endif