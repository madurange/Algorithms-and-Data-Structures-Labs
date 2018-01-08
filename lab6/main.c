#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern void addHeap(int);
extern void printHeap(int);
extern void buildMaxHeap();
extern int isEmpty();
extern int heapSize();
extern int heapDelete();

int main(int argc, char * argv[]){
	int value,temp;
	while (scanf("%d", &value) != EOF) {
   		fprintf(stderr, "READING INPUT: %d\n", value);
    		addHeap(value);
  	}
	buildMaxHeap();
	printHeap(1);
	printf("\n");
	printf("\nThe Sorted Numbers(Descending):\n");
	while(heapSize()>1){
		temp=heapDelete();
		printf("%d\n",temp);
		push(temp);
	}
	printf("The Sorted Numbers(Ascending):\n");
	while(isEmpty()!=1){
		printf("%d\n",pop());
	}
	printf("\n");
  	exit(0);
}
