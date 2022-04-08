#ifndef INT_H
#define INT_H

#include "affichage.h"
#include "define.h"
#include "fichiers.h"
#include "fir.h"
#include "iir.h"
#include "lecture.h"
#include "mesure.h"

/**
 * @brief Use a file as input to run the program
 *
 * @param filename
 */
void integrationTest(char *filename);

/**
 * @brief Use usb as input to run the program
 */
void integrationTestUART();

#endif
