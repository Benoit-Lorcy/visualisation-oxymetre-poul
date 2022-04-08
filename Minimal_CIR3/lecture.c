#include "lecture.h"

absorp lecture(FILE *file_pf, int *file_state)
{
    absorp myAbsorp;

    char data[21];
    char *data_ptr;
    size_t bytes_read;

    bytes_read = fread(data, sizeof(char), 21, file_pf);

    if (bytes_read != 21)
    {
        // Error, sad face :(
        *file_state = EOF;
        return myAbsorp;
    }

    // Check if well formed
    while (!(data[4] == ',' && data[4 + 5] == ',' && data[4 + 5 * 2] == ','))
    {
        int i = 0;
        int first_weird_char = -1;
        // Find the first weird character
        for (i = 0; i < 21; i++)
        {
            if (!((data[i] >= '0' && data[i] <= '9') || data[i] == ','))
            {
                data[i] = '^';
                if(first_weird_char == -1) {
                    first_weird_char = i;
                }
            }
        }
        char data2[21];
        for (i = 0; i < 21; i++)
        {
            data2[i] = '-';
        }
        // Move memory after the weird character to the start of data
        memcpy(data2, data + first_weird_char + 1, 21 - first_weird_char - 1);

        memcpy(data, data2, 21 - first_weird_char - 1);

        // Read data equivalent to the length of the data that a thrown out
        bytes_read = fread(data + (21 - first_weird_char - 1), sizeof(char),
                first_weird_char + 1, file_pf);

        if (bytes_read != first_weird_char + 1)
        {
            // Error, sad face :(
            *file_state = EOF;
            return myAbsorp;
        }
    }

    // 1234 => 1 * 1000 + 2 * 100 + 3 * 10 + 4 * 1
    data_ptr = data;
    short decode = (data_ptr[0] - '0') * 1000 + (data_ptr[1] - '0') * 100 +
                   (data_ptr[2] - '0') * 10 + (data_ptr[3] - '0');
    myAbsorp.acr = (float)decode - 2048;
    data_ptr += 5;

    decode = (data_ptr[0] - '0') * 1000 + (data_ptr[1] - '0') * 100 +
             (data_ptr[2] - '0') * 10 + (data_ptr[3] - '0');
    myAbsorp.dcr = (float)decode;
    data_ptr += 5;

    decode = (data_ptr[0] - '0') * 1000 + (data_ptr[1] - '0') * 100 +
             (data_ptr[2] - '0') * 10 + (data_ptr[3] - '0');
    myAbsorp.acir = (float)decode - 2048;
    data_ptr += 5;

    decode = (data_ptr[0] - '0') * 1000 + (data_ptr[1] - '0') * 100 +
             (data_ptr[2] - '0') * 10 + (data_ptr[3] - '0');
    myAbsorp.dcir = (float)decode;

    return myAbsorp;
}

/**
 *
 */
#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) || defined(__CYGWIN__)

#define _WIN32

#include <Windows.h> // comes first

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

void close_UART(void *handle) { FT_Close((FT_HANDLE)handle); }

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

    // Check if well formed
    while (!(data[4] == ',' && data[4 + 5] == ',' && data[4 + 5 * 2] == ','))
    {
        int i = 0;
        int first_weird_char = -1;
        for (i = 0; i < 21; i++)
        {
            if (!((data[i] >= '0' && data[i] <= '9') || data[i] == ','))
            {
                data[i] = '^';
                if(first_weird_char == -1) {
                    first_weird_char = i;
                }
            }
        }
        char data2[21];
        for (i = 0; i < 21; i++)
        {
            data2[i] = '-';
        }
        memcpy(data2, data + first_weird_char + 1, 21 - first_weird_char - 1);

        memcpy(data, data2, 21 - first_weird_char - 1);
        FT_Read(handle, data + (21 - first_weird_char - 1),
                first_weird_char + 1, &bytes_read);

        if (bytes_read != first_weird_char + 1)
        {
            // Error, sad face :(
            *file_state = EOF;
            return myAbsorp;
        }
    }

    data_ptr = data;
    short decode = (data_ptr[0] - '0') * 1000 + (data_ptr[1] - '0') * 100 +
                   (data_ptr[2] - '0') * 10 + (data_ptr[3] - '0');
    myAbsorp.acr = (float)decode - 2048;
    data_ptr += 5;

    decode = (data_ptr[0] - '0') * 1000 + (data_ptr[1] - '0') * 100 +
             (data_ptr[2] - '0') * 10 + (data_ptr[3] - '0');
    myAbsorp.dcr = (float)decode;
    data_ptr += 5;

    decode = (data_ptr[0] - '0') * 1000 + (data_ptr[1] - '0') * 100 +
             (data_ptr[2] - '0') * 10 + (data_ptr[3] - '0');
    myAbsorp.acir = (float)decode - 2048;
    data_ptr += 5;

    decode = (data_ptr[0] - '0') * 1000 + (data_ptr[1] - '0') * 100 +
             (data_ptr[2] - '0') * 10 + (data_ptr[3] - '0');
    myAbsorp.dcir = (float)decode;

    return myAbsorp; // return EOF flag
}

#else

void *init_UART() {}
void close_UART(void *handle) {}
absorp read_UART(void *handle, int *file_state) {}

#endif