#ifndef MESURE_H
#define MESURE_H

#include "define.h"

typedef struct {
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

oxy mesureTest(char* filename);

MesureEnv *mesure_init();
oxy mesure(MesureEnv *env, absorp data);
void mesure_close(MesureEnv *env);

#endif