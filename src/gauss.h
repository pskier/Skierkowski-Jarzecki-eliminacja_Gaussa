#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"
#include<math.h>

/**
 * Zwraca 0 - zamiana zakonczona sukcesem
 * Zwraca 1 - zamiana nie byla potrzebna
 */
int swap(int c, Matrix* mat, Matrix* b);

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b);

#endif
