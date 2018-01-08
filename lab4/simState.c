#include <stdlib.h>
#include <stdio.h>

#define MAX_STATES 8

/*Declaration of the new Data Structure which represents states*/
typedef struct state{
	char name;
	struct state *next0;
	struct state *next1;
}state;

void initialize_states();
void print_states();
char next_char(char[],int);
void change_state(state*, char[]);
void reset_garbage();
void garbage_identify(state*);
void print_garbage();
void delete_states(state*, char[]);

/*Declaration of Needed Arrays and Pointers */
state fsm[MAX_STATES];
char garbage[MAX_STATES];
char deleted[MAX_STATES]={'0','0','0','0','0','0','0','0'};
state *current_state;
char user[19];

int main(int argc, char * argv[]){
	if (argc > 1) {
        	fprintf(stderr,"Invaid Argument Used");
		exit(1);
	}
	
	/*Initializing States*/
	initialize_states();

	/*Setting the starting state to A */
	current_state=&fsm[0];

	/* Printing the staring state */
	printf("%c\n",(*current_state).name);

	/*Operations of the state machine using user commands*/
	while(fgets(user,20,stdin)){
		switch(next_char(user,0)){
			case '1':
				current_state=(*current_state).next1;
				printf("%c\n",(*current_state).name);
				break;
			case '0':
				current_state=(*current_state).next0;
				printf("%c\n",(*current_state).name);
				break;
			case 'c':
			case 'C':
				change_state(current_state,user);
				break;
			case 'p':
			case 'P':
				print_states();
				break;
			case 'g':
			case 'G':
				reset_garbage();
 				garbage_identify(current_state);
				print_garbage();
				break;
			case 'd':
			case 'D':
				delete_states(current_state,user);
				break;	
			default :
				fprintf(stderr,"Invaild Command Used\n");	
		}
	
	} 

	exit(0);
}

void initialize_states(){

	int i;
	char buf[6];
	FILE *input;
	input=fopen("myStates.txt","r");
	for(i=0;i<MAX_STATES;i++){
		fgets(buf,7,input);
		fsm[i].name=buf[0];
		fsm[i].next0=&(fsm[((int)(buf[2]))-65]);
		fsm[i].next1=&(fsm[((int)(buf[4]))-65]);
	}
	fclose(input);
}

void print_states(){

	int i;
	for(i=0;i<MAX_STATES;i++){
		if(deleted[i]=='0'){
			printf("%c %c %c\n",fsm[i].name,(*(fsm[i].next0)).name,(*(fsm[i].next1)).name);
		}
	}

}

char next_char(char user[],int position){
	int space_count=0,i=0;
	while(i<19){
		if(space_count==position){
			return user[i];
		}
		i++;
		while(i<19 && user[i]==' '){
			i++;
		}
		space_count++;
	}
	return 'x';
}

void change_state(state* current_state , char user[]){
	char input2=next_char(user,1);
	char input3=next_char(user,2);
	if((int)(input3)<65 || (int)(input3)>72){
		fprintf(stderr,"Invaild Command Used\n");
		return;
	}
	switch(input2){
		case '0':
			if(deleted[(int)(input3)-65]=='0'){
				(*current_state).next0=&(fsm[((int)(input3))-65]);
	
			}else{
				fprintf(stderr,"Invaild Command Used - Indicated State is Deleted\n");
				break;
			}	
			break;
		case '1':
			if(deleted[(int)(input3)-65]=='0'){
				(*current_state).next1=&(fsm[((int)(input3))-65]);
			}else{
				fprintf(stderr,"Invaild Command Used - Indicated State is Deleted\n");
				return;
			}
			break;
		default:
			fprintf(stderr,"Invaild Command Used\n");
	}
}

void reset_garbage(){
	int i;
	for(i=0;i<MAX_STATES;i++){
		garbage[i]=(char)(i+65);
	}
}

void garbage_identify(state* current_state){
	state *next;
	next=current_state;

	next=(*next).next0;
	garbage[(int)((*current_state).name)-65]='0';
	if(garbage[(int)((*next).name)-65]!='0'){
		garbage_identify(next);	
	}
	next=(*next).next1;
	garbage[(int)((*current_state).name)-65]='0';
	if(garbage[(int)((*next).name)-65]!='0'){
		garbage_identify(next);	
	}
}

void print_garbage(){
	int i,j;
	int isGarbage=0;
	char temp[MAX_STATES];
	for(i=0,j=0;i<MAX_STATES;i++){
		if(garbage[i]!='0'){
			isGarbage=1;
			temp[j]=garbage[i];
			j++;		
		}
	}
	if(isGarbage==1){
		printf("Garbage: ");
		for(i=0;i<j;i++){
			printf("%c ",temp[i]);
		}
		printf("\b\n");
	}else{
		printf("No Garbage\n");
	}
}

void delete_states(state *current_state, char user[]){
	char argument=next_char(user,1);
	int i,j;
	int isDeleted=1;
	int isGarbage=0;
	char temp[MAX_STATES];
	
	reset_garbage();
	garbage_identify(current_state);
	if(argument == '\n'){
		for(i=0,j=0;i<MAX_STATES;i++){			
			if(garbage[i]!='0'){
				isGarbage=1;
				if(deleted[i]=='0'){
					isDeleted=0;
					deleted[i]=garbage[i];
					temp[j]=garbage[i];
					j++;
				}
						
			}
		}
		if(isGarbage==0){
			printf("No States Deleted\n");
		}else if(isDeleted==1){
			printf("No States Deleted\n");
		}else{
			printf("Deleted: ");
			for(i=0;i<j;i++){
				printf("%c ",temp[i]);
			}
			printf("\n");
		}
	}else{
		char input2=next_char(user,1);
		if((int)(input2)<65 || (int)(input2)>72){
			fprintf(stderr,"Invaild Command Used\n");
			return;
		}
		if(garbage[(int)(input2)-65]==input2 && deleted[(int)(input2)-65]=='0'){
			deleted[(int)(input2)-65]=input2;
			printf("Deleted\n");
		}else{
			printf("Not Deleted\n");
		}
	}
}















