#include "gauss.h"
#include <math.h>
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){


    int n = mat->r;
    int u;
    double max = 0;
    double pom;

    for (int i = 0; i < n; i++) {

        for(int k = n-1; k >= i; k--) {
            if(fabs(mat -> data[k][i]) > fabs(max)) {
                max = mat -> data[l][i];
                u = l;
            }
        }

        for(int j = 0; j < n; j++) {
            pom = mat->data[i][j];
            mat->data[i][j] = mat->data[u][j];
            mat->data[u][j] = pom;
        }

        pom = b->data[i][0];
        b->data[i][0] = b->data[u][0];
        b->data[u][0] = pom;

        for (int j = i + 1; j < n; j++) {
            double factor = mat->data[j][i] / mat->data[i][i];


            for (int k = i; k < n; k++) {
                mat->data[j][k] -= factor * mat->data[i][k];
            }
            b->data[j][0] -= factor * b->data[i][0];
        }
    }
    return 0;
}

