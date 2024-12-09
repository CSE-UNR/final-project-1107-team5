//Liam Jones, Pete Andre, Steven Juan
//12-10-24
//CS135 Final Project Madlibs

#include <stdio.h>

#define FILENAME "madlib2.txt"
#define MAXLINE 100
#define MAXMADLIB 50

void prompt(FILE *fp, char resp[MAXMADLIB][MAXLINE], int ind);
void copy(FILE *fp);
void replace(FILE *fp, char resp[MAXMADLIB][MAXLINE], int ind);
void endcopy(FILE *fp);
void readfile(FILE *fp, char file[MAXMADLIB][MAXLINE], int* length);
int punctuation(char c);

int main(){
	
	int i, l = 0;
	char ch = '0', file[MAXMADLIB][MAXLINE], responses[1][1];
	FILE *mad;
	mad = fopen(FILENAME, "r");
	if(mad == NULL){
		printf("Error Opening File");
		return 0;
	}
	
	readfile(mad, file, &l);
	printf("%d\n", &l);
	for(i = 0; i < l-1; i++){
		printf("%s", file[i]);
	}
	return 0;
}

void prompt(FILE *fp, char resp[MAXMADLIB][MAXLINE], int ind){

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

void replace(FILE *fp, char resp[MAXMADLIB][MAXLINE], int ind){

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
	
void readfile(FILE *fp, char file[MAXMADLIB][MAXLINE], int* length){

	int i;
	for(i = 0; (fgets(file[i], MAXLINE, fp)); i++){
	}
	*length = i + 1;
}
			
int punctuation(char c){
	
	if(c == ',' || c == '.' || c == '?' || c == ';' || c == ':' || c == '"' || c == '-' || c == '}' || c == ']' || c == ')' || c == '!'){
		return(0);
	}else{
		return(1);
	}
}
	
	
				
	
