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
	ftStatus;
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
	char *data_ptr;
	DWORD bytes_read;

	FT_Read(handle, data, 21, &bytes_read);

	if (bytes_read != 21)
	{
		// Error, sad face :(
		*file_state = EOF;
		return myAbsorp;
	}

	data_ptr = data;
	short decode = (data_ptr[0] - '0') * 1000 + (data_ptr[1] - '0') * 100 + (data_ptr[2] - '0') * 10 + (data_ptr[3] - '0');
	myAbsorp.acr = (float)decode;
	data_ptr += 5;

	decode = (data_ptr[0] - '0') * 1000 + (data_ptr[1] - '0') * 100 + (data_ptr[2] - '0') * 10 + (data_ptr[3] - '0');
	myAbsorp.dcr = (float)decode;
	data_ptr += 5;

	decode = (data_ptr[0] - '0') * 1000 + (data_ptr[1] - '0') * 100 + (data_ptr[2] - '0') * 10 + (data_ptr[3] - '0');
	myAbsorp.acir = (float)decode;
	data_ptr += 5;

	decode = (data_ptr[0] - '0') * 1000 + (data_ptr[1] - '0') * 100 + (data_ptr[2] - '0') * 10 + (data_ptr[3] - '0');
	myAbsorp.dcir = (float)decode;
	data_ptr += 5;

	return myAbsorp; // return EOF flag
}
