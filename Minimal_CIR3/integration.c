#include "integration.h"

void integrationTest(char *filename)
{
    float FIR_TAPS[51] = {
        1.4774946e-019,
        1.6465231e-004,
        3.8503956e-004,
        7.0848037e-004,
        1.1840522e-003,
        1.8598621e-003,
        2.7802151e-003,
        3.9828263e-003,
        5.4962252e-003,
        7.3374938e-003,
        9.5104679e-003,
        1.2004510e-002,
        1.4793934e-002,
        1.7838135e-002,
        2.1082435e-002,
        2.4459630e-002,
        2.7892178e-002,
        3.1294938e-002,
        3.4578348e-002,
        3.7651889e-002,
        4.0427695e-002,
        4.2824111e-002,
        4.4769071e-002,
        4.6203098e-002,
        4.7081811e-002,
        4.7377805e-002,
        4.7081811e-002,
        4.6203098e-002,
        4.4769071e-002,
        4.2824111e-002,
        4.0427695e-002,
        3.7651889e-002,
        3.4578348e-002,
        3.1294938e-002,
        2.7892178e-002,
        2.4459630e-002,
        2.1082435e-002,
        1.7838135e-002,
        1.4793934e-002,
        1.2004510e-002,
        9.5104679e-003,
        7.3374938e-003,
        5.4962252e-003,
        3.9828263e-003,
        2.7802151e-003,
        1.8598621e-003,
        1.1840522e-003,
        7.0848037e-004,
        3.8503956e-004,
        1.6465231e-004,
        1.4774946e-019};

    // initialize parameters for each part of the program to read a file
    FILE *f = initFichier(filename);

    param_fir *pfir = initFir(FIR_TAPS, 51);
    param_iir *piir = initIIR(0.992f);
    MesureEnv *pmesure = mesure_init();

    int etat = !EOF;

    // processing data in file
    do
    {
        absorp current = lireFichier(f, &etat);

        if (etat != EOF)
        {
            current = fir(current, pfir);
            current = iir(current, piir);

            oxy final = mesure(pmesure, current);

            // write processeds data to file
            affichage(final);
        }
    } while (etat != EOF);

    // free memory
    finFir(pfir);
    finIIR(piir);
    mesure_close(pmesure);
}

void integrationTestUART()
{
    float FIR_TAPS[51] = {
        1.4774946e-019,
        1.6465231e-004,
        3.8503956e-004,
        7.0848037e-004,
        1.1840522e-003,
        1.8598621e-003,
        2.7802151e-003,
        3.9828263e-003,
        5.4962252e-003,
        7.3374938e-003,
        9.5104679e-003,
        1.2004510e-002,
        1.4793934e-002,
        1.7838135e-002,
        2.1082435e-002,
        2.4459630e-002,
        2.7892178e-002,
        3.1294938e-002,
        3.4578348e-002,
        3.7651889e-002,
        4.0427695e-002,
        4.2824111e-002,
        4.4769071e-002,
        4.6203098e-002,
        4.7081811e-002,
        4.7377805e-002,
        4.7081811e-002,
        4.6203098e-002,
        4.4769071e-002,
        4.2824111e-002,
        4.0427695e-002,
        3.7651889e-002,
        3.4578348e-002,
        3.1294938e-002,
        2.7892178e-002,
        2.4459630e-002,
        2.1082435e-002,
        1.7838135e-002,
        1.4793934e-002,
        1.2004510e-002,
        9.5104679e-003,
        7.3374938e-003,
        5.4962252e-003,
        3.9828263e-003,
        2.7802151e-003,
        1.8598621e-003,
        1.1840522e-003,
        7.0848037e-004,
        3.8503956e-004,
        1.6465231e-004,
        1.4774946e-019};

    // initialize parameters for each part of the program to read USB
    void *uart = init_UART();

    param_fir *pfir = initFir(FIR_TAPS, 51);
    param_iir *piir = initIIR(0.992f);
    MesureEnv *pmesure = mesure_init();

    int etat = !EOF;

    // processing UART
    do
    {
        absorp current = read_UART(uart, &etat);

        if (etat != EOF)
        {
            current = fir(current, pfir);
            current = iir(current, piir);

            oxy final = mesure(pmesure, current);

            // write data to file
            affichage(final);
        }
    } while (etat != EOF);

    // free memory
    finFir(pfir);
    finIIR(piir);
    mesure_close(pmesure);

    close_UART(uart);
}