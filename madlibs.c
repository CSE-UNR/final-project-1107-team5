//Liam Jones, Pete Andre, Steven Juan
//12-10-24
//CS135 Final Project Madlibs

#include <stdio.h>

#define FILENAME "madlib2.txt"
#define MAXLINE 100
#define MAXMADLIB 250

void adj(char file[MAXMADLIB][MAXLINE], int ind);
void noun(char file[MAXMADLIB][MAXLINE], int ind);
void verb(char file[MAXMADLIB][MAXLINE], int ind);
void replace(char file[MAXMADLIB][MAXLINE], int length);
void readfile(FILE *fp, char file[MAXMADLIB][MAXLINE], int* length);
void print(char file[MAXMADLIB][MAXLINE], int length);
int punctuation(char c);

int main(){
	
	int i, l = 0;
	char ch = '0', file[MAXMADLIB][MAXLINE];
	FILE *mad;
	mad = fopen(FILENAME, "r");
	if(mad == NULL){
		printf("Error Opening File");
		return 0;
	}
	
	readfile(mad, file, &l);
	replace(file, l);
	printf("\nYour madlib:\n\n");
	print(file, l);
	printf("\n");
	fclose(mad);
	return 0;
}

	
void readfile(FILE *fp, char file[MAXMADLIB][MAXLINE], int* length){
	
	while(fgets(file[*length], MAXLINE, fp)){
		*length += 1;
	}
}
		
void replace(char file[MAXMADLIB][MAXLINE], int length){

	int i, n;
	for(i = 0; i < length-1; i++){
		if(file[i][0] == 'A' && file[i][1] == '\n'){
			adj(file, i);
		}else if(file[i][0] == 'N' && file[i][1] == '\n'){
			noun(file, i);
		}else if(file[i][0] == 'V' && file[i][1] == '\n'){
			verb(file, i);
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
	
void adj(char file[MAXMADLIB][MAXLINE], int ind){
	
	printf("Enter an adjective: ");
	fgets(file[ind], MAXLINE, stdin);
	
}
	
void noun(char file[MAXMADLIB][MAXLINE], int ind){
	
	printf("Enter a noun: ");
	fgets(file[ind], MAXLINE, stdin);
	
}

void verb(char file[MAXMADLIB][MAXLINE], int ind){
	
	printf("Enter a verb: ");
	fgets(file[ind], MAXLINE, stdin);
	
}
	
void print(char file[MAXMADLIB][MAXLINE], int length){
	
	int i, n;
	
	for(i = 0; i < length-1; i++){
		for(n = 0; n < MAXMADLIB; n++){
			if(file[i][n] == '\n'){
				file[i][n] = '\0';
			}
		}
		if(punctuation(file[i+1][0]) == 0){
			printf("%s", file[i]);
		}else{
			printf("%s ", file[i]);
		}
	}
}
	
				
	
