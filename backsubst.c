//Paweł Skierkowski
#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int a = mat->r -1;
	int c=mat->c-1;

	if(a!=c)
		return 2;//zwraca 2 dla nieodpowiedniego rozmiaru macierzy
	
	int pom=c;
	double sum=0;
	int i,j;
	for (i =a; i >=0; i--) {
		for(j=c;j>pom;j--){
			sum=(mat->data[i][j])*(x->data[j][0]);
			b->data[i][0]-=sum;
		}
		if(mat->data[i][i]==0){
		return 0;
		}
		x->data[i][0] = b->data[i][0]/mat->data[i][i];
		pom--;
	}
return 0;
}


