#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "define.h"

/**
 * @brief Writing spo2, pouls to a file. This file is locked during writing with
 * ".verrouData".
 *
 * @param myOxy
 */
void affichage(oxy myOxy);

#endif