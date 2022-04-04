#include "lecture.h"

#include "ftd2xx.h"

void *init_UART()
{
	FT_STATUS ftStatus;
	DWORD numDevs;

	ftStatus = FT_ListDevices(&numDevs, NULL, FT_LIST_NUMBER_ONLY);
	if (ftStatus == FT_OK)
	{
		// FT_ListDevices OK, number of devices connected is in numDevs
	}
	else
	{
		// FT_ListDevices failed
	}

	FT_HANDLE ftHandle;
	FT_STATUS ftStatus;
	ftStatus = FT_Open(0, &ftHandle);
	if (ftStatus == FT_OK)
	{
		return ftHandle;
	}
	else
	{
		return NULL;
	}
}

void close_UART(void *handle)
{
	FT_Close((FT_HANDLE)handle);
}

absorp read_UART(void *handle, int *file_state)
{
	absorp myAbsorp;

	char data[21];
	DWORD bytes_read;

	FT_Read(handle, data, 21, &bytes_read);

	if (bytes_read != 21)
	{
		// Error, sad face :(
		*file_state = EOF;
		return;
	}

	short decode = (data[0] - '0') * 1000 + (data[1] - '0') * 100 + (data[2] - '0') * 10 + (data[3] - '0');
	myAbsorp.acr = (float)decode;
	data += 5;

	decode = (data[0] - '0') * 1000 + (data[1] - '0') * 100 + (data[2] - '0') * 10 + (data[3] - '0');
	myAbsorp.dcr = (float)decode;
	data += 5;

	decode = (data[0] - '0') * 1000 + (data[1] - '0') * 100 + (data[2] - '0') * 10 + (data[3] - '0');
	myAbsorp.acir = (float)decode;
	data += 5;

	decode = (data[0] - '0') * 1000 + (data[1] - '0') * 100 + (data[2] - '0') * 10 + (data[3] - '0');
	myAbsorp.dcir = (float)decode;
	data += 5;

	return myAbsorp; // return EOF flag
}
