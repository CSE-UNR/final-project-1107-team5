//Liam Jones, Pete Andre, Steven Juan
//12-10-24
//CS135 Final Project Madlibs

#include <stdio.h>

#define FILENAME "madlib2.txt"
#define MAXRESPONSE 100
#define MAXMADLIB 50

void prompt(FILE *fp, char resp[MAXMADLIB][MAXRESPONSE], int ind);
void copy(FILE *fp);
void replace(FILE *fp, char resp[MAXMADLIB][MAXRESPONSE], int ind);
void endcopy(FILE *fp);
void getlength(FILE *fp, int* length);
int punctuation(char c);

int main(){
	
	int i, l = 0;
	char ch = '0', responses[MAXMADLIB][MAXRESPONSE];
	FILE *mad;
	mad = fopen(FILENAME, "r");
	if(mad == NULL){
		printf("Error Opening File");
		return 0;
	}
	 
	getlength(mad, &l);
	mad = fopen(FILENAME, "r");
	i = 1;
	while(i < l){
		if(i % 2 == 0){
			prompt(mad, responses, (i/2 - 1));
		}
		(ch = fgetc(mad));
		if(ch == '\n'){
			i++;
		}
	}
	printf("\nYour Madlib:\n\n");
	mad = fopen(FILENAME, "r");
	for(i = 0; i < (l/2-1); i++){
		copy(mad);
		replace(mad, responses, i);
	}
	endcopy(mad);
	fclose(mad);
	
	return 0;
}

void prompt(FILE *fp, char resp[MAXMADLIB][MAXRESPONSE], int ind){

	char type;
	type = fgetc(fp);
	if(type == 'A'){
		printf("Please enter an adjective: ");
		scanf("%s", &resp[ind]);
	}else if(type == 'N'){
		printf("Please enter a noun: ");
		scanf("%s", &resp[ind]);
	}else if(type == 'V'){
		printf("Please enter a verb: ");
		scanf("%s", &resp[ind]);
	}else{
		printf("Error: Invalid Madlib Identifier");
	}
}

void copy(FILE *fp){
	
	char c;
	while((c = fgetc(fp)) != '\n'){
		printf("%c", c);
	}
}

void replace(FILE *fp, char resp[MAXMADLIB][MAXRESPONSE], int ind){

	char hold;
	printf(" %s", &resp[ind]);
	fgetc(fp);
	fgetc(fp);
	hold = fgetc(fp);
	if(punctuation(hold) == 0){
		printf("%c", hold);
	}else{
		printf(" %c", hold);
	}
}

void endcopy(FILE *fp){
	
	char c;
	while((c = fgetc(fp)) != '\n'){
		printf("%c", c);
	}
	printf("\n\n");
}
	
void getlength(FILE *fp, int* length){

	char c;	
	while((c = fgetc(fp)) != EOF){
		if(c == '\n'){
			*length += 1;
		}
	}
}
			
int punctuation(char c){
	
	if(c == ',' || c == '.' || c == '?' || c == ';' || c == ':' || c == '"' || c == '-' || c == '}' || c == ']' || c == ')' || c == '!'){
		return(0);
	}else{
		return(1);
	}
}
	
	
				
	
