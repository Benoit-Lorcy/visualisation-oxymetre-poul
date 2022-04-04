#include "fir.h"

absorp firTest(char *filename)
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

	int etat = 0;
	int ordreFiltre = 51;
	absorp myAbsorp;
	param_fir *myFIR = initFir(FIR_TAPS, ordreFiltre);

	FILE *myFile = initFichier(filename);
	do
	{
		myAbsorp = lireFichier(myFile, &etat);
		printf("%f, %f \n", myAbsorp.acir, myAbsorp.acr);
		myAbsorp = fir(myAbsorp, myFIR);
		printf("> %f, %f \n", myAbsorp.acir, myAbsorp.acr);

	} while (etat != EOF);

	finFichier(myFile);
	finFir(myFIR);

	return myAbsorp;
}

param_fir *initFir(float *coefFiltre, int ordreFiltre)
{
	param_fir *myFIR = malloc(sizeof(param_fir));
	myFIR->coefFiltre = coefFiltre;
	myFIR->ordreFiltre = ordreFiltre;
	// on met des 0 dans firBuffer comme ça on peut l'utiliser dans les calculs sans risque
	// à la base j'avais un calloc mais moins on touche a la mémoire mieux on se porte ;)
	absorp firBuffer[51] = {0};
	myFIR->firBuffer = calloc(ordreFiltre, sizeof(absorp));

	return myFIR;
}

absorp fir(absorp myAbsorp, param_fir *myFIR)
{
	absorp tempAbsorb;
	int i;
	for (i = 0; i < myFIR->ordreFiltre - 1; i++)
	{
		myFIR->firBuffer[i + 1] = myFIR->firBuffer[i];
	}

	myFIR->firBuffer[0] = myAbsorp;

	for (i = 0; i < myFIR->ordreFiltre; i++)
	{
		tempAbsorb.acr += myFIR->coefFiltre[i] * myFIR->firBuffer[i].acr;
		tempAbsorb.acir += myFIR->coefFiltre[i] * myFIR->firBuffer[i].acir;
	}

	return tempAbsorb;
}

void finFir(param_fir *myFIR)
{
	// free all
	free(myFIR->firBuffer);
	free(myFIR);
	return;
}