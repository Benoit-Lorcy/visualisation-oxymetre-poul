#include <stdio.h>
#include <stdlib.h>

#include "lecture.h"

int main()
{
    printf("Yolo!\n");

    return EXIT_SUCCESS;
}

void test_UART()
{
    void *handler = init_UART();
    int state;

    int count = 0;
    while (++count < 50)
    {
        absorp data = read_UART(handler, &state);

        if (state == EOF)
        {
            printf("EOF!\n");
            break;
        }
        printf("Struct : %f %f %f %f\n", data.acr, data.dcr, data.acir, data.dcir);
    }
}