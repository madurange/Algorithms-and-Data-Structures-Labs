#include "mySort.h"


void merge(int[],int,int,int,int);


void mySort(int array[], unsigned int first, unsigned int last){
    int mid;
        
    if(first<last){
        mid=(first+last)/2;
        mySort(array,first,mid);
        mySort(array,mid+1,last);
        merge(array,first,mid,mid+1,last);
    }
}
 
void merge(int array[],int i1,int j1,int i2,int j2)
{
    int temp[MAX_SIZE_N_TO_SORT];
    int i,j,k;
    i=i1;
    j=i2;
    k=0;
    
    while(i<=j1 && j<=j2){
    	if(myCompare(array[i],array[j])<0){
            	myCopy(&array[i],&temp[k]);
		k++;
		i++;
        }else{
            	myCopy(&array[j],&temp[k]);
		k++;
		j++;
	}
    }
    
    while(i<=j1){
        myCopy(&array[i],&temp[k]);
	k++;
	i++;
    }    
    while(j<=j2){
        myCopy(&array[j],&temp[k]);
	k++;
	j++;
    }    

    for(i=i1,j=0;i<=j2;i++,j++){
        myCopy(&temp[j],&array[i]);
    }
}
