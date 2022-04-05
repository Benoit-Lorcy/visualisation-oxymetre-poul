#ifndef IIR_H
#define IIR_H

#include "define.h"
#include "fichiers.h"

/*! ------------------------------------------------------------

  \struct param_fir

  \brief

  ------------------------------------------------------------*/

typedef struct
{
    float alpha;
    absorp lastInput;
    absorp lastOutput;
} param_iir;

absorp iirTest(char *filename);
param_iir *initIIR(float alpha);
absorp iir(absorp myAbsorb, param_iir *myIIR);
void finIIR(param_iir *myIIR);

#endif