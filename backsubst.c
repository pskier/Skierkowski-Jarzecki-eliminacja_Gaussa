//Paweł Skierkowski
#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int a = mat->r -1;
	int b=mat->c-1;

	if(a!=b)
		return 2;//zwraca 2 dla nieodpowiedniego rozmiaru macierzy
	

	int i;
	for (i =0; i < x->r; i++) {
		x->data[i][0] = b->data[i][0];
	}

return 0;
}


