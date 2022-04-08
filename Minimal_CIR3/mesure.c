#include "mesure.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "fichiers.h"

// Value to be above or under to qualify to be able to be a new 0
#define VALUE_TO_CLEAR 10

oxy mesureTest(char *filename)
{
	oxy myOxy;

	FILE *f = initFichier(filename);

	int file_state = 1;

	MesureEnv *env = mesure_init();
	do
	{
		absorp data = lireFichier(f, &file_state);
		mesure(env, data);
	} while (file_state != EOF);

	return env->current;
}

MesureEnv *mesure_init()
{
	MesureEnv *env = malloc(sizeof(MesureEnv));

	if (env == NULL)
	{
		// SAD :(
		return NULL;
	}

	// We could use calloc instead of doing it in 2 steps, but 2 > 1
	memset(env, 0, sizeof(MesureEnv));
	env->can_be_zero = 1;

	// Valeurs par defaut correspondent qa 70 BPM et 85% Sp02
	int i = 0;
	for (; i < 8; i++)
	{
		env->BPM[i] = 70;
		env->RsIR[i] = 1;
	}
	env->current.pouls = 70;
	env->current.spo2 = 85;

	return env;
}

oxy mesure(MesureEnv *env, absorp data)
{
	env->counter++;

	// Etat 0 : Mise en place de la variable previous, 1 : Recherche du premier 0, 2 : Recherche du prochain 0, etat final
	switch (env->mesure_state)
	{
	case 0:
		env->mesure_state = 1;
		break;
	case 1:
		if ((env->previous.acr > 0 && data.acr <= 0) || (env->previous.acr < 0 && data.acr >= 0))
		{
			env->mesure_state = 2;
			env->counter = 0;
			env->zero_count = 1;
			env->can_be_zero = 0;
		}
		break;
	case 2:
		// ACR passent a nouveau par 0
		if (env->can_be_zero && (((env->previous.acr > 0 && data.acr <= 0) || (env->previous.acr < 0 && data.acr >= 0))))
		{
			env->zero_count++;
			env->can_be_zero = 0; // Variable permet de prendre en compte que ACR peut etre instable -> empeche le comptage de plusieurs 0 au lieu de juste 1

			if (env->zero_count == 3)
			{
				// Full period
				env->BPM[env->BPM_index] = 30000.0f / env->counter;
				env->RsIR[env->BPM_index] = env->ir_dc_average * (env->r_maximum - env->r_minimum) / (env->r_dc_average * (env->ir_maximum - env->ir_minimum));
				env->BPM_index = (env->BPM_index + 1) % 8;

				env->zero_count = 1;
				env->r_dc_average = data.dcr;
				env->ir_dc_average = data.dcir;
				env->r_maximum = env->r_minimum = env->ir_maximum = env->ir_minimum = 0;
				env->counter = 1;

				env->current.pouls = (env->BPM[0] + env->BPM[1] + env->BPM[2] + env->BPM[3] + env->BPM[4] + env->BPM[5] + env->BPM[6] + env->BPM[7]) / 8.0f;
				float ratio = (env->RsIR[0] + env->RsIR[1] + env->RsIR[2] + env->RsIR[3] + env->RsIR[4] + env->RsIR[5] + env->RsIR[6] + env->RsIR[7]) / 8.0f;

				if (ratio > 1)
				{
					env->current.spo2 = (int)((3.4f - ratio) * 50.0f / (3.4f - 2));
				}
				else
				{
					env->current.spo2 = (int)((0.8f - ratio) * 10.0f / (0.8f - 0.4f) + 90);
				}
			}
		}

		// Si ACR depasse une certaine valeur, l'instabilite de ACR ne permet plus d'etre detecte comme un faux 0
		if (data.acr > VALUE_TO_CLEAR || data.acr < VALUE_TO_CLEAR)
		{
			env->can_be_zero = 1;
		}

		// Record the maximum and minimum of ACR and ACIR during the period
		if (data.acr > env->r_maximum)
		{
			env->r_maximum = data.acr;
		}
		else if (data.acr < env->r_minimum)
		{
			env->r_minimum = data.acr;
		}
		if (data.acir > env->ir_maximum)
		{
			env->ir_maximum = data.acir;
		}
		else if (data.acir < env->ir_minimum)
		{
			env->ir_minimum = data.acir;
		}

		// Take a value of DC
		env->r_dc_average = (env->r_dc_average + data.dcr) / 2.0f;
		env->ir_dc_average = (env->ir_dc_average + data.dcir) / 2.0f;
		break;

	default:
		break;
	}
	env->previous = data;

	return env->current;
}

void mesure_close(MesureEnv *env)
{
	free(env);
}