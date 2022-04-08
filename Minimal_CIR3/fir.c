#include "fir.h"

absorp firTest(char *filename)
{
    // initialise coeficients
    float FIR_TAPS[51] = {
        1.4774946e-019, 1.6465231e-004, 3.8503956e-004, 7.0848037e-004,
        1.1840522e-003, 1.8598621e-003, 2.7802151e-003, 3.9828263e-003,
        5.4962252e-003, 7.3374938e-003, 9.5104679e-003, 1.2004510e-002,
        1.4793934e-002, 1.7838135e-002, 2.1082435e-002, 2.4459630e-002,
        2.7892178e-002, 3.1294938e-002, 3.4578348e-002, 3.7651889e-002,
        4.0427695e-002, 4.2824111e-002, 4.4769071e-002, 4.6203098e-002,
        4.7081811e-002, 4.7377805e-002, 4.7081811e-002, 4.6203098e-002,
        4.4769071e-002, 4.2824111e-002, 4.0427695e-002, 3.7651889e-002,
        3.4578348e-002, 3.1294938e-002, 2.7892178e-002, 2.4459630e-002,
        2.1082435e-002, 1.7838135e-002, 1.4793934e-002, 1.2004510e-002,
        9.5104679e-003, 7.3374938e-003, 5.4962252e-003, 3.9828263e-003,
        2.7802151e-003, 1.8598621e-003, 1.1840522e-003, 7.0848037e-004,
        3.8503956e-004, 1.6465231e-004, 1.4774946e-019};
    int etat = 0;
    int ordreFiltre = 51;

    absorp myAbsorp;
    absorp saveAbsorp;

    // file and fir initialisation
    param_fir *myFIR = initFir(FIR_TAPS, ordreFiltre);
    FILE *myFile = initFichier(filename);

    // reading file and applying the filter
    do
    {
        myAbsorp = lireFichier(myFile, &etat);
        if (etat != EOF)
        {
            myAbsorp = fir(myAbsorp, myFIR);
            saveAbsorp = myAbsorp;
        }
    } while (etat != EOF);

    // free memory
    finFichier(myFile);
    finFir(myFIR);

    // return last value, (that's why we need to save it in the while)
    return saveAbsorp;
}

param_fir *initFir(float *coefFiltre, int ordreFiltre)
{
    param_fir *myFIR = malloc(sizeof(param_fir));
    myFIR->coefFiltre = coefFiltre;
    myFIR->ordreFiltre = ordreFiltre;
    // on met des 0 dans firBuffer comme ça on peut l'utiliser dans les calculs
    myFIR->firBuffer = calloc(ordreFiltre, sizeof(absorp));

    return myFIR;
}

absorp fir(absorp myAbsorp, param_fir *myFIR)
{
    absorp tempAbsorb = {
        .acir = 0, .acr = 0, .dcir = myAbsorp.dcir, .dcr = myAbsorp.dcr};

    // we move the memory to the right so we can add a new element in front
    memmove(myFIR->firBuffer + 1, myFIR->firBuffer,
            sizeof(absorp) * (myFIR->ordreFiltre - 1));

    // add the new element to the list
    myFIR->firBuffer[0] = myAbsorp;

    // appling the filter the filter
    int i;
    for (i = 0; i < myFIR->ordreFiltre; i++)
    {
        tempAbsorb.acr += myFIR->coefFiltre[i] * myFIR->firBuffer[i].acr;
        tempAbsorb.acir += myFIR->coefFiltre[i] * myFIR->firBuffer[i].acir;
    }

    // we format the output by casting it to an int
    tempAbsorb.acir = (int)(tempAbsorb.acir);
    tempAbsorb.acr = (int)(tempAbsorb.acr);

    return tempAbsorb;
}

void finFir(param_fir *myFIR)
{
    // free all pointer with allocated memory
    free(myFIR->firBuffer);
    free(myFIR);
    return;
}