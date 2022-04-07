#include "iir.h"

absorp iirTest(char *filename) {
    float alpha = 0.992;
    int etat = 0;
    absorp myAbsorp;
    param_iir *myIIR = initIIR(alpha);
    FILE *myFile = initFichier(filename);
    do {
        myAbsorp = lireFichier(myFile, &etat);
        if (etat != EOF) {
            printf("%f, %f \n", myAbsorp.acir, myAbsorp.acr);
            myAbsorp = iir(myAbsorp, myIIR);
            printf("> %f, %f, %f, %f \n", myAbsorp.acir, myAbsorp.acr,
                   myAbsorp.dcir, myAbsorp.dcr);
        }
    } while (etat != EOF);
    myAbsorp = myIIR->lastOutput;
    myAbsorp.acr = (int)(myAbsorp.acr);
    myAbsorp.acir = (int)(myAbsorp.acir);

    finFichier(myFile);
    finIIR(myIIR);

    return myAbsorp;
}

param_iir *initIIR(float alpha) {
    param_iir *myIIR = malloc(sizeof(param_iir));
    absorp tempAbsorp = {.acir = 0, .acr = 0, .dcir = 0, .dcr = 0};
    myIIR->alpha = alpha;
    myIIR->lastInput = tempAbsorp;
    myIIR->lastOutput = tempAbsorp;

    return myIIR;
}

absorp iir(absorp myAbsorp, param_iir *myIIR) {
    absorp tempAbsorp = myAbsorp;
    myAbsorp.acr = myAbsorp.acr - myIIR->lastInput.acr +
                   myIIR->alpha * myIIR->lastOutput.acr;
    myAbsorp.acir = myAbsorp.acir - myIIR->lastInput.acir +
                    myIIR->alpha * myIIR->lastOutput.acir;
    myIIR->lastInput = tempAbsorp;
    myIIR->lastOutput = myAbsorp;

    myAbsorp.acr = (int)(myAbsorp.acr);
    myAbsorp.acir = (int)(myAbsorp.acir);

    return myAbsorp;
}

void finIIR(param_iir *myIIR) {
    free(myIIR);
    return;
}