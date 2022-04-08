#include <stdio.h>
#include <stdlib.h>

#include "fichiers.h"
#include "fir.h"
#include "iir.h"
#include "integration.h"
#include "lecture.h"
#include "mesure.h"

int main(int argc, char **argv) {
    // If no arguments, leave program with failure code
    if (argc < 2) {
        printf(
            "Not enought arguments\nTry reading README for more "
            "information.\n");
        return EXIT_FAILURE;
    }

    // We use the argument to start the program to read file or to read usb
    // strcmp return 0 if there is no difference between 2 strings
    if (strcmp("-file", argv[1]) == 0) {
        // If no path, leave program with failure code
        if (argc < 3) {
            printf("Please enter a path\n");
            return EXIT_FAILURE;
        }
        printf("Executing file!\n");
        integrationTest(argv[2]);
    } else if (strcmp("-usb", argv[1]) == 0) {
        printf("Warning : this will only work when compiled on windows\n");
        integrationTestUART();
    } else {
        printf("Illegal argument\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}