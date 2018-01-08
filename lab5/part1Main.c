#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[]){

	int ch,popped,next;

  	while ((ch = getchar()) != EOF) {
    		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')){
      			continue;
    		}else if(ch=='<'){
			next=getchar();
			if(isalpha(next)){
				push(next);
			}else if(next=='/'){
				next=getchar();
				popped=pop();
				if(popped!=next){
					printf("\nNOT Valid\n");
					exit(1);
				}
			}
		}
   	}
	
	if(isEmpty()==1){
		printf("\nValid\n");
		exit(0);	
	}else{
		printf("\nNOT Valid\n");
		exit(1);
	}
		
  	exit(0);
}
