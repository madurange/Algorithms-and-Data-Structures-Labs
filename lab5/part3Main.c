#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern char *  pop();
extern void push(char *);
extern void init();
extern void add(char *,int);
extern int isEmpty();
extern void printResults();

int main(int argc, char * argv[]){
	
	int ch,next,i;
	char temp[100],temp2[100];
	char* str;
	
	init();
		
	
	while ((ch = getchar()) != EOF) {
   		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')){
      			continue;
		}else if(ch=='<'){
			next=getchar();
			if(isalpha(next)||isdigit(next)){
				i=0;
				do{					
					temp[i]=next;
					i++;
				}while((next=getchar())!='>');
				temp[i]=0;			
				
				str=(char*)malloc(i*sizeof(char));
				strcpy(str,temp);			
				push(str);
				add(str,i);
			}else if(next=='/'){
				next=getchar();
				if(isalpha(next) || isdigit(next)){
					i=0;
					do{					
						temp[i]=(char)next;
						i++;
					}while((next=getchar())!='>');
					temp[i]=0;
					if(isEmpty()==1){
						pop();
						exit(1);
					}else{
						strcpy(temp2,pop());
						if(strcmp(temp,temp2)!=0){
							printf("\nNOT Valid\n");
							exit(1);
						}
					}	
				
				}
			}	
		}
	
	}
	
	if(isEmpty()==1){
		printf("\nValid\n");
		printResults();
		exit(0);	
	}else{
		printf("\nNOT Valid\n");
		exit(1);
	}    
    
}
