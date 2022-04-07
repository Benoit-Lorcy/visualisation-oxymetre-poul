#include <stdio.h>
#include <stdlib.h>

#include "fichiers.h"
#include "fir.h"
#include "iir.h"
#include "integration.h"
#include "lecture.h"
#include "mesure.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf(
            "Not enought arguments\nTry reading README for more "
            "information.\n");
        return EXIT_FAILURE;
    }

    if (strcmp("-file", argv[1]) == 0) {
        if (argc < 3) {
            printf("Please enter a path\n");
            return EXIT_FAILURE;
        }
        integrationTest(argv[2]);
    } else if (strcmp("-usb", argv[1]) == 0) {
        printf("Warning : this will only work when compiled on windows\n");
        integrationTestUART();
    } else {
        printf("illegal argument\n");
    }

    return EXIT_SUCCESS;
}