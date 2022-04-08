#ifndef IIR_H
#define IIR_H

#include "define.h"
#include "fichiers.h"

/**
 * @brief
 *
 */
typedef struct {
    float alpha;
    absorp lastInput;
    absorp lastOutput;
} param_iir;

/**
 * @brief
 *
 * @param filename
 * @return absorp
 */
absorp iirTest(char *filename);

/**
 * @brief
 *
 * @param alpha
 * @return param_iir*
 */
param_iir *initIIR(float alpha);

/**
 * @brief
 *
 * @param myAbsorb
 * @param myIIR
 * @return absorp
 */
absorp iir(absorp myAbsorb, param_iir *myIIR);

/**
 * @brief
 *
 * @param myIIR
 */
void finIIR(param_iir *myIIR);

#endif