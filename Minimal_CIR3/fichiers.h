#ifndef FICHIERS_H
#define FICHIERS_H
#include <stdio.h>
#include <stdlib.h>

#include "define.h"

/**
 * @brief
 *
 * @param nomFichier
 * @return FILE*
 */
FILE* initFichier(char* nomFichier);

/**
 * @brief
 *
 * @param pf
 * @param etat
 * @return absorp
 */
absorp lireFichier(FILE* pf, int* etat);

/**
 * @brief
 *
 * @param pf
 */
void finFichier(FILE* pf);
#endif
