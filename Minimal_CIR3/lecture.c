#include "lecture.h"

#include <stdio.h>

absorp lecture(FILE *file_pf, int *file_state)
{

	absorp myAbsorp;

	long current_pos = ftell(file_pf);
	fseek(file_pf, 0, SEEK_END);
	long size = ftell(file_pf) - current_pos;

	if(size < 21) {
		*file_state = EOF;
		return;
	}
	if(size < 21 * 2) {
		*file_state = EOF;
	}
	fseek(file_pf, current_pos, SEEK_SET);

	char data[21];

	size_t num_read = fread(data, sizeof(char), 21, file_pf);

	if(num_read != 21) {
		// Error, sad face :(
		*file_state = EOF;
		return;
	}

	short decode = (data[0] - '0') * 1000 + (data[1] - '0') * 100 + (data[2] - '0') * 10 + (data[3] - '0');
	myAbsorp.acr = (float) decode;
	data += 5;

	decode = (data[0] - '0') * 1000 + (data[1] - '0') * 100 + (data[2] - '0') * 10 + (data[3] - '0');
	myAbsorp.dcr = (float) decode;
	data += 5;

	decode = (data[0] - '0') * 1000 + (data[1] - '0') * 100 + (data[2] - '0') * 10 + (data[3] - '0');
	myAbsorp.acir = (float) decode;
	data += 5;

	decode = (data[0] - '0') * 1000 + (data[1] - '0') * 100 + (data[2] - '0') * 10 + (data[3] - '0');
	myAbsorp.dcir = (float) decode;
	data += 5;

	return myAbsorp; // return EOF flag
}
