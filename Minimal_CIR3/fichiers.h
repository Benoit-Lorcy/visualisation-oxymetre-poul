#ifndef FICHIERS_H
#define FICHIERS_H
#include <stdio.h>
#include <stdlib.h>

#include "define.h"

/**
 * @brief Initialise file reading
 *
 * @param nomFichier
 * @return FILE*
 */
FILE *initFichier(char *nomFichier);

/**
 * @brief Read current file
 *
 * @param pf
 * @param etat
 * @return absorp
 */
absorp lireFichier(FILE *pf, int *etat);

/**
 * @brief Close file
 *
 * @param pf
 */
void finFichier(FILE *pf);
#endif
