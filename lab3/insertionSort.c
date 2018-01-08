#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last){
	int i,j;
	for(i=1;i<=last;i++){
		j=1;
		while(j<=i && myCompare(array[i-j+1],array[i-j])<0){
			mySwap(&array[i-j+1],&array[i-j]);
			j++;						
		}	
	}
}
