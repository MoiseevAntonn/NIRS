#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Funct.h"

void main(void){

	int l1 , l2 ;
	int *a;
	while (1){
		scanf("%d", &l1);
		scanf("%d", &l2);
		srand(time(NULL));
		a = (int*)malloc(l1*l2*sizeof(int));
		for (int i = 0; i < l2; i++){
			for (int j = 0; j < l1; j++){
				*(a + i*l1 + j) = rand() % 10;
			}
		}

		printArr(a, l1, l2);

		inplace(a, l1, l2);

		printArr(a, l2, l1);
	}

	scanf("\n");

}

