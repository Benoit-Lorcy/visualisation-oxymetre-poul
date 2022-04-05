#ifndef FIR_H
#define FIR_H

#include "define.h"
#include "fichiers.h"

/*! ------------------------------------------------------------

  \struct param_fir

  \brief

  ------------------------------------------------------------*/

typedef struct
{
    absorp *firBuffer;
    float *coefFiltre;
    int ordreFiltre;
} param_fir;

absorp firTest(char *filename);

param_fir *initFir(float *coefFiltre, int ordreFiltre);
absorp fir(absorp myAbsorb, param_fir *myFIR);
void finFir(param_fir *myFIR);

#endif