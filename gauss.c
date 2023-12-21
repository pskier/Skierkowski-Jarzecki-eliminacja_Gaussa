//łukasz jarzęcki
#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    

	//sprawdzenie osobliwosci
	for (int i = 0; i < mat->c; i++)
	{
		if (mat->data[i][i] == 0)
			return 1;
	}


	//eliminacja
	for (int i = 0; i < mat->c-1; i++)
	{
		for (int j = i+1; j < mat->r; j++) 
		{
			double m = mat->data[j][i]/ mat->data[i][i];
			for (int h = 0; h < mat->c; h++)
			{
				mat->data[j][h] -= m * mat->data[i][h];
			}
			b->data[j][0] -= m * b->data[i][0];

		}
	}
		return 0;
}

