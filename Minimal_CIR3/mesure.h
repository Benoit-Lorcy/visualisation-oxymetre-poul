#ifndef MESURE_H
#define MESURE_H

#include "define.h"

/**
 * @brief Parameters for the measure
 */
typedef struct
{
    char mesure_state;
    float zero_count;
    char can_be_zero;
    float r_maximum, r_minimum;
    float ir_maximum, ir_minimum;

    float r_dc_average;
    float ir_dc_average;

    long counter;

    absorp previous;

    float BPM[8];
    float RsIR[8];
    int BPM_index;

    oxy current;
} MesureEnv;

/**
 * @brief measure function for automatic tests
 *
 * @param filename
 * @return oxy
 */
oxy mesureTest(char *filename);

/**
 * @brief initialisation of the mesure
 *
 * @return MesureEnv*
 */
MesureEnv *mesure_init();

/**
 * @brief get current oxy (BPM, spo2) from current data
 *
 * @param env
 * @param data
 * @return oxy
 */
oxy mesure(MesureEnv *env, absorp data);

/**
 * @brief free memory allocated to MesureEnv at initialisation
 *
 * @param env
 */
void mesure_close(MesureEnv *env);

#endif