#include <stdio.h>
#include <stdlib.h>

#include "lecture.h"
#include "mesure.h"

int main()
{
    printf("Yolo!\n");
 
    mesureTest("../fichiers/record1_iir.dat");
    int etat=0;
    absorp myAbsorp;
    FILE* fp = fopen("../fichiers/record1_bin.dat", "r");

    while(etat != EOF) {

    myAbsorp = lecture(fp, &etat);

    printf("%f : %f : %f : %f\n", myAbsorp.acr, myAbsorp.dcr, myAbsorp.acir, myAbsorp.dcir);
    }

    
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