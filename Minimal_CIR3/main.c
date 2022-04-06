#include <stdio.h>
#include <stdlib.h>

#include "fichiers.h"
#include "lecture.h"
#include "mesure.h"
#include "iir.h"
#include "fir.h"
#include "integration.h"

int main()
{
    integrationTestUART();
    /*
    mesureTest("../fichiers/record1_iir.dat");
    int etat = 0;
    absorp myAbsorp, a2;
    FILE *fp = fopen("../fichiers/record1_bin.dat", "r");
    FILE *fp2 = initFichier("../fichiers/record1.dat");


    while (etat != EOF)
    {

        myAbsorp = lecture(fp, &etat);
        a2 = lireFichier(fp2, &etat);

        printf("%f %f %f %f\n", myAbsorp.acr, myAbsorp.dcr, myAbsorp.acir, myAbsorp.dcir);
        return 1;

        if (a2.acr != myAbsorp.acr || a2.acir != myAbsorp.acir || a2.dcir != myAbsorp.dcir || a2.dcr != myAbsorp.dcr)
        {
            if(etat == EOF) break;
            if(a2.acr != myAbsorp.acr) {
                printf("ACR : %f != %f\n", a2.acr, myAbsorp.acr);
            }if(a2.acir != myAbsorp.acir) {
                printf("ACIR : %f != %f\n", a2.acir, myAbsorp.acir);
            }if(a2.dcr != myAbsorp.dcr) {
                printf("DCR : %f != %f\n", a2.dcr, myAbsorp.dcr);
            }if(a2.dcir != myAbsorp.dcir) {
                printf("DCIR : %f != %f\n", a2.dcir, myAbsorp.dcir);
            }
        }
    }*/

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

// void test_UART()
// {
//     void *handler = init_UART();
//     int state;

//     int count = 0;
//     while (++count < 50)
//     {
//         absorp data = read_UART(handler, &state);

//         if (state == EOF)
//         {
//             printf("EOF!\n");
//             break;
//         }
//         printf("Struct : %f %f %f %f\n", data.acr, data.dcr, data.acir, data.dcir);
//     }
// }