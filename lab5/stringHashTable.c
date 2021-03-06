#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define HASH_TABLE_SIZE 1057

void init();
void add(char*,int);
void printResults();

typedef struct Entry Entry, *EntryPtr;
struct Entry {
  char * string;
  int count;
};

Entry hash_table[HASH_TABLE_SIZE];
int i,sum,key;

void init(){
	for(i=0;i<HASH_TABLE_SIZE;i++){
		hash_table[i].count=0;		
	}
}

void add(char* tag,int num){
	sum=0;
	for(i=0;i<num;i++){
		sum+=(int)tag[i];
	}
	key=sum%HASH_TABLE_SIZE;
	if(hash_table[key].string!=NULL){
		if(strcmp(hash_table[key].string,tag)==0){
			hash_table[key].count++;
		}else{
			while(hash_table[key].string!=NULL){
				key++;
				if(hash_table[key].string!=NULL){
					if(strcmp(hash_table[key].string,tag)==0){
						hash_table[key].count++;
						break;
					}
				}
			}
		}
	}
	if(hash_table[key].string==NULL){
		hash_table[key].count++;
		hash_table[key].string=(char*)malloc(num*sizeof(char));
		strcpy(hash_table[key].string,tag);
	}	

}

void printResults(){
	for(i=0;i<HASH_TABLE_SIZE;i++){
		if(hash_table[i].count!=0){
			printf("%s %d\n",hash_table[i].string,hash_table[i].count);
		}		
	}
}


