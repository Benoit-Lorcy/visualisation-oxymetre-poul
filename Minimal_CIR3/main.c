#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
#include "lecture.h"

int main()
{
    printf("Yolo!\n");
    int etat=0;
    absorp myAbsorp;
    // oxy myOxy;
    // param_fir* myFIR = init_fir(...); // init FIR
    // param_iir* myIIR = init_iir(...); // init IIR
    // param_mesure* myMes = init_mesure(...) // init mesure
    // FILE* myFile = initFichier("record1.dat");
    
    // do{
    //     myAbsorp = lireFichier(myFile,&etat);
    //     myAbsorp = fir(myAbsorp,myFIR);
    //     myAbsorp = iir(myAbsorp,myIIR);
    //     myOxy = mesure(myAbsorp,myMes);
    //     affichage(myOxy);
    // }while( etat != EOF )
    // finFichier(myFile);
    // fin_mesure(myMes);
    // fin_iir(myIIR);
    // fin_fir(myFIR) 
    return EXIT_SUCCESS;
}

void test_UART()
{
    void *handler = init_UART();
    int state;

    int count = 0;
    while (++count < 50)
    {
        absorp data = read_UART(handler, &state);

        if (state == EOF)
        {
            printf("EOF!\n");
            break;
        }
        printf("Struct : %f %f %f %f\n", data.acr, data.dcr, data.acir, data.dcir);
    }
}