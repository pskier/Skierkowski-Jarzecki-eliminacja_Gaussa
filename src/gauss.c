//łukasz jarzęcki
#include "gauss.h"

/**
 * Zwraca 0 - zamiana zakonczona sukcesem
 * Zwraca 1 - zamiana nie byla potrzebna
 */
int swap(int c, Matrix* mat, Matrix* b)
{
	int maxRow = c;
	//znalezienie max wartosci bezwzgl w danej kolumnie
	for (int i = c+1; i < mat->r; i++)
	{
		if (fabs(mat->data[i][c]) > fabs(mat->data[maxRow][c]))
			maxRow = i;
	}
	//jezeli nie znaleziono wiekszej wartosci od tej na przekatnej
	if (maxRow == c)
		return 1;

	//zamiana wartosci w wektorze b
	double temp;
	temp = b->data[c][0];
	b->data[c][0] = b->data[maxRow][0];
	b->data[maxRow][0] = temp;

	//zamiana wartosci w macierzy a
	for (int i = 0; i < mat->c; i++)
	{
		temp = mat->data[c][i];
		mat->data[c][i] = mat->data[maxRow][i];
		mat->data[maxRow][i] = temp;
	}
	return 0;
}

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix* mat, Matrix* b) {


	


	//eliminacja
	for (int i = 0; i < mat->c - 1; i++)
	{
		int er = swap(i, mat, b);
		for (int j = i + 1; j < mat->r; j++)
		{
			if (mat->data[i][i] == 0)
				return 1;
			double m = mat->data[j][i] / mat->data[i][i];
			for (int h = 0; h < mat->c; h++)
			{
				mat->data[j][h] -= m * mat->data[i][h];
			}
			b->data[j][0] -= m * b->data[i][0];

		}
	}
	return 0;
}