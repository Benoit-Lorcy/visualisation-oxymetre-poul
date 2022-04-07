#ifndef DEFINE_H
#define DEFINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @struct absorp
 *
 * @brief absorption values for red light and infrared light
 */
typedef struct {
    float acr;  /*!< AC R */
    float dcr;  /*!< DC R */
    float acir; /*!< AC IR */
    float dcir; /*!< DC IR */
} absorp;

/**
 * @struct absorp
 *
 * @brief Oui
 */
typedef struct {
    int spo2;  /*!< SPO2 */
    int pouls; /*!< Pouls */
} oxy;

#endif  // DEFINE_H