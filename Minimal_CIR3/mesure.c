#include "mesure.h"

#include <math.h>

#include "fichiers.h"

// Value to be above or under to qualify to be able to be a new 0
#define VALUE_TO_CLEAR 10

oxy mesureTest(char *filename)
{
	oxy myOxy;

	FILE *f = initFichier(filename);

	oxy current;
	int file_state = 1;

	// State variables

	char state = 0; // 0 : first value, 1 : Search for first 0, 2 : Continue search for zeroes

	float zero_count = 0;
	char can_be_zero = 1;

	float r_maximum, r_minimum;
	float ir_maximum, ir_minimum;
	float r_dc_average = 0;
	float ir_dc_average = 0;

	long counter = 0;

	absorp previous;

	float BPM[8] = {70, 70, 70, 70, 70, 70, 70, 70};
	float RsIR[8] = {1,1,1,1,1,1,1,1};
	int BPM_index = 0;

	do
	{
		absorp data = lireFichier(f, &file_state);
		counter++;

		switch (state)
		{
		case 0:
			state = 1;
			break;
		case 1:
			if ((previous.acr > 0 && data.acr <= 0) || (previous.acr < 0 && data.acr >= 0))
			{
				state = 2;
				counter = 0;
				zero_count = 1;
				can_be_zero = 0;
			}
			break;
		case 2:
			if (can_be_zero && (((previous.acr > 0 && data.acr <= 0) || (previous.acr < 0 && data.acr >= 0))))
			{
				zero_count++;
				can_be_zero = 0;

				if (zero_count == 3)
				{
					// Full period
					BPM[BPM_index] = 30000.0f / counter;
					RsIR[BPM_index] = ir_dc_average * (r_maximum - r_minimum) / (r_dc_average * (ir_maximum - ir_minimum));
					BPM_index = (BPM_index + 1) % 8;

					zero_count = 1;
					r_dc_average = data.dcr;
					ir_dc_average = data.dcir;
					r_maximum = r_minimum = ir_maximum = ir_minimum = 0;
					counter = 1;
				}
			}

			if (data.acr > VALUE_TO_CLEAR || data.acr < VALUE_TO_CLEAR)
			{
				can_be_zero = 1;
			}
			if (data.acr > r_maximum)
				r_maximum = data.acr;
			else if (data.acr < r_minimum)
				r_minimum = data.acr;
			if (data.acir > ir_maximum)
				ir_maximum = data.acir;
			else if (data.acir < ir_minimum)
				ir_minimum = data.acir;

			r_dc_average = (r_dc_average + data.dcr) / 2.0f;
			ir_dc_average = (ir_dc_average + data.dcir) / 2.0f;
			break;

		default:
			break;
		}
		previous = data;
	} while (file_state != EOF);

	myOxy.pouls = (BPM[0] + BPM[1] + BPM[2] + BPM[3] + BPM[4] + BPM[5] + BPM[6] + BPM[7]) / 8.0f;
	float ratio = (RsIR[0] + RsIR[1] + RsIR[2] + RsIR[3] + RsIR[4] + RsIR[5] + RsIR[6] + RsIR[7]) / 8.0f;

	if(ratio > 1) {
		myOxy.spo2 = (int) ((3.4f - ratio) * 50.0f / (3.4f - 2));
	} else {
		myOxy.spo2 = (int) ((0.8f - ratio) * 10.0f / (0.8f - 0.4f) + 90);
	}

	return myOxy;
}