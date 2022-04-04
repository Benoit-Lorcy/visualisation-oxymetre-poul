#include "mesure.h"

#include "fichiers.h"

oxy mesureTest(char* filename){
	oxy myOxy;

	FILE* f = initFichier(filename);

	oxy un, deux;

	float r_max = 0, r_min = 0;
	float ir_max = 0, ir_min = 0;


	int state = 1;
	do {
		absorp data = lireFichier(f, &state);

		if(data.acr > r_max) r_max = data.acr;
		if(data.acir > ir_max) r_max = data.acir;
		if(data.acr < r_min) r_min = data.acr;
		if(data.acir < ir_min) ir_min = data.acir;
	} while(state != EOF);

	printf("Yo2 : %f, %f\n", r_max, r_min);

	return myOxy;

}

